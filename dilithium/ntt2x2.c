#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include "params.h"
#include "ntt.h"
#include "ntt2x2.h"
#include "util.h"
#include "reduce.h"

// Don't change this 
#define DEPT_I 3
#define DEPT_A 4
#define DEPT_B 6
#define DEPT_C 5
#define DEPT_D 7

#define LOG_N  8 // N= 256, => log(N) = 8

enum OP {NTT_MODE, INVNTT_MODE, MUL_MODE, DECODE_TRUE, DECODE_FALSE};

/* static const int32_t zetas[N] = {
         0,    25847, -2608894,  -518909,   237124,  -777960,  -876248,   466468,
   1826347,  2353451,  -359251, -2091905,  3119733, -2884855,  3111497,  2680103,
   2725464,  1024112, -1079900,  3585928,  -549488, -1119584,  2619752, -2108549,
  -2118186, -3859737, -1399561, -3277672,  1757237,   -19422,  4010497,   280005,
   2706023,    95776,  3077325,  3530437, -1661693, -3592148, -2537516,  3915439,
  -3861115, -3043716,  3574422, -2867647,  3539968,  -300467,  2348700,  -539299,
  -1699267, -1643818,  3505694, -3821735,  3507263, -2140649, -1600420,  3699596,
    811944,   531354,   954230,  3881043,  3900724, -2556880,  2071892, -2797779,
  -3930395, -1528703, -3677745, -3041255, -1452451,  3475950,  2176455, -1585221,
  -1257611,  1939314, -4083598, -1000202, -3190144, -3157330, -3632928,   126922,
   3412210,  -983419,  2147896,  2715295, -2967645, -3693493,  -411027, -2477047,
   -671102, -1228525,   -22981, -1308169,  -381987,  1349076,  1852771, -1430430,
  -3343383,   264944,   508951,  3097992,    44288, -1100098,   904516,  3958618,
  -3724342,    -8578,  1653064, -3249728,  2389356,  -210977,   759969, -1316856,
    189548, -3553272,  3159746, -1851402, -2409325,  -177440,  1315589,  1341330,
   1285669, -1584928,  -812732, -1439742, -3019102, -3881060, -3628969,  3839961,
   2091667,  3407706,  2316500,  3817976, -3342478,  2244091, -2446433, -3562462,
    266997,  2434439, -1235728,  3513181, -3520352, -3759364, -1197226, -3193378,
    900702,  1859098,   909542,   819034,   495491, -1613174,   -43260,  -522500,
   -655327, -3122442,  2031748,  3207046, -3556995,  -525098,  -768622, -3595838,
    342297,   286988, -2437823,  4108315,  3437287, -3342277,  1735879,   203044,
   2842341,  2691481, -2590150,  1265009,  4055324,  1247620,  2486353,  1595974,
  -3767016,  1250494,  2635921, -3548272, -2994039,  1869119,  1903435, -1050970,
  -1333058,  1237275, -3318210, -1430225,  -451100,  1312455,  3306115, -1962642,
  -1279661,  1917081, -2546312, -1374803,  1500165,   777191,  2235880,  3406031,
   -542412, -2831860, -1671176, -1846953, -2584293, -3724270,   594136, -3776993,
  -2013608,  2432395,  2454455,  -164721,  1957272,  3369112,   185531, -1207385,
  -3183426,   162844,  1616392,  3014001,   810149,  1652634, -3694233, -1799107,
  -3038916,  3523897,  3866901,   269760,  2213111,  -975884,  1717735,   472078,
   -426683,  1723600, -1803090,  1910376, -1667432, -1104333,  -260646, -3833893,
  -2939036, -2235985,  -420899, -2286327,   183443,  -976891,  1612842, -3545687,
   -554416,  3919660,   -48306, -1362209,  3937738,  1400424,  -846154,  1976782
};
 */
