#include "FIRFilter.h"

FIRFilter::FIRFilter(int numElements)
	: elements(numElements)
{
	FilterMemory = new float[numElements];
	FilterCoefficients = new float[numElements];
}

FIRFilter::~FIRFilter(){}

void FIRFilter::AddCoefficient(int delay, float coefficient)
{
	if(delay > elements)
		return;

	FilterCoefficients[delay] = coefficient;
}