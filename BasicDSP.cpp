#include "BasicDSP.h"
#include <iostream>

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

bool PeakValleyDetector::IsPeakCross(int curSample)
{
	bool detectedZeroCross = StepDetector(curSample);

	if(theZeroCrossDetector.fromAbove == false)
	{
		return detectedZeroCross;
	}

	return false;
}

bool PeakValleyDetector::IsValleyCross(int curSample)
{
	bool detectedZeroCross = StepDetector(curSample);

	if(theZeroCrossDetector.fromAbove == true)
	{
		return detectedZeroCross;
	}
	
	return false;
}

bool PeakValleyDetector::StepDetector(int curSample)
{
	int differentiatedSample = theDifferentiator.CalculateDerivative(curSample);
	return theZeroCrossDetector.IsZeroCross(differentiatedSample);
}