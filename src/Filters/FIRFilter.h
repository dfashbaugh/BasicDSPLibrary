class FIRFilter{
public:
	FIRFilter(int numElements);
	~FIRFilter();

	void AddCoefficient(int delay, float coefficient);

	void InitializeFilter();

	float StepFilter(float input);

private:
	float* FilterMemory;
	float* FilterCoefficients;
	int elements;
};