#include "func.h"

ap_int<24> mul_add(const ap_int<16> a[NDATA], const ap_int<16> b[NDATA]) {
//    #pragma HLS pipeline II=1
//    #pragma HLS array_partition variable=a complete
//    #pragma HLS array_partition variable=b complete
    ap_int<24> sum = 0;
    for (unsigned int i = 0; i < NDATA; ++i) {
//        #pragma HLS unroll
        ap_int<24> prod = (a[i] * b[i]) >> 8;
        sum += prod;
    }
    return sum;
}
