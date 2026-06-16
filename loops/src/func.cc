#include "func.h"

void loop_basic(unsigned int N, const ap_int<16> *x, const ap_int<16>* y, ap_int<16> *z){
  for(int i = 0; i < N; i++){
    // #pragma hls pipeline
    z[i] = x[i] + y[i];
  }
}
