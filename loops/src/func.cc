#include <ap_int.h>

#define N 16

void vec_add(int a[N], int b[N], int c[N]) {

// #pragma HLS INTERFACE mode=s_axilite port=return
// #pragma HLS INTERFACE mode=m_axi bundle=gmem0 port=a
// #pragma HLS INTERFACE mode=m_axi bundle=gmem1 port=b
// #pragma HLS INTERFACE mode=m_axi bundle=gmem2 port=c

loop_add:
    for (int i = 0; i < N; i++) {

        // #pragma HLS PIPELINE
        // #pragma HLS PIPELINE II=1
        #pragma HLS UNROLL
        // #pragma HLS UNROLL factor=4

        c[i] = a[i] + b[i];
    }
}