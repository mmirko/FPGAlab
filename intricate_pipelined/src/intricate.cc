#include "intricate.h"

ap_int<16> multiply(ap_int<16> a, ap_int<16> b) {
	#pragma HLS pipeline II=1	
    	return a*b;
}

ap_int<16> intricate(ap_int<16> a, ap_int<16> b) {
	#pragma HLS pipeline II=1
    	return a+multiply(a, multiply(b, b - 1));
}