static const int32_t zetas_barret[N] = {
        0, -3572223,  3765607,  3761513, -3201494, -2883726, -3145678, -3201430, 
  -601683,  3542485,  2682288,  2129892,  3764867, -1005239,   557458, -1221177, 
  -3370349, -4063053,  2663378, -1674615, -3524442,  -434125,   676590, -1335936, 
  -3227876,  1714295,  2453983,  1460718,  -642628, -3585098,  2815639,  2283733, 
  3602218,  3182878,  2740543, -3586446, -3110818,  2101410,  3704823,  1159875, 
    394148,   928749,  1095468, -3506380,  2071829, -4018989,  3241972,  2156050, 
  3415069,  1759347,  -817536, -3574466,  3756790, -1935799, -1716988, -3950053, 
  -2897314,  3192354,   556856,  3870317,  2917338,  1853806,  3345963,  1858416, 
  3073009,  1277625, -2635473,  3852015,  4183372, -3222807, -3121440,  -274060, 
  2508980,  2028118,  1937570, -3815725,  2811291, -2983781, -1109516,  4158088, 
  1528066,   482649,  1148858, -2962264,  -565603,   169688,  2462444, -3334383, 
  -4166425, -3488383,  1987814, -3197248,  1736313,   235407, -3250154,  3258457, 
  -2579253,  1787943, -2391089, -2254727,  3482206, -4182915, -1300016, -2362063, 
  -1317678,  2461387,  3035980,   621164,  3901472, -1226661,  2925816,  3374250, 
  1356448, -2775755,  2683270, -2778788, -3467665,  2312838,  -653275,  -459163, 
    348812,  -327848,  1011223, -2354215, -3818627, -1922253, -2236726,  1744507, 
      1753, -1935420, -2659525, -1455890,  2660408, -1780227,   -59148,  2772600, 
  1182243,    87208,   636927, -3965306, -3956745, -2296397, -3284915, -3716946, 
    -27812,   822541,  1009365, -2454145, -1979497,  1596822, -3956944, -3759465, 
  -1685153, -3410568,  2678278, -3768948, -3551006,   635956,  -250446, -2455377, 
  -4146264, -1772588,  2192938, -1727088,  2387513, -3611750,  -268456, -3180456, 
  3747250,  2296099,  1239911, -3838479,  3195676,  2642980,  1254190,   -12417, 
  2998219,   141835,   -89301,  2513018, -1354892,   613238, -1310261, -2218467, 
  -458740, -1921994,  4040196, -3472069,  2039144, -1879878,  -818761, -2178965, 
  -1623354,  2105286, -2374402, -2033807,   586241, -1179613,   527981, -2743411, 
  -1476985,  1994046,  2491325, -1393159,   507927, -1187885,  -724804, -1834526, 
  -3033742,  -338420,  2647994,  3009748, -2612853,  4148469,   749577, -4022750, 
  3980599,  2569011, -1615530,  1723229,  1665318,  2028038,  1163598, -3369273, 
  3994671,   -11879, -1370517,  3020393,  3363542,   214880,   545376,  -770441, 
  3105558, -1103344,   508145,  -553718,   860144,  3430436,   140244, -1514152, 
  -2185084,  3123762,  2358373, -2193087, -3014420, -1716814,  2926054,  -392707, 
  -303005,  3531229, -3974485, -3773731,  1900052,  -781875,  1054478,  -731434, 
};

