#include <stdint.h>
#include "params.h"
#include "consts.h"

#if FALCON_N == 256
extern const uint16_t zetas_barrett[] = {
        1, 10984,  3542, 10643,  7468, 11726,  5728,  8961, 
    2319,  9088,  4846,  4805,  3091,  9326, 11112, 12149, 
    1260,  2426,  2013,  2881,  8595,  3382,  3637,  9558, 
    9447,  9821, 10616,  8112, 11336,  2476,  3949,  7935, 
    2401,   390,   354,  5012,  1017,    27,  1537,  9611, 
    1002,  7313,  9852,  9723, 11224,  1168,   493,  7952, 
    2166, 12129,  3636, 10863,  3364,  9442,  7247,  5195, 
    9042,  9919,  1630, 11136,  9890,  9289,  6730,  3985, 
    49,  9789,  1512,  5369,  9551,  9280, 10314,  8974, 
    3030,  2908,  3963,  1954,  3991,  2281,  3772,  5429, 
    295,  8273,   325,  5990,  3329,  5961,  6167,  1360, 
    8210,  1958,  4046,  4240,  2459, 10723,  9166,  7856, 
    7048,  6821,  5057, 12097,   677,  1323,  1579,  3957, 
    12231,  1956,  3477,  9445,  9260,  8076, 11868,  8689, 
    7822,  4449,  6118,  3860,  5079,  7965, 11011,  8775, 
    654,  6760,  6136,  4948,  5339,   468, 10256, 10930, 
        7,  3154,   216,   767,  3120,  8348,  3229,  1282, 
    3944,  2171,  9344,  9057,  9348,  3837,  4050, 11309, 
    8820,  4693,  1802,  7878, 11009, 11385,   881,  5461, 
    4684,  7302,   578,  7628,  5618,  5043,  3065,  6389, 
    4518,  2730,  2478, 10506,  7119,   189, 10759,  5832, 
    7014,  2035,  7519,  6616,  4834,  8176,  3451,  6508, 
    2873, 11169,   874,  2307, 11259,  4649,  1573, 11787, 
    1849,  7988, 11410,  4218,  7785,  3578, 10243,  3317, 
    343,  7078, 10584,   716,  5412,  3515, 10753,  1373, 
    8921,  8067,  3163,  1389,  3359,  3678,  1826,  1136, 
    2065,  8755,  2275,  5063, 11014,  4860,  6302,  9520, 
    8314,  1417,  3744,  5102,  4924,  1327,  2717,  5836, 
    180, 10880, 10821, 10945,  4739,  9261, 11053,  3121, 
    11883,  1403, 12050,  4670,  3375,  7376,  9342, 11667, 
    5598,  6565,  5959,  2442, 10975,  6599,  3343, 12269, 
    4578, 10453,  6085, 10058,   506,  3276, 10347,  2776, 
};


