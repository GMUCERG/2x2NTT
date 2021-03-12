#include <stdio.h>
#include <stdint.h>
#include "params.h"
#include "ntt.h"
#include "util.h"
#include "reduce.h"

#define DEPT_A 4
#define DEPT_B 6
#define DEPT_C 5
#define DEPT_D 7

typedef struct
{
    int32_t coeffs[4];
} line;

typedef struct
{
    line vec[N / 4];
} bram;

static const int32_t zetas[N] = {
    0, 25847, -2608894, -518909, 237124, -777960, -876248, 466468,
    1826347, 2353451, -359251, -2091905, 3119733, -2884855, 3111497, 2680103,
    2725464, 1024112, -1079900, 3585928, -549488, -1119584, 2619752, -2108549,
    -2118186, -3859737, -1399561, -3277672, 1757237, -19422, 4010497, 280005,
    2706023, 95776, 3077325, 3530437, -1661693, -3592148, -2537516, 3915439,
    -3861115, -3043716, 3574422, -2867647, 3539968, -300467, 2348700, -539299,
    -1699267, -1643818, 3505694, -3821735, 3507263, -2140649, -1600420, 3699596,
    811944, 531354, 954230, 3881043, 3900724, -2556880, 2071892, -2797779,
    -3930395, -1528703, -3677745, -3041255, -1452451, 3475950, 2176455, -1585221,
    -1257611, 1939314, -4083598, -1000202, -3190144, -3157330, -3632928, 126922,
    3412210, -983419, 2147896, 2715295, -2967645, -3693493, -411027, -2477047,
    -671102, -1228525, -22981, -1308169, -381987, 1349076, 1852771, -1430430,
    -3343383, 264944, 508951, 3097992, 44288, -1100098, 904516, 3958618,
    -3724342, -8578, 1653064, -3249728, 2389356, -210977, 759969, -1316856,
    189548, -3553272, 3159746, -1851402, -2409325, -177440, 1315589, 1341330,
    1285669, -1584928, -812732, -1439742, -3019102, -3881060, -3628969, 3839961,
    2091667, 3407706, 2316500, 3817976, -3342478, 2244091, -2446433, -3562462,
    266997, 2434439, -1235728, 3513181, -3520352, -3759364, -1197226, -3193378,
    900702, 1859098, 909542, 819034, 495491, -1613174, -43260, -522500,
    -655327, -3122442, 2031748, 3207046, -3556995, -525098, -768622, -3595838,
    342297, 286988, -2437823, 4108315, 3437287, -3342277, 1735879, 203044,
    2842341, 2691481, -2590150, 1265009, 4055324, 1247620, 2486353, 1595974,
    -3767016, 1250494, 2635921, -3548272, -2994039, 1869119, 1903435, -1050970,
    -1333058, 1237275, -3318210, -1430225, -451100, 1312455, 3306115, -1962642,
    -1279661, 1917081, -2546312, -1374803, 1500165, 777191, 2235880, 3406031,
    -542412, -2831860, -1671176, -1846953, -2584293, -3724270, 594136, -3776993,
    -2013608, 2432395, 2454455, -164721, 1957272, 3369112, 185531, -1207385,
    -3183426, 162844, 1616392, 3014001, 810149, 1652634, -3694233, -1799107,
    -3038916, 3523897, 3866901, 269760, 2213111, -975884, 1717735, 472078,
    -426683, 1723600, -1803090, 1910376, -1667432, -1104333, -260646, -3833893,
    -2939036, -2235985, -420899, -2286327, 183443, -976891, 1612842, -3545687,
    -554416, 3919660, -48306, -1362209, 3937738, 1400424, -846154, 1976782};

// This function will output an element when insert 1 element
int32_t FIFO(const int dept, int32_t *fifo, const int32_t new)
{
    int32_t out = fifo[dept - 1];
    for (int i = dept - 1; i > -1; i--)
    {
        fifo[i] = fifo[i - 1];
    }
    fifo[0] = new;

    return out;
}

void print_reshaped_array(bram *ram, int bound, const char *string)
{
    printf("%s :\n", string);
    for (int i = 0; i < bound; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d, ", ram->vec[i].coeffs[j]);
        }
    }
    printf("\n");
}

void swap(int32_t *a, int32_t *b)
{
    int32_t tmp = *a;
    *a = *b;
    *b = tmp;
}

// buttefly unit
void forward_butterfly(int32_t *bj, int32_t *bjlen, const int32_t zeta, int32_t aj, int32_t ajlen)
{
    /* t = montgomery_reduce((int64_t)zeta * a[j + len]);
        a[j + len] = a[j] - t;
        a[j] = a[j] + t; */
    int32_t t;
    printf("i: %d |  %d * %d\n", aj, zeta, ajlen);

    t = montgomery_reduce((int64_t)zeta * ajlen);
    ajlen = aj - t;
    aj = aj + t;
    *bj = aj;
    *bjlen = ajlen;

    printf("o: %d |  %d\n", aj, ajlen);
}

// buttefly unit
void inverse_butterfly(int32_t *bj, int32_t *bjlen, const int32_t zeta, int32_t aj, int32_t ajlen)
{
    /* t = a[j];
        a[j] = t + a[j + len];
        a[j + len] = t - a[j + len];
        a[j + len] = montgomery_reduce((int64_t)zeta * a[j + len]); */
    int32_t t;
    // printf("i: %d |  %d * %d\n", aj, zeta, ajlen);

    t = aj;
    aj = t + ajlen;
    ajlen = t - ajlen;
    ajlen = montgomery_reduce((int64_t)zeta * ajlen);
    *bj = aj;
    *bjlen = ajlen;

    // printf("o: %d |  %d\n", aj, ajlen);
}

