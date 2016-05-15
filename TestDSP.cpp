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

int main (void)
{
	cout << "DSP Tests" << endl;
	
	testThresholdCommand();
	testDifferentiator();
	
	return 0;
}