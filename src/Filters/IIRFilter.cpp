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

void IIRFilter::AddInputCoefficient(int delay, float value)
{
	if(delay >= elementsInput)
		return;

	FilterCoefficientsInput[delay] = value;
}

void IIRFilter::AddOutputCoefficient(int delay, float value)
{
	if(delay >= elementsOutput)
		return;

	FilterCoefficientsOutput[delay] = value;
}

float IIRFilter::StepFilter(float input)
{
	float inputOut = 0.0;
	if(elementsInput < 1)
	{
		inputOut = input;
	}
	else
	{
		float curTransfer = FilterMemoryInput[0];
		float nextTransfer = curTransfer;
		for(int i = 1; i < elementsInput; i++)
		{
			curTransfer = nextTransfer;
			nextTransfer = FilterMemoryInput[i];
			FilterMemoryInput[i] = curTransfer;
			curTransfer = FilterMemoryInput[i];
		}

		FilterMemoryInput[0] = input;

		for(int i = 0; i < elementsInput; i++)
		{
			inputOut += FilterMemoryInput[i]*FilterCoefficientsInput[i];
		}
	}

	float outputOut = 0.0;
	if(elementsOutput >= 1)
	{
		float curTransfer = FilterMemoryOutput[0];
		float nextTransfer = curTransfer;
		for(int i = 1; i < elementsOutput; i++)
		{
			curTransfer = nextTransfer;
			nextTransfer = FilterMemoryOutput[i];
			FilterMemoryOutput[i] = curTransfer;
			curTransfer = FilterMemoryOutput[i];
		}

		for(int i = 0; i < elementsOutput; i++)
		{
			outputOut += FilterMemoryOutput[i]*FilterCoefficientsOutput[i];
		}
	}

	float output = inputOut + outputOut;

	FilterMemoryOutput[0] = output;


	return output;
}