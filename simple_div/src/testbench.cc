#include "div.h"
#include <cstdio>
#include <cstdlib>

int main() {
    srand(125);
    for (unsigned int itest = 0, ntest = 20; itest <= ntest; ++itest) {
        ap_int<16> a = (rand() & 0xFFF);
        ap_int<16> b = (rand() & 0xFF);

        printf("a = %d, b = %d, ", a.to_int(), b.to_int());
        bool ok = true;

        ap_int<16> div_exp = a / b;
        ap_int<16> div_fw = div(a, b);
        printf(" div = %d (expected %d), %s\n", div_fw.to_int(), div_exp.to_int(), div_fw == div_exp ? " ok " : "fail");
        ok = ok && (div_fw == div_exp);

        if (!ok) return 1;
    }
    return 0;
}
