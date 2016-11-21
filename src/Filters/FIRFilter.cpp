#include "FIRFilter.h"

FIRFilter::FIRFilter(int numElements)
{
	FilterMemory = new float[numElements];
	FilterCoefficients = new float[numElements];
}

FIRFilter::~FIRFilter(){}