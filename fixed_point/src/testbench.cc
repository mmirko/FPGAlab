#include "func.h"
#include <cstdio>
#include <cstdlib>

int main() {
    srand(125);
    for (unsigned int itest = 0, ntest = 20; itest <= ntest; ++itest) {
        ap_int<16> a = (rand() & 0xFFF);
        ap_int<10> b = (rand() & 0xFF);
        bool want_sum = rand() & 1;
        printf("test %d: a = %d, b = %d, want_sum = %d:\n",
            itest,
            a.to_int(),
            b.to_int(),
            int(want_sum));

        bool ok = true;

        // fixed precision numbers with 4 decimal bits (i.e. LSB=2^-4 = 0.0625)
        ap_fixed<16,12> afix;
        ap_fixed<10,6> bfix;
        // copy the bits from a and b
        afix(15,0) = a(15,0);
        bfix(9,0) = b(9,0);
        // print out the numbers
        printf("fixed point a = %.4f (expected %.4f), b = %.4f (expected %.4f):\n",
            itest,
            afix.to_float(), a.to_int() * 0.0625,
            bfix.to_float(), b.to_int() * 0.0625);

        ap_fixed<16,12> sum_fix_ref = afix + bfix;
        ap_fixed<16,12> sum_fix_fw = fix_sum(afix, bfix);
        printf(" - fix_sum = %.4f (expected %.4f), %s\n", 
            sum_fix_fw.to_float(), sum_fix_ref.to_float(), 
            sum_fix_fw == sum_fix_ref ? " ok " : "FAIL");
        ok = ok && (sum_fix_fw == sum_fix_ref);

        ap_fixed<16,12,AP_TRN,AP_SAT> asat = afix;
        ap_fixed<10,6,AP_TRN,AP_SAT> bsat = bfix;
        printf("fixed point a = %.4f (expected %.4f), b = %.4f (expected %.4f):\n",
            itest,
            asat.to_float(), a.to_int() * 0.0625,
            asat.to_float(), b.to_int() * 0.0625);

        ap_fixed<16,12,AP_TRN,AP_SAT> sum_sat_ref = asat + bsat;
        ap_fixed<16,12,AP_TRN,AP_SAT> sum_sat_fw = fix_sum_sat(asat, bsat);
        printf(" - fix_sum_sat = %.4f (expected %.4f), %s\n", 
            sum_sat_fw.to_float(), sum_sat_ref.to_float(), 
            sum_sat_fw == sum_sat_ref ? " ok " : "FAIL");
        ok = ok && (sum_sat_fw == sum_sat_ref);

        if (!ok) return 1;
        printf("\n");
    }
    return 0;
}
