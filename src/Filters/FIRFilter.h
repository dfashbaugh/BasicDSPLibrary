class FIRFilter{
public:
	FIRFilter(int numElements);
	~FIRFilter();

private:
	float* FilterMemory;
	float* FilterCoefficients;
};