const uint16_t MUL_test_RAM[FALCON_N] = {
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

#elif FALCON_N == 512
extern const uint16_t zetas_barrett[] = {
        1,  7143, 10984,  5736,  3542,  9744, 10643,  3195, 
    7468,  9664, 11726,  9283,  5728,  5023,  8961,  7311, 
    2319, 11334,  9088,  5086,  4846,  9154,  4805, 11227, 
    3091,  7969,  9326,  9238, 11112, 10654, 12149,  7678, 
    1260,  4632,  2426,  1428,  2013,   729,  2881,  7197, 
    8595, 10530,  3382,  9741,  3637,   145,  9558,  7399, 
    9447,  1022,  9821,  5791, 10616,  6958,  8112,  1381, 
    11336,   827,  2476,  2197,  3949,  4452,  7935,  2837, 
    2401,  7188,   390,  8456,   354,  9377,  5012,  2859, 
    1017,  1632,    27,  8526,  1537,  4714,  9611,  5019, 
    1002,  5088,  7313,  8509,  9852,  6022,  9723,  6250, 
    11224, 11885,  1168, 11082,   493,  6845,  7952,  1378, 
    2166, 12176, 12129, 12286,  3636,  5291, 10863,  1663, 
    3364,  4057,  9442,  2174,  7247,  4053,  5195,  7394, 
    9042,  8311,  9919,  5332,  1630,  5407, 11136, 10040, 
    9890,  7098,  9289,  3016,  6730, 10111,  3985,  3531, 
    49,  5915,  9789, 10706,  1512, 10474,  5369,  9087, 
    9551,  6554,  9280,   174, 10314,   347,  8974,  1858, 
    3030,  2361,  2908,  3434,  3963,  6142,  1954,  9407, 
    3991,  9522,  2281, 10258,  3772,  5908,  5429,  7552, 
    295,  5766,  8273,  8527,   325, 11143,  5990,  8561, 
    3329, 12121,  5961, 10327,  6167,  7105,  1360,  6170, 
    8210,   922,  1958,  1112,  4046,  9139,  4240,  6224, 
    2459,  3656, 10723,  9341,  9166,  9235,  7856,  3834, 
    7048,  8120,  6821,  8807,  5057,  4780, 12097,  4912, 
    677,  6234,  1323, 12237,  1579,  9784,  3957,   151, 
    12231,  3532,  1956, 11404,  3477,   142,  9445, 11314, 
    9260,  4782,  8076,  2302, 11868,  3602,  8689,  6077, 
    7822,  6752,  4449, 12142,  6118,  1190,  3860,  7753, 
    5079,  2169,  7965,  8214, 11011,  1973,  8775,  5925, 
    654,  1702,  6760,  3199,  6136,  6874,  4948,   400, 
    5339,  3710,   468,   316, 10256,  3879, 10930,   973, 
        7,   845,  3154,  3285,   216,  6763,   767, 10076, 
    3120,  6203,  8348,  3536,  3229, 10583,  1282,  2021, 
    3944,  5604,  2171, 11024,  9344,  2633,  9057,  4855, 
    9348,  6627,  3837,  3221,  4050,   844, 11309,  4590, 
    8820,  7846,  4693,  9996,  1802,  5103,  7878,  1223, 
    11009, 12265, 11385,  6742,   881,  1015,  5461,  2637, 
    4684,  7154,  7302,  3670,   578, 11839,  7628,  9667, 
    5618,  5789,  5043,  3090,  3065,  6586,  6389,  7570, 
    4518,  1160,  2730, 10036,  2478,  4194, 10506,  7724, 
    7119, 11424,   189, 10526, 10759,  8420,  5832, 10555, 
    7014, 11038,  2035, 10407,  7519,  5287,  6616,  6883, 
    4834,  9461,  8176,  3840,  3451, 11048,  6508,  9646, 
    2873, 11498, 11169, 12268,   874,   170,  2307, 11641, 
    11259,  3821,  4649,  2929,  1573,  3793, 11787,  2602, 
    1849,  9021,  7988,   457, 11410,   982,  4218,  8835, 
    7785,   530,  3578,  8823, 10243,  9332,  3317,   139, 
    343,  4538,  7078,  1208, 10584, 11873,   716,  2164, 
    5412,  9011,  3515,  1218, 10753,  2429,  1373,   717, 
    8921,  4238,  8067, 11749,  3163,  6127,  1389,  4404, 
    3359,  5209,  3678, 10361,  1826,  4489,  1136,  3708, 
    2065,  3495,  8755, 10533,  2275,  4267,  5063, 10771, 
    11014, 11113,  4860, 10844,  6302,   579,  9520,  6323, 
    8314,  6454,  1417,  7784,  3744,  2528,  5102,  6701, 
    4924,  1014,  1327,  3942,  2717,  3200,  5836,  2260, 
    180,  7684, 10880,   204, 10821,  8882, 10945,  9806, 
    4739,  6771,  9261, 11925, 11053,  7043,  3121,  1057, 
    11883,   146,  1403,  6094, 12050,   994,  4670,  5464, 
    3375,  8896,  7376,  3825,  9342,   636, 11667,  5672, 
    5598, 10397,  6565, 11260,  5959,  8330,  2442,  5115, 
    10975,  2894,  6599,  8342,  3343,  1522, 12269,  4608, 
    4578, 11914, 10453, 10104,  6085, 11251, 10058,  2800, 
    506,  1392,  3276,  2212, 10347,  2575,  2776,  6811, 
};


const uint16_t MUL_test_RAM[FALCON_N] = {
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

#elif FALCON_N == 1024
extern const uint16_t zetas_barrett[] = {
        1, 10810,  7143,  4043, 10984,   722,  5736,  8155, 
    3542,  8785,  9744,  3621, 10643,  1212,  3195,  5860, 
    7468,  2639,  9664, 11340, 11726,  9314,  9283,  9545, 
    5728,  7698,  5023,  5828,  8961,  6512,  7311,  1351, 
    2319, 11119, 11334, 11499,  9088,  3014,  5086, 10963, 
    4846,  9542,  9154,  3712,  4805,  8736, 11227,  9995, 
    3091, 12208,  7969, 11289,  9326,  7393,  9238,  2366, 
    11112,  8034, 10654,  9521, 12149, 10436,  7678, 11563, 
    1260,  4388,  4632,  6534,  2426,   334,  1428,  1696, 
    2013,  9000,   729,  3241,  2881,  3284,  7197, 10200, 
    8595,  7110, 10530,  8582,  3382, 11934,  9741,  8058, 
    3637,  3459,   145,  6747,  9558,  8357,  7399,  6378, 
    9447,   480,  1022,     9,  9821,   339,  5791,   544, 
    10616,  4278,  6958,  7300,  8112,  8705,  1381,  9764, 
    11336,  8541,   827,  5767,  2476,   118,  2197,  7222, 
    3949,  8993,  4452,  2396,  7935,   130,  2837,  6915, 
    2401,   442,  7188, 11222,   390,   773,  8456,  3778, 
    354,  4861,  9377,  5698,  5012,  9808,  2859, 11244, 
    1017,  7404,  1632,  7205,    27,  9223,  8526, 10849, 
    1537,   242,  4714,  8146,  9611,  3704,  5019, 11744, 
    1002,  5011,  5088,  8005,  7313, 10682,  8509, 11414, 
    9852,  3646,  6022,  2987,  9723, 10102,  6250,  9867, 
    11224,  2143, 11885,  7644,  1168,  5277, 11082,  3248, 
    493,  8193,  6845,  2381,  7952, 11854,  1378,  1912, 
    2166,  3915, 12176,  7370, 12129,  3149, 12286,  4437, 
    3636,  4938,  5291,  2704, 10863,  7635,  1663, 10512, 
    3364,  1689,  4057,  9018,  9442,  7875,  2174,  4372, 
    7247,  9984,  4053,  2645,  5195,  9509,  7394,  1484, 
    9042,  9603,  8311,  9320,  9919,  2865,  5332,  3510, 
    1630, 10163,  5407,  3186, 11136,  9405, 10040,  8241, 
    9890,  8889,  7098,  9153,  9289,   671,  3016,   243, 
    6730,   420, 10111,  1544,  3985,  4905,  3531,   476, 
    49,  1263,  5915,  1483,  9789, 10800, 10706,  6347, 
    1512,   350, 10474,  5383,  5369, 10232,  9087,  4493, 
    9551,  6421,  6554,  2655,  9280,  1693,   174,   723, 
    10314,  8532,   347,  2925,  8974, 11863,  1858,  4754, 
    3030,  4115,  2361, 10446,  2908,   218,  3434,  8760, 
    3963,   576,  6142,  9842,  1954, 10238,  9407, 10484, 
    3991,  8320,  9522,   156,  2281,  5876, 10258,  5333, 
    3772,   418,  5908, 11836,  5429,  7515,  7552,  1293, 
    295,  6099,  5766,   652,  8273,  4077,  8527,  9370, 
    325, 10885, 11143, 11341,  5990,  1159,  8561,  8240, 
    3329,  4298, 12121,  2692,  5961,  7183, 10327,  1594, 
    6167,  9734,  7105, 11089,  1360,  3956,  6170,  5297, 
    8210, 11231,   922,   441,  1958,  4322,  1112,  2078, 
    4046,   709,  9139,  1319,  4240,  8719,  6224, 11454, 
    2459,   683,  3656, 12225, 10723,  5782,  9341,  9786, 
    9166, 10542,  9235,  6803,  7856,  6370,  3834,  7032, 
    7048,  9369,  8120,  9162,  6821,  1010,  8807,   787, 
    5057,  4698,  4780,  8844, 12097,  1321,  4912, 10240, 
    677,  6415,  6234,  8953,  1323,  9523, 12237,  3174, 
    1579, 11858,  9784,  5906,  3957,  9450,   151, 10162, 
    12231, 12048,  3532, 11286,  1956,  7280, 11404,  6281, 
    3477,  6608,   142, 11184,  9445,  3438, 11314,  4212, 
    9260,  6695,  4782,  5886,  8076,   504,  2302, 11684, 
    11868,  8209,  3602,  6068,  8689,  3263,  6077,  7665, 
    7822,  7500,  6752,  4749,  4449,  6833, 12142,  8500, 
    6118,  8471,  1190,  9606,  3860,  5445,  7753, 11239, 
    5079,  9027,  2169, 11767,  7965,  4916,  8214,  5315, 
    11011,  9945,  1973,  6715,  8775, 11248,  5925, 11271, 
    654,  3565,  1702,  1987,  6760,  5206,  3199, 12233, 
    6136,  6427,  6874,  8646,  4948,  6152,   400, 10561, 
    5339,  5446,  3710,  6093,   468,  8301,   316, 11907, 
    10256,  8291,  3879,  1922, 10930,  6854,   973, 11035, 
        7,  1936,   845,  3723,  3154,  5054,  3285,  7929, 
    216,    50,  6763,   769,   767,  8484, 10076,  4153, 
    3120,  6184,  6203,  5646,  8348,  3753,  3536,  5370, 
    3229,  4730, 10583,  3929,  1282,  8717,  2021,  9457, 
    3944,  4099,  5604,  6759,  2171,  8809, 11024,  3007, 
    9344,  5349,  2633,  1406,  9057, 11996,  4855,  8520, 
    9348, 11722,  6627,  5289,  3837,  2595,  3221,  4273, 
    4050,  7082,   844,  5202, 11309, 11607,  4590,  7207, 
    8820,  6138,  7846,  8871,  4693,  2338,  9996, 11872, 
    1802,  1555,  5103, 10398,  7878, 10699,  1223,  9955, 
    11009,   614, 12265, 10918, 11385,  9804,  6742,  7250, 
    881, 11924,  1015, 10362,  5461,  9343,  2637,  7779, 
    4684,  3360,  7154,    63,  7302,  2373,  3670,  3808, 
    578,  5368, 11839,  1944,  7628, 11779,  9667,  6903, 
    5618, 10631,  5789,  3502,  5043,   826,  3090,  1398, 
    3065,  1506,  6586,  4483,  6389,   910,  7570, 11538, 
    4518,  3094,  1160,  4820,  2730,  5411, 10036,  1868, 
    2478,  9449,  4194,  3019, 10506,  7211,  7724,  4974, 
    7119,  2672, 11424,  1279,   189,  3116, 10526,  2209, 
    10759,  1694,  8420,  7866,  5832,  1350, 10555,  8474, 
    7014, 10499, 11038,  6879,  2035,  1040, 10407,  6164, 
    7519,   944,  5287,  8620,  6616,  9269,  6883,  7624, 
    4834,  2712,  9461,  4352,  8176,    72,  3840, 10447, 
    3451,  8195, 11048,  4378,  6508,  9244,  9646,  1095, 
    2873,  2827, 11498,  2434, 11169,  9754, 12268,  6481, 
    874,  9988,   170,  6639,  2307,  4289, 11641, 12139, 
    11259, 11823,  3821,  1681,  4649,  5969,  2929,  6026, 
    1573,  8443,  3793,  6226, 11787,  5118,  2602, 10388, 
    1849,  5776,  9021,  3795,  7988,  7766,   457, 12281, 
    11410,  9696,   982, 10013,  4218,  4390,  8835,  8531, 
    7785,   778,   530,  2626,  3578,  4697,  8823,  1701, 
    10243,  2940,  9332, 10808,  3317,  9757,   139,  3332, 
    343,  8841,  4538, 10381,  7078,  1866,  1208,  7562, 
    10584,  2450, 11873,   814,   716, 10179,  2164,  6873, 
    5412,  8080,  9011,  6296,  3515, 11851,  1218,  5061, 
    10753, 10568,  2429,  8186,  1373,  9307,   717,  8700, 
    8921,  4227,  4238, 11677,  8067,  1526, 11749, 12164, 
    3163,  4032,  6127,  7449,  1389, 10221,  4404, 11943, 
    3359,  9084,  5209,  1092,  3678,  4265, 10361,   464, 
    1826,  2926,  4489,  9118,  1136,  3449,  3708,  9051, 
    2065,  5826,  3495,  4564,  8755,  3961, 10533,  4145, 
    2275,  2461,  4267,  5653,  5063,  8113, 10771,  8524, 
    11014,  5508, 11113,  6555,  4860,  1125, 10844, 11158, 
    6302,  6693,   579,  3889,  9520,  3114,  6323,   212, 
    8314,  4883,  6454,  3087,  1417,  5676,  7784,  2257, 
    3744,  4963,  2528,  9233,  5102, 11877,  6701,  6444, 
    4924,  4781,  1014, 11841,  1327,  3607,  3942,  7057, 
    2717,    60,  3200, 10754,  5836,  7723,  2260,    68, 
    180,  4138,  7684,  2689, 10880,  7070,   204,  5509, 
    10821,  8308,  8882,   463, 10945,  9247,  9806, 10235, 
    4739,  8038,  6771,  1226,  9261,  5216, 11925,  9929, 
    11053,  9272,  7043,  4475,  3121,  4705,  1057,  9689, 
    11883, 10602,   146,  5268,  1403,  1804,  6094,  7100, 
    12050,  9389,   994,  4554,  4670, 11777,  5464,  4906, 
    3375,  9998,  8896,  4335,  7376,  3528,  3825,  8054, 
    9342,  8307,   636,  5609, 11667, 10552,  5672,  4499, 
    5598,  3344, 10397,  8665,  6565, 10964, 11260, 10344, 
    5959, 10141,  8330,  5797,  2442,  1248,  5115,  4939, 
    10975,  1744,  2894,  8635,  6599,  9834,  8342,   338, 
    3343,  8170,  1522, 10138, 12269,  5002,  4608,  5163, 
    4578,   377, 11914,  1620, 10453, 11864, 10104, 11897, 
    6085,  8122, 11251, 11366, 10058,  6197,  2800,   193, 
    506,  1255,  1392,  5784,  3276,  8951,  2212,  9615, 
    10347,  8881,  2575,  1165,  2776, 11111,  6811,  3511, 
};

const uint16_t MUL_test_RAM[FALCON_N] = {
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

#else 
#error "Support only FALCON_N = 256, 512, 1024"
#endif
