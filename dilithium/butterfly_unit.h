#ifndef BUTTERFLY_UNITS_H
#define BUTTERFLY_UNITS_H

#include <stdint.h>

void buttefly_circuit(int32_t *a, int32_t *b,
                      int32_t *c, int32_t *d,
                      const int32_t w_fwd[4],
                      const int32_t w_imul[4],
                      const int mode);

void buttefly_circuit_new(int32_t data_out[4], 
                        const int32_t data_in[4],
                        const int32_t w1, const int32_t w2, 
                        const int32_t w3, const int32_t w4,
                        enum OPERATION mode);

#endif