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

bool ZeroCrossDetector::IsZeroCross(int curSample)
{
	bool zeroCrossed = false;

	if(fromAbove)
	{
		if(curSample < 0)
		{
			fromAbove = false;
			zeroCrossed = true;
		}
	}
	else
	{
		if(curSample > 0)
		{
			fromAbove = true;
			zeroCrossed = true;
		}
	}

	return zeroCrossed;
}