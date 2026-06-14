#include "functions.h"
#include <cstdio>
#include <cstdlib>

int main() {
    srand(125);
    for (unsigned int itest = 0, ntest = 20; itest <= ntest; ++itest) {
        double a = static_cast<double>(rand() & 0xFFF);
        double b = static_cast<double>(rand() & 0xFF);

        printf("a = %f, b = %f, ", a, b);
        bool ok = true;

        double sum_exp = a + b;
        double sum_fw = sum(a, b);
        printf(" sum = %f (expected %f), %s\n", sum_fw, sum_exp, sum_fw == sum_exp ? " ok " : "fail");
        ok = ok && (sum_fw == sum_exp);

        if (!ok) return 1;
    }
    return 0;
}
