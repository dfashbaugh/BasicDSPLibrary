/******************************************************************************
* Using the Biquad Filter
* 
* 1.) Create a BIquadFilter_t object
* 2.) Call GenerateCoefficients() with the following data as arguments
*       a.) Filter Type - lowpass, bandpass, or highpass
*       b.) Sample Frequency (in Hz)
*       c.) Corner Frequency (in Hz)
*       d.) Quality Factor (Default is 0.707)
* 3.) Send your input in FeedValue(), the output is returned.
*
* Note: This filter is used for streaming data. It will take in one value 
*       and return one value. Since this is IIR, the filter expects that 
*       new data is from the same set as old data.
*******************************************************************************/

#include <math.h>

class BiquadFilter
{
public:
    enum filterType {lowpass, bandpass, highpass};

    BiquadFilter(void);
	BiquadFilter(filterType filter, double sampleFrequency, double cornerFrequency, double qualityFactor = 0.707);
    ~BiquadFilter(void);

    void   		GenerateCoefficients(filterType filter, double sampleFrequency, double cornerFrequency, double qualityFactor = 0.707); 
    
    double      FeedValue(double curInput); 

private:

    double mCornerFrequency;
    double mSampleRate;
    double mQualityFactor;
    double mB0;
    double mB1;
    double mB2;
    double mA1;
    double mA2;

    double mYm1; //y[n-1]
    double mYm2; //y[n-2]
    double mXm1; //x[n-1]
    double mXm2; //x[n-2]

};