#include "func.h"

#include <iostream>

#define N 256

// void vec_add(int a[N], int b[N], int c[N]);

int main() {

    int a[N];
    int b[N];
    int c[N];
    int expected[N];

    for (int i = 0; i < N; i++) {
        a[i] = i;
        b[i] = 100 + i;
        expected[i] = a[i] + b[i];
    }

    vec_add(a, b, c);

    int errors = 0;

    std::cout << "a\tb\tc\tref\n";

    for (int i = 0; i < N; i++) {

        std::cout
            << a[i] << "\t"
            << b[i] << "\t"
            << c[i] << "\t"
            << expected[i];

        if (c[i] != expected[i]) {
            errors++;
            std::cout << "  ERROR";
        }

        std::cout << std::endl;
    }

    if (errors == 0) {
        std::cout << "\nTEST PASSED" << std::endl;
    } else {
        std::cout << "\nTEST FAILED : " << errors
                  << " errors" << std::endl;
    }

    return errors;
}