// Store 4 coefficients per line
void reshape(bram *ram, int32_t in[N])
{
    for (int i = 0; i < N / 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            ram->vec[i].coeffs[j] = in[4 * i + j];
        }
    }
}

void ntt2x2(bram *ram)
{
    int32_t fifo_a[DEPT_A] = {0},
            fifo_b[DEPT_B] = {0},
            fifo_c[DEPT_C] = {0},
            fifo_d[DEPT_D] = {0};
    int32_t a, b, c, d;
    int32_t fa, fb, fc, fd;

    int count = 0;
    int write = 0;
    int32_t fi, indexes[3] = {0};

    int i1, i2, i3, i4;
    int ram_i;

    i1 = N - 1;
    i2 = N - 2;
    i3 = N / 2 - 1;
    i4 = N / 2 - 1;

    // iterate 2 levels at a time
    for (int s = 1; s < 4; s += 2)
    {
        int m0 = 1 << (s - 1);
        int m1 = 1 << (s);
        int m2 = 1 << (s + 1);

        int w_m1 = 1 << s;
        int w_m2 = 1 << (s - 1);

        for (int j = 0; j < m0; j++)
        {
            for (int k = 0; k < N; k += m2)
            {
                int ram_i = k + j;

                int w1 = -zetas[i1];
                int w2 = -zetas[i2];

                int w3 = -zetas[i3];
                int w4 = -zetas[i4];

                a = ram->vec[ram_i / 4].coeffs[0];
                b = ram->vec[ram_i / 4].coeffs[1];
                c = ram->vec[ram_i / 4].coeffs[2];
                d = ram->vec[ram_i / 4].coeffs[3];

                fi = FIFO(3, indexes, ram_i / 4);

                if ( (ram_i < 32 || ram_i > 224) && (s > 2) )
                {
                    // index
                    printf("%d, %d | %d\n", ram_i, ram_i + 1, i1);
                    printf("%d, %d | %d\n", ram_i + 2, ram_i + 3, i2);
                    // value
                    // printf("%d %d | %d\n", a, b, w1);
                    // printf("%d %d | %d\n", c, d, w2);
                }

                inverse_butterfly(&a, &b, w1, a, b);
                inverse_butterfly(&c, &d, w2, c, d);

                swap(&b, &c);

                if ( (ram_i < 32 || ram_i > 224) && (s > 2) )
                {
                    // index
                    printf("%d, %d | %d\n", ram_i, ram_i + 2, i3);
                    printf("%d, %d | %d\n", ram_i + 1, ram_i + 3, i4);
                    // value
                    // printf("%d %d | %d\n", a, b, w3);
                    // printf("%d %d | %d\n", c, d, w4);
                    printf("==============================%d\n", ram_i / 4);
                }

                inverse_butterfly(&a, &b, w3, a, b);
                inverse_butterfly(&c, &d, w4, c, d);


                fa = FIFO(DEPT_A, fifo_a, a);
                fb = FIFO(DEPT_B, fifo_b, b);
                fc = FIFO(DEPT_C, fifo_c, c);
                fd = FIFO(DEPT_D, fifo_d, d);

                if (count == 3)
                {
                    // FIFO_A is full
                    write = 1;
                    count = 0;
                }
                else
                {
                    count++;
                }

                if (write)
                {
                    // Serial in Parallel out
                    switch (count & 0b11)
                    {
                    case 0:
                        fa = fifo_a[DEPT_A - 1];
                        fb = fifo_a[DEPT_A - 2];
                        fc = fifo_a[DEPT_A - 3];
                        fd = fifo_a[DEPT_A - 4];
                        break;

                    case 2:
                        fa = fifo_b[DEPT_B - 1];
                        fb = fifo_b[DEPT_B - 2];
                        fc = fifo_b[DEPT_B - 3];
                        fd = fifo_b[DEPT_B - 4];
                        break;
                    case 1:
                        fa = fifo_c[DEPT_C - 1];
                        fb = fifo_c[DEPT_C - 2];
                        fc = fifo_c[DEPT_C - 3];
                        fd = fifo_c[DEPT_C - 4];
                        break;
                    case 3:
                        fa = fifo_d[DEPT_D - 1];
                        fb = fifo_d[DEPT_D - 2];
                        fc = fifo_d[DEPT_D - 3];
                        fd = fifo_d[DEPT_D - 4];
                        break;

                    default:
                        printf("Error, suspect overflow\n");
                        break;
                    }

                    ram->vec[fi].coeffs[0] = fa;
                    ram->vec[fi].coeffs[1] = fb;
                    ram->vec[fi].coeffs[2] = fc;
                    ram->vec[fi].coeffs[3] = fd;
                }
                i1 -= w_m1;
                i2 -= w_m1;
                i3 -= w_m2;
                i4 -= w_m2;
            }
        }
        print_reshaped_array(ram, N / 4, "after level 0, 1");
    }
}

void ntt2x2_wrapper(int32_t a[N])
{
    bram ram;
    reshape(&ram, a);

    ntt2x2(&ram);
}

int main()
{
    // test FIFO
    // int32_t fifo[7] = {0, 1, 2, 3, 4, 5, 6};
    // int32_t out;
    // print_array(fifo, 7, "arr");
    // out = FIFO(7, fifo, 8);
    // printf("output: %d\n", out);
    // print_array(fifo, 7, "arr");
    // out = FIFO(7, fifo, 9);
    // printf("output: %d\n", out);
    // print_array(fifo, 7, "arr");

    // test reshape

    int32_t a[N], a_gold[N];
    for (int i = 0; i < N; i++)
    {
        a[i] = i;
        a_gold[i] = i;
    }

    invntt_tomont(a_gold);
    print_array(a_gold, N, "a_gold");
    ntt2x2_wrapper(a);

    return 0;
}