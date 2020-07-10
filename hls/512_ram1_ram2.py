  
gammas_bitrev_montgomery = [4075,5315,7965,7373,522,10120,9027,5079,2344,1278,1973,5574,1018,6364,11248,8775,
  7500,7822,5537,4749,8500,12142,5456,7840,5445,3860,4536,11239,6171,8471,2683,11099,
  10561,400,6137,7341,5415,8646,6136,5862,5529,5206,56,9090,8724,11635,1702,10302,
  5339,6843,6093,3710,316,382,11821,8301,10930,5435,11035,973,8291,10256,8410,1922,
  12097,10968,10240,4912,4698,5057,7509,8844,8807,11502,5468,1010,9162,8120,2920,5241,
  6055,8953,677,5874,2766,10966,12237,9115,12138,10162,3957,2839,6383,2505,11858,1579,
  9026,3600,6077,4624,11868,4080,6068,3602,605,9987,504,8076,4782,6403,3029,6695,
  11184,142,5681,8812,2844,3438,8077,975,58,12048,1003,8757,885,6281,1956,5009,
  12225,3656,11606,9830,1566,5782,2503,2948,7032,3834,5919,4433,3054,6803,9166,1747,
  10211,11177,4322,1958,922,11848,4079,11231,4046,11580,1319,9139,6224,835,8049,8719,
  7105,1200,6122,9734,3956,1360,6119,5297,4298,3329,168,2692,1594,10327,5106,6328,
  3728,8240,5990,11130,948,1146,10885,325,8212,4016,8527,2919,295,6190,652,5766,
  11713,8326,6142,2447,1805,2882,10238,1954,1843,9928,4115,3030,2908,12071,8760,3434,
  5876,2281,2031,5333,8298,8320,12133,2767,11836,5908,11871,8517,6860,7515,10996,4737,
  2500,10800,5942,1583,11026,12240,5915,10806,1815,5383,1512,11939,2057,6920,9087,7796,
  8974,426,4754,1858,8532,10314,11942,2925,174,11566,3009,1693,2655,6554,5868,2738,
  11796,8193,9908,5444,10911,1912,7952,435,404,7644,11224,10146,7012,11121,11082,9041,
  9723,2187,9867,6250,3646,9852,6267,2987,8509,875,4976,10682,8005,5088,7278,11287,
  9223,27,3763,10849,11272,7404,5084,10657,8146,4714,12047,10752,2678,3704,545,7270,
  1067,5101,442,2401,390,11516,3778,8456,1045,9430,9808,5012,9377,6591,11935,4861,
  7852,3,3149,12129,12176,4919,10123,3915,3636,7351,2704,5291,1663,1777,1426,7635,
  1484,7394,2780,7094,8236,2645,7247,2305,2847,7875,7917,10115,10600,8925,4057,3271,
  9273,243,9289,11618,3136,5191,8889,9890,11869,5559,10111,10745,11813,8758,4905,3985,
  9603,9042,3978,9320,3510,5332,9424,2370,9405,11136,2249,8241,10659,10163,9103,6882,
  10810,1,5146,4043,8155,5736,11567,1305,1212,10643,9094,5860,8747,8785,8668,2545,
  4591,6561,5023,6461,10938,4978,6512,8961,949,2625,2639,7468,11726,2975,9545,9283,
  3091,81,11289,7969,9238,9923,2963,7393,12149,1853,11563,7678,8034,11112,1635,9521,
  3201,3014,1326,7203,1170,9970,11334,790,3135,3712,4846,2747,3553,7484,11227,2294,
  11267,9,9447,11809,11950,2468,5791,11745,10908,9764,8112,3584,4989,5331,4278,10616,
  4452,9893,8340,8993,130,7935,9452,6915,8541,11336,11462,5767,7222,2197,12171,9813,
  3241,729,3289,10276,9408,3284,2089,5092,11029,4388,5755,7657,10861,1696,2426,11955,
  4231,2548,11934,3382,10530,3707,3694,7110,3637,8830,6747,145,7399,5911,2731,8357,]

hls_ram1_gammas_bitrev_montgomery = []
hls_ram2_gammas_bitrev_montgomery = []
for i in range(0, len(gammas_bitrev_montgomery), 2):
    hls_ram2_gammas_bitrev_montgomery.append( gammas_bitrev_montgomery[i]  )
    hls_ram1_gammas_bitrev_montgomery.append( gammas_bitrev_montgomery[i+1])

print(f"uint16_t hls_ram2_gammas_bitrev_montgomery[NEWHOPE_N/2]={hls_ram2_gammas_bitrev_montgomery}")
print(f"uint16_t hls_ram1_gammas_bitrev_montgomery[NEWHOPE_N/2]={hls_ram1_gammas_bitrev_montgomery}")

