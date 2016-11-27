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