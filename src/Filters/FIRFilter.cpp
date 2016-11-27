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

float FIRFilter::StepFilter(float input)
{
	if(elements < 1)
		return 0.0;

	float output = 0.0;


	float curTransfer = FilterMemory[0];
	float nextTransfer = curTransfer;
	for(int i = 1; i < elements; i++)
	{
		curTransfer = nextTransfer;
		nextTransfer = FilterMemory[i];
		FilterMemory[i] = curTransfer;
		curTransfer = FilterMemory[i];
	}

	FilterMemory[0] = input;

	for(int i = 0; i < elements; i++)
	{
		output += FilterMemory[i]*FilterCoefficients[i];
	}

	return output;
}