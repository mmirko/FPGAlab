#include "func.h"

ap_fixed<16,12> fix_sum(ap_fixed<16,12> a, ap_fixed<10,6> b) {
     #pragma HLS pipeline II=1
    return a + b;
}

ap_fixed<16,12,AP_TRN,AP_SAT> fix_sum_sat(ap_fixed<16,12,AP_TRN,AP_SAT> a, ap_fixed<10,6,AP_TRN,AP_SAT> b) {
    #pragma HLS pipeline II=1
    return a + b;
}