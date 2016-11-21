#include "FIRFilter.h"

FIRFilter::FIRFilter(int numElements)
	: elements(numElements)
{
	FilterMemory = new float[numElements];
	FilterCoefficients = new float[numElements];

	InitializeFilter();
}

FIRFilter::~FIRFilter(){}

void FIRFilter::InitializeFilter()
{
	for(int i = 0; i < elements; i++)
	{
		FilterMemory[i] = 0.0;
	}
}

void FIRFilter::AddCoefficient(int delay, float coefficient)
{
	if(delay > elements)
		return;

	FilterCoefficients[delay] = coefficient;
}