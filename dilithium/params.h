#ifndef PARAMS_H
#define PARAMS_H

enum OPERATION {FORWARD_NTT_MODE, INVERSE_NTT_MODE, MUL_MODE};
enum MAPPING {DECODE_TRUE, DECODE_FALSE, ENCODE_TRUE, ENCODE_FALSE};

#define DILITHIUM_SEEDBYTES 32
#define DILITHIUM_CRHBYTES 64
#define DILITHIUM_N 256
#define DILITHIUM_LOGN 8
#define DILITHIUM_Q 8380417 // 2**23 - 2**13 + 1
#define DILITHIUM_D 13
#define DILITHIUM_ROOT_OF_UNITY 1753
#define DILITHIUM_2NDROOT_OF_UNITY 2217225

#if DILITHIUM_MODE == 2
#define DILITHIUM_K 4
#define DILITHIUM_L 4
#define DILITHIUM_ETA 2
#define DILITHIUM_TAU 39
#define DILITHIUM_BETA 78
#define DILITHIUM_GAMMA1 (1 << 17)
#define DILITHIUM_GAMMA2 ((Q-1)/88)
#define DILITHIUM_OMEGA 80

#elif DILITHIUM_MODE == 3
#define DILITHIUM_K 6
#define DILITHIUM_L 5
#define DILITHIUM_ETA 4
#define DILITHIUM_TAU 49
#define DILITHIUM_BETA 196
#define DILITHIUM_GAMMA1 (1 << 19)
#define DILITHIUM_GAMMA2 ((Q-1)/32)
#define DILITHIUM_OMEGA 55

#elif DILITHIUM_MODE == 5
#define DILITHIUM_K 8
#define DILITHIUM_L 7
#define DILITHIUM_ETA 2
#define DILITHIUM_TAU 60
#define DILITHIUM_BETA 120
#define DILITHIUM_GAMMA1 (1 << 19)
#define DILITHIUM_GAMMA2 ((Q-1)/32)
#define DILITHIUM_OMEGA 75

#endif

#define POLYT1_PACKEDBYTES  320
#define POLYT0_PACKEDBYTES  416
#define POLYVECH_PACKEDBYTES (OMEGA + K)

#if GAMMA1 == (1 << 17)
#define POLYZ_PACKEDBYTES   576
#elif GAMMA1 == (1 << 19)
#define POLYZ_PACKEDBYTES   640
#endif

#if GAMMA2 == (Q-1)/88
#define POLYW1_PACKEDBYTES  192
#elif GAMMA2 == (Q-1)/32
#define POLYW1_PACKEDBYTES  128
#endif

#if ETA == 2
#define POLYETA_PACKEDBYTES  96
#elif ETA == 4
#define POLYETA_PACKEDBYTES 128
#endif

#define CRYPTO_PUBLICKEYBYTES (SEEDBYTES + K*POLYT1_PACKEDBYTES)
#define CRYPTO_SECRETKEYBYTES (3*SEEDBYTES \
                               + L*POLYETA_PACKEDBYTES \
                               + K*POLYETA_PACKEDBYTES \
                               + K*POLYT0_PACKEDBYTES)
#define CRYPTO_BYTES (SEEDBYTES + L*POLYZ_PACKEDBYTES + POLYVECH_PACKEDBYTES)

#endif