int32_t MUL_RAM[N] = {
    41978, 41978, 41978, 41978, 41978, 41978, 41978, 41978, 
    41978, 41978, 41978, 41978, 41978, 41978, 41978, 41978, 
    41978, 41978, 41978, 41978, 41978, 41978, 41978, 41978, 
    41978, 41978, 41978, 41978, 41978, 41978, 41978, 41978, 
    41978, 41978, 41978, 41978, 41978, 41978, 41978, 41978, 
    41978, 41978, 41978, 41978, 41978, 41978, 41978, 41978, 
    41978, 41978, 41978, 41978, 41978, 41978, 41978, 41978, 
    41978, 41978, 41978, 41978, 41978, 41978, 41978, 41978, 
    41978, 41978, 41978, 41978, 41978, 41978, 41978, 41978, 
    41978, 41978, 41978, 41978, 41978, 41978, 41978, 41978, 
    41978, 41978, 41978, 41978, 41978, 41978, 41978, 41978, 
    41978, 41978, 41978, 41978, 41978, 41978, 41978, 41978, 
    41978, 41978, 41978, 41978, 41978, 41978, 41978, 41978, 
    41978, 41978, 41978, 41978, 41978, 41978, 41978, 41978, 
    41978, 41978, 41978, 41978, 41978, 41978, 41978, 41978, 
    41978, 41978, 41978, 41978, 41978, 41978, 41978, 41978, 
    41978, 41978, 41978, 41978, 41978, 41978, 41978, 41978, 
    41978, 41978, 41978, 41978, 41978, 41978, 41978, 41978, 
    41978, 41978, 41978, 41978, 41978, 41978, 41978, 41978, 
    41978, 41978, 41978, 41978, 41978, 41978, 41978, 41978, 
    41978, 41978, 41978, 41978, 41978, 41978, 41978, 41978, 
    41978, 41978, 41978, 41978, 41978, 41978, 41978, 41978, 
    41978, 41978, 41978, 41978, 41978, 41978, 41978, 41978, 
    41978, 41978, 41978, 41978, 41978, 41978, 41978, 41978, 
    41978, 41978, 41978, 41978, 41978, 41978, 41978, 41978, 
    41978, 41978, 41978, 41978, 41978, 41978, 41978, 41978, 
    41978, 41978, 41978, 41978, 41978, 41978, 41978, 41978, 
    41978, 41978, 41978, 41978, 41978, 41978, 41978, 41978, 
    41978, 41978, 41978, 41978, 41978, 41978, 41978, 41978, 
    41978, 41978, 41978, 41978, 41978, 41978, 41978, 41978, 
    41978, 41978, 41978, 41978, 41978, 41978, 41978, 41978, 
    41978, 41978, 41978, 41978, 41978, 41978, 41978, 41978, 
};

int32_t MUL_test_RAM[N] = {
    1, 2, 3, 4, 5, 6, 7, 8,
    9, 10, 11, 12, 13, 14, 15, 16,
    17, 18, 19, 20, 21, 22, 23, 24,
    25, 26, 27, 28, 29, 30, 31, 32,
    33, 34, 35, 36, 37, 38, 39, 40,
    41, 42, 43, 44, 45, 46, 47, 48,
    49, 50, 51, 52, 53, 54, 55, 56,
    57, 58, 59, 60, 61, 62, 63, 64,
    65, 66, 67, 68, 69, 70, 71, 72,
    73, 74, 75, 76, 77, 78, 79, 80,
    81, 82, 83, 84, 85, 86, 87, 88,
    89, 90, 91, 92, 93, 94, 95, 96,
    97, 98, 99, 100, 101, 102, 103, 104,
    105, 106, 107, 108, 109, 110, 111, 112,
    113, 114, 115, 116, 117, 118, 119, 120,
    121, 122, 123, 124, 125, 126, 127, 128,
    129, 130, 131, 132, 133, 134, 135, 136,
    137, 138, 139, 140, 141, 142, 143, 144,
    145, 146, 147, 148, 149, 150, 151, 152,
    153, 154, 155, 156, 157, 158, 159, 160,
    161, 162, 163, 164, 165, 166, 167, 168,
    169, 170, 171, 172, 173, 174, 175, 176,
    177, 178, 179, 180, 181, 182, 183, 184,
    185, 186, 187, 188, 189, 190, 191, 192,
    193, 194, 195, 196, 197, 198, 199, 200,
    201, 202, 203, 204, 205, 206, 207, 208,
    209, 210, 211, 212, 213, 214, 215, 216,
    217, 218, 219, 220, 221, 222, 223, 224,
    225, 226, 227, 228, 229, 230, 231, 232,
    233, 234, 235, 236, 237, 238, 239, 240,
    241, 242, 243, 244, 245, 246, 247, 248,
    249, 250, 251, 252, 253, 254, 255, 256,
};

