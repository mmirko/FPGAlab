#include "mult.h"
#include <cstdio>
#include <cstdlib>

int main() {
    srand(125);
    for (unsigned int itest = 0, ntest = 20; itest <= ntest; ++itest) {
        ap_int<16> a = (rand() & 0xFFF);
        ap_int<16> b = (rand() & 0xFF);

        printf("a = %d, b = %d, ", a.to_int(), b.to_int());
        bool ok = true;

        ap_int<16> prod_exp = a * b;
        ap_int<16> prod_fw = mult(a, b);
        printf(" mult = %d (expected %d), %s\n", prod_fw.to_int(), prod_exp.to_int(), prod_fw == prod_exp ? " ok " : "fail");
        ok = ok && (prod_fw == prod_exp);

        if (!ok) return 1;
    }
    return 0;
}
