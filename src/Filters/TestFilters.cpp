#include "FIRFilter.h"
#include <iostream>

using namespace std;

void CheckFIRImpulseResponse()
{
	FIRFilter myFilter(10);
	myFilter.AddCoefficient(0, 0.1);
	myFilter.AddCoefficient(1, 2);
	myFilter.AddCoefficient(2, 0.7);
	myFilter.AddCoefficient(3, 0.6);
	myFilter.AddCoefficient(4, 2);
	myFilter.AddCoefficient(5, 0.8);
	myFilter.AddCoefficient(6, 0.4);
	myFilter.AddCoefficient(7, 0.5);
	myFilter.AddCoefficient(8, 2);
	myFilter.AddCoefficient(9, 0.9);

	cout << myFilter.StepFilter(1) << endl;

	for(int i = 0; i < 20; i++)
	{
		cout << myFilter.StepFilter(0) << endl;
	}
}

int main(void)
{
	cout << "Working " << endl;

	CheckFIRImpulseResponse();
}