int32_t MUL_RAM_barret[N] = {
    16382, 16382, 16382, 16382, 16382, 16382, 16382, 16382, 
    16382, 16382, 16382, 16382, 16382, 16382, 16382, 16382, 
    16382, 16382, 16382, 16382, 16382, 16382, 16382, 16382, 
    16382, 16382, 16382, 16382, 16382, 16382, 16382, 16382, 
    16382, 16382, 16382, 16382, 16382, 16382, 16382, 16382, 
    16382, 16382, 16382, 16382, 16382, 16382, 16382, 16382, 
    16382, 16382, 16382, 16382, 16382, 16382, 16382, 16382, 
    16382, 16382, 16382, 16382, 16382, 16382, 16382, 16382, 
    16382, 16382, 16382, 16382, 16382, 16382, 16382, 16382, 
    16382, 16382, 16382, 16382, 16382, 16382, 16382, 16382, 
    16382, 16382, 16382, 16382, 16382, 16382, 16382, 16382, 
    16382, 16382, 16382, 16382, 16382, 16382, 16382, 16382, 
    16382, 16382, 16382, 16382, 16382, 16382, 16382, 16382, 
    16382, 16382, 16382, 16382, 16382, 16382, 16382, 16382, 
    16382, 16382, 16382, 16382, 16382, 16382, 16382, 16382, 
    16382, 16382, 16382, 16382, 16382, 16382, 16382, 16382, 
    16382, 16382, 16382, 16382, 16382, 16382, 16382, 16382, 
    16382, 16382, 16382, 16382, 16382, 16382, 16382, 16382, 
    16382, 16382, 16382, 16382, 16382, 16382, 16382, 16382, 
    16382, 16382, 16382, 16382, 16382, 16382, 16382, 16382, 
    16382, 16382, 16382, 16382, 16382, 16382, 16382, 16382, 
    16382, 16382, 16382, 16382, 16382, 16382, 16382, 16382, 
    16382, 16382, 16382, 16382, 16382, 16382, 16382, 16382, 
    16382, 16382, 16382, 16382, 16382, 16382, 16382, 16382, 
    16382, 16382, 16382, 16382, 16382, 16382, 16382, 16382, 
    16382, 16382, 16382, 16382, 16382, 16382, 16382, 16382, 
    16382, 16382, 16382, 16382, 16382, 16382, 16382, 16382, 
    16382, 16382, 16382, 16382, 16382, 16382, 16382, 16382, 
    16382, 16382, 16382, 16382, 16382, 16382, 16382, 16382, 
    16382, 16382, 16382, 16382, 16382, 16382, 16382, 16382, 
    16382, 16382, 16382, 16382, 16382, 16382, 16382, 16382, 
    16382, 16382, 16382, 16382, 16382, 16382, 16382, 16382, 
};

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

void butterfly(int mode, int32_t *bj, int32_t *bjlen, const int32_t zeta, 
                        const int32_t aj, const int32_t ajlen)
{
    static int32_t aj1, ajlen1;
    static int32_t aj2, ajlen2;
    static int32_t aj3, ajlen3;
    static int32_t aj4, ajlen4;
    
    aj1 = aj;
    ajlen1 = ajlen;
    
    if (mode == INVNTT_MODE)
    {
        /* This code copied from butterfly unit in Dilithium Inverse NTT
        t = a[j];
        a[j] = t + a[j + len];
        a[j + len] = t - a[j + len];
        a[j + len] = montgomery_reduce((int64_t)zeta * a[j + len]); */
        // INV_NTT
        aj2 = aj1 + ajlen1;
        ajlen2 = aj1 - ajlen1;
    }
    else
    {
        aj2 = aj1;
        ajlen2 = ajlen1;
    }

    // MUL
    // t = ajlen = montgomery_reduce((int64_t)zeta * ajlen);
    ajlen3 = ((int64_t)zeta * ajlen2) % Q;
    aj3 = aj2;
    
    if (mode == NTT_MODE)
    {
        /* This code copied from butterfly unit in Dilithium Forward NTT
        t = montgomery_reduce((int64_t)zeta * a[j + len]);
        a[j + len] = a[j] - t;
        a[j] = a[j] + t; */
        // NTT
        ajlen4 = aj3 - ajlen3;
        aj4 = aj3 + ajlen3;
    }
    else
    {
        ajlen4 = ajlen3;
        aj4 = aj3;
    }

    if (mode == INVNTT_MODE)
    {
      // if (aj & 1)
      // {
      //   aj = (aj >> 1) + (Q + 1) / 2;
      // }
      // else
      // {
      //   aj = (aj >> 1);
      // }

      // if (ajlen & 1)
      // {
      //   ajlen = (ajlen >> 1) + (Q + 1) / 2;
      // }
      // else
      // {
      //   ajlen = (ajlen >> 1);
      // }
    }

    *bj = aj4;
    *bjlen = ajlen4;
}

