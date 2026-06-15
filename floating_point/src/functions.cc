#include "functions.h"

float sum(float a, float b) {
	#pragma HLS pipeline no
    	return a+b;
}

float mult(float a, float b) {
	#pragma HLS pipeline no
    	return a*b;
}