gammas_inv_montgomery= [512,3944,4267,5411,9615,5900,3205,6063,9261,2021,3087,4770,1029,1590,343,530,
  8307,4273,2769,9617,923,7302,4404,2434,1468,9004,8682,11194,2894,11924,5061,8071,
  1687,10883,8755,7724,11111,6671,7800,6320,2600,6203,4963,6164,9847,6151,11475,10243,
  3825,11607,1275,3869,425,5386,4238,9988,5509,11522,10029,7937,3343,6742,9307,10440,
  11295,3480,3765,1160,1255,4483,8611,9687,11063,3229,7784,9269,6691,7186,10423,10588,
  11667,11722,3889,12100,9489,12226,3163,12268,9247,12282,11275,4094,11951,5461,8080,10013,
  10886,7434,7725,2478,2575,826,9051,8468,3017,6919,5102,10499,5797,7596,10125,2532,
  3375,844,1125,8474,375,6921,125,2307,4138,769,9572,8449,7287,11009,2429,7766,
  4906,6685,9828,10421,3276,7570,1092,10716,364,3572,8314,5287,10964,9955,7751,11511,
  6680,3837,6323,1279,6204,8619,2068,2873,8882,5054,7057,5781,10545,1927,3515,8835,
  5268,2945,1756,5078,8778,5789,2926,6026,9168,6105,3056,2035,5115,8871,1705,2957,
  8761,5082,11113,1694,11897,4661,8062,5650,10880,10076,7723,7455,10767,2485,3589,9021,
  9389,3007,7226,9195,6505,3065,10361,5118,7550,1706,6613,4665,10397,1555,7562,8711,
  6617,7000,6302,10526,6197,7605,6162,2535,2054,845,4781,4378,5690,9652,5993,11410,
  6094,11996,10224,8095,3408,10891,1136,11823,4475,3941,5588,5410,5959,9996,10179,3332,
  3393,5207,1131,5832,377,1944,4222,648,9600,216,3200,72,5163,24,1721,8,
  4670,4099,5653,9559,10077,11379,3359,3793,5216,9457,5835,11345,1945,7878,8841,2626,
  2947,9068,9175,7119,11251,2373,11943,791,3981,4360,1327,9646,8635,11408,11071,7899,
  11883,2633,3961,4974,9513,1658,3171,4649,1057,5646,8545,1882,11041,8820,11873,2940,
  8054,980,6781,4423,10453,9667,11677,11415,12085,3805,12221,9461,8170,7250,10916,6513,
  7735,2171,10771,4820,11783,5703,8024,1901,6771,4730,2257,5673,8945,1891,7078,8823,
  10552,2941,11710,9173,12096,7154,4032,6481,1344,10353,448,3451,8342,9343,6877,11307,
  10485,3769,3495,9449,1165,7246,8581,10608,11053,3536,11877,5275,3959,9951,5416,3317,
  9998,5202,7429,1734,10669,578,11749,4289,12109,5526,12229,1842,12269,614,8186,4301,
  6825,5530,2275,10036,8951,11538,7080,3846,2360,1282,4883,8620,5724,11066,1908,7785,
  636,2595,212,865,4167,8481,1389,2827,463,9135,8347,3045,10975,1015,11851,8531,
  12143,6940,8144,10506,6811,3502,10463,9360,7584,3120,2528,1040,4939,4443,9839,1481,
  7376,4590,6555,1530,2185,510,8921,170,7070,4153,6453,9577,2151,11385,717,3795,
  239,1265,4176,4518,1392,1506,464,502,4251,8360,1417,6883,8665,10487,11081,7592,
  7790,6627,6693,2209,2231,8929,4840,11169,9806,3723,7365,1241,2455,4510,9011,9696,
  7100,3232,6463,9270,10347,3090,3449,1030,5246,8536,5845,11038,10141,11872,11573,12150,
  7954,4050,10844,1350,7711,450,10763,150,7684,50,10754,4113,7681,1371,10753,457,]

hls_ram1_gammas_inv_montgomery = []
hls_ram2_gammas_inv_montgomery = []
for i in range(0, len(gammas_inv_montgomery), 2):
    hls_ram2_gammas_inv_montgomery.append( gammas_inv_montgomery[i] )
    hls_ram1_gammas_inv_montgomery.append( gammas_inv_montgomery[i+1] )

print(f"uint16_t hls_ram2_gammas_inv_montgomery[NEWHOPE_N/2]={hls_ram2_gammas_inv_montgomery}")
print(f"uint16_t hls_ram1_gammas_inv_montgomery[NEWHOPE_N/2]={hls_ram1_gammas_inv_montgomery}")