/* Lazy, avoid transpose the matrix */
int addr_decoder(int addr_in)
{
    /* For Inverse NTT
    [ 0  4  8 12] <= [  0* 1  2  3 ]
    [16 20 24 28] <= [  4  5  6  7 ]
    [32 36 40 44] <= [  8  9 10 11 ]
    [48 52 56 60] <= [ 12 13 14 15 ]

    [ 1  5  9 13] <= [ 16 17  18 19 ]
    [17 21 25 29] <= [ 20 21* 22 23 ]
    [33 37 41 45] <= [ 24 25  26 27 ]
    [49 53 57 61] <= [ 28 29  30 31 ]

    [ 2  6 10 14] <= [ 32 33 34  35 ]
    [18 22 26 30] <= [ 36 37 38  39 ]
    [34 38 42 46] <= [ 40 41 42* 43 ]
    [50 54 58 62] <= [ 44 45 46  47 ]

    [ 3  7 11 15] <= [ 48 49 50 51 ]
    [19 23 27 31] <= [ 52 53 54 55 ]
    [35 39 43 47] <= [ 56 57 58 59 ]
    [51 55 59 63] <= [ 60 61 62 63*] 
    */
    const int invntt_map[N / 4] = {
        0, 4, 8, 12, 16, 20, 24, 28, 32, 36, 40, 44, 48, 52, 56, 60,
        1, 5, 9, 13, 17, 21, 25, 29, 33, 37, 41, 45, 49, 53, 57, 61,
        2, 6, 10, 14, 18, 22, 26, 30, 34, 38, 42, 46, 50, 54, 58, 62,
        3, 7, 11, 15, 19, 23, 27, 31, 35, 39, 43, 47, 51, 55, 59, 63};
    return invntt_map[addr_in];
}

void read_fifo(int32_t *fa, int32_t *fb,
               int32_t *fc, int32_t *fd,
               const int count, const int mode,
               const int32_t fifo_a[DEPT_A],
               const int32_t fifo_b[DEPT_B],
               const int32_t fifo_c[DEPT_C],
               const int32_t fifo_d[DEPT_D])
{
    static int32_t ta, tb, tc, td;
    if (mode == INVNTT_MODE)
    {
        // Serial in Parallel out
        switch (count & 0b11)
        {
        case 0:
            ta = fifo_a[DEPT_A - 1];
            tb = fifo_a[DEPT_A - 2];
            tc = fifo_a[DEPT_A - 3];
            td = fifo_a[DEPT_A - 4];
            break;

        case 2:
            ta = fifo_b[DEPT_B - 1];
            tb = fifo_b[DEPT_B - 2];
            tc = fifo_b[DEPT_B - 3];
            td = fifo_b[DEPT_B - 4];
            break;
        case 1:
            ta = fifo_c[DEPT_C - 1];
            tb = fifo_c[DEPT_C - 2];
            tc = fifo_c[DEPT_C - 3];
            td = fifo_c[DEPT_C - 4];
            break;
        case 3:
            ta = fifo_d[DEPT_D - 1];
            tb = fifo_d[DEPT_D - 2];
            tc = fifo_d[DEPT_D - 3];
            td = fifo_d[DEPT_D - 4];
            break;

        default:
            printf("Error, suspect overflow\n");
            break;
        }
    }
    else
    {
        // MUL Mode
        ta = fifo_a[DEPT_A - 1];
        tb = fifo_b[DEPT_B - 3];
        tc = fifo_c[DEPT_C - 2];
        td = fifo_d[DEPT_D - 4];
    }

    *fa = ta;
    *fb = tb;
    *fc = tc;
    *fd = td;
}

void read_ram(int32_t *a, int32_t *b, int32_t *c, int32_t *d,
              const bram *ram, const int ram_i)
{
    *a = ram->vec[ram_i].coeffs[0];
    *b = ram->vec[ram_i].coeffs[1];
    *c = ram->vec[ram_i].coeffs[2];
    *d = ram->vec[ram_i].coeffs[3];
}

