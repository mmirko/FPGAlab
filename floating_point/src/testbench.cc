#include "functions.h"
#include <cstdio>
#include <cstdlib>

int main() {
    srand(125);
    for (unsigned int itest = 0, ntest = 20; itest <= ntest; ++itest) {
        float a = static_cast<float>(rand() & 0xFFF);
        float b = static_cast<float>(rand() & 0xFF);

        printf("a = %f, b = %f, ", a, b);
        bool ok = true;

        float sum_exp = a + b;
        float sum_fw = sum(a, b);
        printf(" sum = %f (expected %f), %s\n", sum_fw, sum_exp, sum_fw == sum_exp ? " ok " : "fail");
        ok = ok && (sum_fw == sum_exp);

        if (!ok) return 1;
    }
    return 0;
}
