#include "func.h"
#include <cstdio>
#include <cstdlib>

int main() {
    srand(125);
    for (unsigned int itest = 0, ntest = 20; itest <= ntest; ++itest) {
        ap_int<16> a = (rand() & 0xFFF);
        ap_int<10> b = (rand() & 0xFF);

        printf("a = %d, b = %d, ", a.to_int(), b.to_int());
        bool ok = true;

        ap_int<24> sum_exp = a + b;
        ap_int<24> mul_exp = a * b;
        ap_int<24> sum_fw = sum_or_mul(true, a, b);
        ap_int<24> mul_fw = sum_or_mul(false, a, b);
        printf(" sum = %d (expected %d), %s\n", sum_fw.to_int(), sum_exp.to_int(), sum_fw == sum_exp ? " ok " : "fail");
        printf(" mul = %d (expected %d), %s\n", mul_fw.to_int(), mul_exp.to_int(), mul_fw == mul_exp ? " ok " : "fail");
        ok = ok && (sum_fw == sum_exp) && (mul_fw == mul_exp);

        if (!ok) return 1;
    }
    return 0;
}
