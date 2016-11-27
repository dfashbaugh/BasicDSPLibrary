class IIRFilter{
public:
	IIRFilter(int numElementsInput, int numElementsOutput);
	~IIRFilter() {};

	void InitializeFilter();

	void AddInputCoefficient(int delay, float value);
	void AddOutputCoefficient(int delay, float value);

private:
	float* FilterMemoryInput;
	float* FilterMemoryOutput;
	float* FilterCoefficientsInput;
	float* FilterCoefficientsOutput;
	int elementsInput;
	int elementsOutput;
};