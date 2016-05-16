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
	ZeroCrossDetector(bool startFromAbove) 	{fromAbove = startFromAbove;};
	~ZeroCrossDetector() {};

	bool IsZeroCross(int curSample);
};