void write_ram(bram *ram, const int ram_i,
               const int32_t a, const int32_t b,
               const int32_t c, const int32_t d)
{
    ram->vec[ram_i].coeffs[0] = a;
    ram->vec[ram_i].coeffs[1] = b;
    ram->vec[ram_i].coeffs[2] = c;
    ram->vec[ram_i].coeffs[3] = d;
}

void buttefly_circuit(int32_t *a, int32_t *b, 
                    int32_t *c, int32_t *d,
                    const int32_t w1, 
                    const int32_t w2,
                    const int32_t w3,
                    const int32_t w4, 
                    const int mode)
{
    // 4 pipeline stages
    static int32_t save_b, save_d;
    static int32_t a0, b0, c0, d0;
    static int32_t a1, b1, c1, d1;
    static int32_t a2, b2, c2, d2;
    static int32_t a3, b3, c3, d3;
    static int32_t tw1, tw2, tw3, tw4;

    a0 = *a;
    b0 = *b;
    c0 = *c;
    d0 = *d;

    /* For debugging purpose
    if ((ram_i < 64 || ram_i > 192) && (s > 2))
    {
        // index
        printf("%d, %d | %d\n", ram_i, ram_i + 1, i1);
        printf("%d, %d | %d\n", ram_i + 2, ram_i + 3, i2);
        // value
        printf("%d %d | %d\n", a, b, i1);
        printf("%d %d | %d\n", c, d, i2);
    } */
    if (mode == MUL_MODE)
    {
        tw1 = w2; 
        tw2 = w4;
    }
    else
    {
        tw1 = w1;
        tw2 = w2;
    }
    butterfly(mode, &a1, &b1, tw1, a0, b0);
    butterfly(mode, &c1, &d1, tw2, c0, d0);

    save_b = b1; 
    save_d = d1;

    a2 = a1;
    c2 = b1;

    if (mode == MUL_MODE)
    {
        // switch lane A -> B, C->D 
        b2 = a1;
        d2 = c1;
    }
    else
    {
        b2 = c1;
        d2 = d1;
    }

    /* For debugging purpose
    if ((ram_i < 64 || ram_i > 192) && (s > 2))
    {
        // index
        printf("%d, %d | %d\n", ram_i, ram_i + 2, i3);
        printf("%d, %d | %d\n", ram_i + 1, ram_i + 3, i4);
        // value
        printf("%d %d | %d\n", a, b, i3);
        printf("%d %d | %d\n", c, d, i4);
        printf("==============================%d %d | %d %d\n", ram_i / 4, ram_i, j, k);
    } */

    if (mode == MUL_MODE)
    {
        tw3 = w1;
        tw4 = w3;
    }
    else
    {
        tw3 = w3;
        tw4 = w4;
    }
    butterfly(mode, &a3, &b3, tw3, a2, b2);
    butterfly(mode, &c3, &d3, tw4, c2, d2);

    if (mode == MUL_MODE)
    {
        // switch lane again, B->A, D->C
        *a = b3; 
        *b = save_b;
        *c = d3; 
        *d = save_d;
    }
    else
    {
        // NTT Mode
        *a = a3; 
        *b = b3;
        *c = c3; 
        *d = d3;
    }
}

