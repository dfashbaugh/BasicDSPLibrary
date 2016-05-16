// Returns true if threshold is less than curSample.. 
bool IsThresholdExceeded (int threshold, int curSample);

// Differentiator Class creates a persistent derivative of the inputs
class Differentiator
{
public:
	int lastSample;

	Differentiator() 	{lastSample = 0;};
	~Differentiator() 	{};

	int CalculateDerivative(int curSample);
};

class ZeroCrossDetector
{
public:
	bool fromAbove;

	ZeroCrossDetector() 					{fromAbove = false;};
	~ZeroCrossDetector() {};

	bool IsZeroCross(int curSample);
};

class PeakValleyDetector
{
public:
	Differentiator 		theDifferentiator;
	ZeroCrossDetector 	theZeroCrossDetector;

	PeakValleyDetector() {};
	~PeakValleyDetector(){};

	bool IsPeakCross(int curSample);
	bool IsValleyCross(int curSample);
};