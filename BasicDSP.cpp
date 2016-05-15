#include "BasicDSP.h"

bool IsThresholdExceeded(int threshold, int curSample)
{
	return curSample > threshold;
}

int Differentiator::CalculateDerivative(int curSample)
{	
	int derivative = curSample - lastSample;
	lastSample = curSample;
	return derivative;
}