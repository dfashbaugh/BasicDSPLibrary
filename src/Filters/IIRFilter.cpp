#include "IIRFilter.h"

IIRFilter::IIRFilter(int numElementsInput, int numElementsOutput)
	: elementsInput(numElementsInput)
	, elementsOutput(numElementsOutput)
{
	FilterMemoryInput = new float[elementsInput];
	FilterCoefficientsInput = new float[elementsInput];
	FilterMemoryOutput = new float[elementsOutput];
	FilterCoefficientsOutput = new float[elementsOutput];
}

void IIRFilter::InitializeFilter()
{
	for(int i = 0; i < elementsInput; i++)
	{
		FilterMemoryInput[i] = 0.0;
	}

	for(int i = 0; i < elementsOutput; i++)
	{
		FilterMemoryOutput[i] = 0.0;
	}
}