void ntt2x2(bram *ram, bram *mul_ram, int mode, int decode)
{
    int32_t fifo_i[DEPT_I] = {0},
            fifo_a[DEPT_A] = {0},
            fifo_b[DEPT_B] = {0},
            fifo_c[DEPT_C] = {0},
            fifo_d[DEPT_D] = {0};
    int32_t a, b, c, d;
    int32_t fa, fb, fc, fd, fi;

    int i1, i2, i3, i4;
    int ram_i, bound, addr;

    int count = 0;
    int write = 0;
    int m_counter = 0;

    const int w_m1 = 2;
    const int w_m2 = 1;

    int32_t w1, w2, w3, w4;
    

    switch (mode)
    {
    case MUL_MODE:
        bound = 1;
        break;
    
    case INVNTT_MODE:
        bound = LOG_N;
        break;
    
    case NTT_MODE:
        bound = LOG_N;
        printf("FOFWARD NTT is not ready\n");
        break;
    
    default:
        printf("Error: MODE is wrong\n");
        bound = 0;
        break;
    }

    // iterate 2 levels at a time
    for (int s = 0; s < bound; s += 2)
    {
        for (int j = 0; j < (1 << s); j++)
        {          
            for (int k = 0; k < N/4; k += 1 << s)
            {
                if (k == 0)
                {
                    if (mode == INVNTT_MODE)
                    {
                        // NTT mode
                        // Layer s 
                        i1 = (N >> s) - 1;
                        i2 = (N >> s) - 2;
                        // Layer s + 1
                        i4 = i3 = (N >> (s+1)) - 1;
                    }
                }

                addr = k + j; 
                if (decode == DECODE_TRUE)
                {
                    ram_i = addr_decoder(addr);
                }
                else
                {
                    ram_i = addr;
                }

                if (mode == INVNTT_MODE)
                {
                    // w1 = -zetas[i1];
                    // w2 = -zetas[i2];
                    // w3 = -zetas[i3];
                    // w4 = -zetas[i4];
                    w1 = -zetas_barret[i1];
                    w2 = -zetas_barret[i2];
                    w3 = -zetas_barret[i3];
                    w4 = -zetas_barret[i4];
                }
                else{
                    // MUL
                    read_ram(&w1, &w2, &w3, &w4, mul_ram, ram_i);
                }

                read_ram(&a, &b, &c, &d, ram, ram_i);

                // 2x2 circuit
                buttefly_circuit(&a, &b, &c, &d, w1, w2, w3, w4, mode);

                // FIFO 
                FIFO(DEPT_A, fifo_a, a);
                FIFO(DEPT_B, fifo_b, b);
                FIFO(DEPT_C, fifo_c, c);
                FIFO(DEPT_D, fifo_d, d);
                fi = FIFO(DEPT_I, fifo_i, ram_i);

                if (count == DEPT_I)
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
                    read_fifo(&fa, &fb, &fc, &fd, count, mode, fifo_a, fifo_b, fifo_c, fifo_d);
                    write_ram(ram, fi, fa, fb, fc, fd);
                    
                    // writeback
                    // printf("[%d] <= (%d, %d, %d, %d)\n", fi, fa, fb, fc, fd);
                }
                if (mode == INVNTT_MODE)
                {
                    // Only adjust omega in NTT mode
                    i1 -= w_m1;
                    i2 -= w_m1;
                    i3 -= w_m2;
                    i4 -= w_m2;
                }
                // // Decode only happen once
                // if (decode == DECODE_TRUE)
                // {
                //     printf("%d\n", k);
                // }
            }
        }
            decode = DECODE_FALSE;
    }
    // Write back left over coefficients in FIFO
    for (int i = 0; i < DEPT_I; i++)
    {
        fi = FIFO(DEPT_I, fifo_i, 0);
        FIFO(DEPT_A, fifo_a, 0);
        FIFO(DEPT_B, fifo_b, 0);
        FIFO(DEPT_C, fifo_c, 0);
        FIFO(DEPT_D, fifo_d, 0);
        count++;

        read_fifo(&fa, &fb, &fc, &fd, count, mode, fifo_a, fifo_b, fifo_c, fifo_d);
        write_ram(ram, fi, fa, fb, fc, fd);
        // writeback
        // printf("[%d] <= (%d, %d, %d, %d)\n", fi, fa, fb, fc, fd);
    }
    /* // For debugging purpose 
    print_array(fifo_i, DEPT_I, "fifo_i");
    print_array(fifo_a, DEPT_A, "fifo_a");
    print_array(fifo_b, DEPT_B, "fifo_b");
    print_array(fifo_c, DEPT_C, "fifo_c");
    print_array(fifo_d, DEPT_D, "fifo_d"); 
    */
}

