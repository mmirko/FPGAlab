#include "func.h"

ap_int<24> sum_or_mul(bool want_sum, ap_int<16> a, ap_int<10> b) {
    // #pragma HLS pipeline II=1
    return want_sum ? ap_int<24>(a + b) : ap_int<24>(a * b);
}