#include "../params.h"
#include "ntt2x2.h"
#include "ram_util.h"
#include "butterfly_unit.h"
#include "fifo.h"
#include "address_encoder_decoder.h"
#include "util.h"

void ntt2x2_fwdntt(bram *ram, enum OPERATION mode, enum MAPPING mapping)
{
    // Initialize FIFO
    data_t fifo_i[DEPT_W] = {0};
    data_t fifo_a[DEPT_A] = {0};
    data_t fifo_b[DEPT_B] = {0};
    data_t fifo_c[DEPT_C] = {0};
    data_t fifo_d[DEPT_D] = {0};
    data_t fifo_w[DEPT_W][DEPT_W] = {{0}};

    // Initialize Forward NTT
    unsigned fw_ntt_pattern[] = {6, 4, 2, 0, 6};
    unsigned s, last = 0;

    // Initialize twiddle
    unsigned tw_i[4] = {0}, tw_base_i[4] = {0};
    data_t w_in[4], w_out[4];

    // Intialize index
    data_t k, j;

    // Initialize coefficients
    const data_t null[4] = {0};
    data_t data_in[4] = {0},
           data_out[4] = {0},
           data_fifo[4] = {0};

    // Initialize writeback
    unsigned count = 0; // 2-bit counter
    bool write_en = false;

    for (unsigned l = 0; l < FALCON_LOGN; l += 2)
    {
        for (unsigned i = 0; i < BRAM_DEPT; ++i)
        {
            /* ============================================== */

            if (i == 0)
            {
                k = j = 0;
            }

            /* ============================================== */
            // modify here
            unsigned addr = k + j;

            // Prepare address
            unsigned ram_i = resolve_address(mapping, addr);

            // Read ram by address
            // data_in = ram[ram_i];
            read_ram(data_in, ram, ram_i);

            // Write data_in to FIFO, extract output to data_fifo
            // In this mode, new_value[4] = null[4]
            read_write_fifo<data_t>(mode, data_fifo, data_in, null, fifo_a,
                                    fifo_b, fifo_c, fifo_d, count);
            count = (count + 1) & 3;

            // Prepare twiddle
            resolve_twiddle(tw_i, &last, tw_base_i, k, l, mode);

            // Read Twiddle
            read_twiddle(w_in, mode, tw_i);

            /* ============================================== */
            // Rolling FIFO for index of RAM
            unsigned fi = FIFO<DEPT_W>(fifo_i, ram_i);

            // printf("--------------%d - %d <= %d\n", count, ram_i, addr);
            // print_array<unsigned>(tw_i, 4, "twiddle");
            // print_array<data_t>(fifo_i, DEPT_W, "FIFO_I");
            // print_array<data_t>(fifo_a, DEPT_A, "FIFO_A");
            // print_array<data_t>(fifo_b, DEPT_B, "FIFO_B");
            // print_array<data_t>(fifo_c, DEPT_C, "FIFO_C");
            // print_array<data_t>(fifo_d, DEPT_D, "FIFO_D");
            // print_array<data_t>(data_in, 4, "data_in");
            
            /* 
             * PIPO for twiddle factor, delay it by DEPT_W
             */
            PIPO<DEPT_W, data_t>(w_out, fifo_w, w_in);
            /* ============================================== */

            // Calculate
            buttefly_circuit<data2_t, data_t>(data_out, data_fifo, w_out, mode);
            // print_array<data_t>(data_fifo, 4, "i");
            // print_array<data_t>(w_out, 4, "w");
            // print_array<data_t>(data_out, 4, "o");
            // printf("\n");
            
            /* ============================================== */
            // count equal the size of FIFO_I
            if (count == 0 && i != 0)
            {
                write_en = true;
            }

            if (write_en)
            {
                write_ram(ram, fi, data_out);
            }

            /* ============================================== */
            // Update loop
            if (mode == FORWARD_NTT_MODE)
            {
                s = fw_ntt_pattern[l >> 1];
            }
            else
            {
                s = l;
            }

            if (k + (1 << s) < BRAM_DEPT)
            {
                k += (1 << s);
                // printf("k = %d\n", k);
            }
            else
            {
                k = 0;
                ++j;
            }

            update_indexes(tw_i, tw_base_i, l, mode);
        }
        /* ============================================== */
        // print_reshaped_array(ram, BRAM_DEPT, "ram");
    }

    for (unsigned i = 0; i < DEPT_W; i++)
    {
        // Extract left over data in FIFO to data_in
        read_write_fifo<data_t>(mode, data_in, null, null, fifo_a,
                                fifo_b, fifo_c, fifo_d, count);

        // Rolling FIFO
        unsigned fi = FIFO<DEPT_W>(fifo_i, 0);

        // Buffer twiddle
        PIPO<DEPT_W, data_t>(w_out, fifo_w, null);

        buttefly_circuit<data2_t, data_t>(data_out, data_in,
                         w_out, mode);

        // Write back
        write_ram(ram, fi, data_out);
    }
}