#include <iostream>
#include "BiquadFilter.h"
#include "BasicDSP.h"

using namespace std;

bool testThresholdCommand()
{
	if(IsThresholdExceeded(100, 101))
	{
		cout << "Passed Threshold Command" << endl;
		return true;
	}
		
	cout << "Failed Threshold Command" << endl;
	return false;
}

bool testDifferentiator()
{
	Differentiator derivative;

	int sample1 = 2;
	int sample2 = 3;

	if(derivative.CalculateDerivative(sample1) == 2)
	{
		if(derivative.CalculateDerivative(sample2) == 1)
		{
			cout << "Passed Differentiator Command" << endl;;
			return true;
		}
	}

	cout << "Failed Differentiator Command" << endl;;
	return false;
}

bool testZeroCrossDetector()
{
	ZeroCrossDetector detector;

	bool passedTest = true;

	int sample1 = 2;
	int sample2 = 3;
	int sample3 = -2;
	int sample4 = 1;

	if(detector.IsZeroCross(sample1) == false)
		passedTest = false;
	if(detector.IsZeroCross(sample2) == true)
		passedTest = false;
	if(detector.IsZeroCross(sample3) == false)
		passedTest = false;
	if(detector.IsZeroCross(sample4) == false)
		passedTest = false;

	if(passedTest)
		cout << "Passed Zero Cross Test" << endl;
	else
		cout << "Failed Zero Cross Test" << endl;

	return passedTest;
}

int main (void)
{
	cout << "DSP Tests" << endl;
	
	testThresholdCommand();
	testDifferentiator();
	testZeroCrossDetector();
	
	return 0;
}