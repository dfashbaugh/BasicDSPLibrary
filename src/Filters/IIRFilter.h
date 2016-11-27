class IIRFilter{
public:
	IIRFilter(int numElementsInput, int numElementsOutput);
	~IIRFilter() {};

private:
	float* FilterMemoryInput;
	float* FilterMemoryOutput;
	float* FilterCoefficientsInput;
	float* FilterCoefficientsOutput;
	int elementsInput;
	int elementsOutput;
};