int ntt2x2_INVNTT(int32_t r_gold[N], int32_t r[N])
{
    bram ram, mul_ram;
    // Load data into BRAM, 4 coefficients per line
    reshape(&ram, r);
    reshape(&mul_ram, MUL_RAM_barret);
    // Compute NTT
    ntt2x2(&ram, &mul_ram, INVNTT_MODE, DECODE_FALSE);
    
    // Enable DECODE_TRUE only after NTT transform
    ntt2x2(&ram, &mul_ram, MUL_MODE, DECODE_TRUE);


    // Run the reference code
    invntt_tomont(r_gold);

    // Compare with the reference code
    int32_t a, b, c, d;
    int32_t ta, tb, tc, td;

    int addr;
    int ret = 0;

    // print_array(r_gold, 16, "r_gold");
    // print_reshaped_array(&ram, 4, "ram");

    for (int i = 0; i < N; i += 4)
    {
        // Get golden result
        a = r_gold[i + 0];
        b = r_gold[i + 1];
        c = r_gold[i + 2];
        d = r_gold[i + 3];

        addr = addr_decoder( i / 4 );
        read_ram(&ta, &tb, &tc, &td, &ram, addr);
        // Comapre with reference code

        // Quick xor, I hate long if-else clause
        ret |= a != ta;
        ret |= b != tb;
        ret |= c != tc;
        ret |= d != td;

        if (ret)
        {
            printf("INVTNTT Error at index: %d => %d\n", addr, i);
            printf("%12d | %12d | %12d | %12d\n", a, b, c, d);
            printf("%12d | %12d | %12d | %12d\n", ta, tb, tc, td);
            return 1;
        }
    }
    printf("==============INV_NTT is Correct!\n\n");
    return 0;
}

int ntt2x2_MUL(int32_t r_gold[N], int32_t r[N])
{
    bram ram, mul_ram;
    
    // Load data into BRAM, 4 coefficients per line
    reshape(&ram, r);
    reshape(&mul_ram, MUL_test_RAM);

    // MUL Operation using NTT
    // Enable DECODE_TRUE only after NTT transform
    // This example we only do pointwise multiplication
    ntt2x2(&ram, &mul_ram, MUL_MODE, DECODE_FALSE);
    
    // Run the reference code
    pointwise_montgomery(r_gold, r_gold, MUL_test_RAM);

    // Compare with the reference code
    int32_t a, b, c, d;
    int32_t ta, tb, tc, td;

    int addr;
    int ret = 0;

    // print_array(r_gold, 32, "gold");
    // print_reshaped_array(&ram, 8, "first 8");

    for (int i = 0; i < N; i += 4)
    {
        // Get golden result
        a = r_gold[i + 0];
        b = r_gold[i + 1];
        c = r_gold[i + 2];
        d = r_gold[i + 3];

        addr = i / 4;
        read_ram(&ta, &tb, &tc, &td, &ram, addr);
        
        // Comapre with reference code

        // Quick xor, I hate long if-else clause
        ret |= a != ta;
        ret |= b != tb;
        ret |= c != tc;
        ret |= d != td;

        if (ret)
        {
            printf("MUL Error at index: %d => %d\n", addr, i);
            printf("%12d | %12d | %12d | %12d\n", a, b, c, d);
            printf("%12d | %12d | %12d | %12d\n", ta, tb, tc, td);
            return 1;
        }
    }
    printf("==============MUL is Correct!\n\n");
    return 0;
}

#define TESTS 10

int main()
{
    srand(time(0));
    // srand(0);
    int32_t r[N], r_gold[N], r_gold_copy[N], r_copy[N];
    int32_t t1, t2;
    int ret = 0;

    for (int k = 0; k < TESTS; k++)
    {
        for (int i = 0; i < N; i++)
        {
            // t1 = i;
            t1 = rand() % Q;
            r[i] = t1;
            r_gold[i] = t1;
            
            // t2 = i + 2;
            t2 = rand() % Q;
            r_gold_copy[i] = t2; 
            r_copy[i] = t2;
        }

        ret |= ntt2x2_INVNTT(r_gold, r);
        ret |= ntt2x2_MUL(r_gold_copy, r_copy);

        if (ret)
        {
           break;
        }
    }

    // ntt(r_gold);

    if (ret)
    {
        printf("ERROR\n");
    }
    else
    {
      printf("OK\n");
    }

    return ret;
}

/* 
 * Combine GS and CT butterfly  unit: DONE 
 * Replace Montgomery to Barrett reduction: DONE 
 * Divide by 2 in inverse NTT: No yet 
 * Find algorithm to compute fast bit-reverse permutation for Forward NTT: 
 * What the point of merging forward and inverse butterfly unit?
 */