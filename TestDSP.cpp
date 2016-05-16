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

bool testPeakDetector()
{
	PeakValleyDetector peakDetector;

	bool passedTest = true;

	int sample1 = 2;
	int sample2 = 4;
	int sample3 = 7; // Peak
	int sample4 = 4;
	int sample5 = 0; // Valley
	int sample6 = 2;

	peakDetector.IsPeakCross(sample1);
	if(peakDetector.IsPeakCross(sample2)) 			{passedTest = false;}
	if(peakDetector.IsPeakCross(sample3)) 			{passedTest = false;}
	if(peakDetector.IsPeakCross(sample4) == false) 	{passedTest = false;}
	if(peakDetector.IsPeakCross(sample5)) 			{passedTest = false;}
	if(peakDetector.IsPeakCross(sample6)) 			{passedTest = false;}

	if(passedTest)
	{
		cout << "Passed Peak detection test" << endl;
	}
	else
	{
		cout << "Failed Peak detection test" << endl;
	}

	return passedTest;
}

bool testValleyDetector()
{
	PeakValleyDetector valleyDetector;

	bool passedTest = true;

	int sample1 = 2;
	int sample2 = 4;
	int sample3 = 7; // Peak
	int sample4 = 4;
	int sample5 = 0; // Valley
	int sample6 = 2;

	valleyDetector.IsValleyCross(sample1);
	valleyDetector.IsValleyCross(sample2);
	valleyDetector.IsValleyCross(sample3);
	valleyDetector.IsValleyCross(sample4);
	valleyDetector.IsValleyCross(sample5);
	valleyDetector.IsValleyCross(sample6);

	return passedTest;
}

int main (void)
{
	cout << "DSP Tests" << endl;
	
	testThresholdCommand();
	testDifferentiator();
	testZeroCrossDetector();
	testPeakDetector();
	
	return 0;
}