my_omegas_montgomery = [4075, 12097, 10561, 9026, 7500, 6055, 5339, 11184, 2344, 8807, 5529, 605, 5445, 12138, 10930, 58, 522, 4698, 5415, 11868, 8500, 2766, 316, 2844, 1018, 9162, 8724, 4782, 6171, 6383, 8291, 885, 7965, 10240, 6137, 6077, 5537, 677, 6093, 5681, 1973, 5468, 56, 504, 4536, 3957, 11035, 1003, 9027, 7509, 6136, 6068, 5456, 12237, 11821, 8077, 11248, 2920, 1702, 3029, 2683, 11858, 8410, 1956, 5315, 10968, 400, 3600, 7822, 8953, 6843, 142, 1278, 11502, 5206, 9987, 3860, 10162, 5435, 12048, 10120, 5057, 8646, 4080, 12142, 10966, 382, 3438, 6364, 8120, 11635, 6403, 8471, 2505, 10256, 6281, 7373, 4912, 7341, 4624, 4749, 5874, 3710, 8812, 5574, 1010, 9090, 8076, 11239, 2839, 973, 8757, 5079, 8844, 5862, 3602, 7840, 9115, 8301, 975, 8775, 5241, 10302, 6695, 11099, 1579, 1922, 5009, 8214, 192, 1728, 3263, 4789, 6234, 6950, 1105, 9945, 3482, 6760, 11684, 6844, 151, 1359, 12231, 11767, 7591, 6874, 421, 3789, 9523, 11973, 9445, 11271, 3127, 3565, 7507, 6118, 5906, 3998, 11404, 4324, 2049, 6152, 6212, 6752, 11612, 6196, 6608, 10316, 6821, 12233, 11785, 7753, 8332, 1254, 11286, 3262, 4780, 6153, 6221, 6833, 52, 468, 4212, 1041, 9369, 10587, 9260, 9606, 431, 3879, 10333, 6974, 1321, 11889, 8689, 4467, 3336, 5446, 12147, 11011, 787, 7083, 2302, 8429, 2127, 6854, 241, 2169, 7232, 3643, 8209, 147, 1323, 11907, 8851, 5925, 4169, 654, 5886, 3818, 9784, 2033, 6008, 4916, 7377, 4948, 7665, 7540, 6415, 8579, 3477, 6715, 11279, 3199, 4213, 1050, 9450, 11316, 3532, 7210, 3445, 6427, 8687, 4449, 3174, 3988, 11314, 3514, 7048, 1987, 5594, 1190, 10710, 10367, 7280]

hls_ram1_my_omegas_montgomery = []
hls_ram2_my_omegas_montgomery = []
for i in range(0, len(my_omegas_montgomery), 2):
    


# my_omegas_inv_montgomery = [4075, 7280, 10367, 10710, 1190, 5594, 1987, 7048, 3514, 11314, 3988, 3174, 4449, 8687, 6427, 3445, 7210, 3532, 11316, 9450, 1050, 4213, 3199, 11279, 6715, 3477, 8579, 6415, 7540, 7665, 4948, 7377, 4916, 6008, 2033, 9784, 3818, 5886, 654, 4169, 5925, 8851, 11907, 1323, 147, 8209, 3643, 7232, 2169, 241, 6854, 2127, 8429, 2302, 7083, 787, 11011, 12147, 5446, 3336, 4467, 8689, 11889, 1321, 6974, 10333, 3879, 431, 9606, 9260, 10587, 9369, 1041, 4212, 468, 52, 6833, 6221, 6153, 4780, 3262, 11286, 1254, 8332, 7753, 11785, 12233, 6821, 10316, 6608, 6196, 11612, 6752, 6212, 6152, 2049, 4324, 11404, 3998, 5906, 6118, 7507, 3565, 3127, 11271, 9445, 11973, 9523, 3789, 421, 6874, 7591, 11767, 12231, 1359, 151, 6844, 11684, 6760, 3482, 9945, 1105, 6950, 6234, 4789, 3263, 1728, 192, 8214, 5009, 1922, 1579, 11099, 6695, 10302, 5241, 8775, 975, 8301, 9115, 7840, 3602, 5862, 8844, 5079, 8757, 973, 2839, 11239, 8076, 9090, 1010, 5574, 8812, 3710, 5874, 4749, 4624, 7341, 4912, 7373, 6281, 10256, 2505, 8471, 6403, 11635, 8120, 6364, 3438, 382, 10966, 12142, 4080, 8646, 5057, 10120, 12048, 5435, 10162, 3860, 9987, 5206, 11502, 1278, 142, 6843, 8953, 7822, 3600, 400, 10968, 5315, 1956, 8410, 11858, 2683, 3029, 1702, 2920, 11248, 8077, 11821, 12237, 5456, 6068, 6136, 7509, 9027, 1003, 11035, 3957, 4536, 504, 56, 5468, 1973, 5681, 6093, 677, 5537, 6077, 6137, 10240, 7965, 885, 8291, 6383, 6171, 4782, 8724, 9162, 1018, 2844, 316, 2766, 8500, 11868, 5415, 4698, 522, 58, 10930, 12138, 5445, 605, 5529, 8807, 2344, 11184, 5339, 6055, 7500, 9026, 10561, 12097]