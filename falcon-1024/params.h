#ifndef PARAMS_H
#define PARAMS_H

enum OPERATION {FORWARD_NTT_MODE, INVERSE_NTT_MODE, MUL_MODE};
enum MAPPING {DECODE_TRUE, DECODE_FALSE, ENCODE_TRUE, ENCODE_FALSE};

#define FALCON_Q 12289 // 2**13 + 2**12 + 1
#define FALCON_Q0I 12287

// This directory support FALCON_MODE == [0, 5]
#define FALCON_MODE 5


#if FALCON_MODE == 0
#define FALCON_LOGN 8
#define FALCON_N 256

#elif FALCON_MODE == 1
#define FALCON_LOGN 9
#define FALCON_N 512

#elif FALCON_MODE == 5
#define FALCON_LOGN 10
#define FALCON_N 1024

#endif


#endif
