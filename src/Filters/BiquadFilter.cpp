#include <math.h>
#include "BiquadFilter.h"

BiquadFilter::BiquadFilter(void)
    : mCornerFrequency  (0.0)
    , mSampleRate       (0.0)
    , mQualityFactor    (0.0)
    , mB0               (0.0)
    , mB1               (0.0)
    , mB2               (0.0)
    , mA1               (0.0)
    , mA2               (0.0)
    , mYm1              (0.0)
    , mYm2              (0.0)
    , mXm1              (0.0)
    , mXm2              (0.0)
{
}

BiquadFilter::BiquadFilter(filterType filter, double sampleFrequency, double cornerFrequency, double qualityFactor)
{
	BiquadFilter();
	GenerateCoefficients(filter, sampleFrequency, cornerFrequency, qualityFactor);
}

BiquadFilter::~BiquadFilter(void)
{
}

double BiquadFilter::FeedValue(double inputValue)
{
    double curOutput = 0.0;

    curOutput = inputValue*mB0 + mXm1*mB1 + mXm2*mB2 - mYm1*mA1 - mYm2*mA2;

    mYm2 = mYm1;
    mYm1 = curOutput;
    mXm2 = mXm1;
    mXm1 = inputValue;

    return curOutput;
}

void BiquadFilter::GenerateCoefficients(filterType filter, double sampleFrequency, double cornerFrequency, double qualityFactor)
{
    double b0;
    double b1;
    double b2;
    double a0;
    double a1;
    double a2;
    mQualityFactor = qualityFactor;
    double omegaC = (cornerFrequency/sampleFrequency)*2*M_PI;
    double alpha = sin(omegaC)/(2*mQualityFactor);

    if(filter == lowpass)
    {
        b0 = (1-cos(omegaC))/2;
        b1 =  1-cos(omegaC);
        b2 =  b0;
        a0 =  1+alpha;
        a1 = -2*cos(omegaC);
        a2 =  1-alpha;

        mB0 = b0/a0;
        mB1 = b1/a0;
        mB2 = b2/a0;
        mA1 = a1/a0;
        mA2 = a2/a0;
    }
    else if(filter == bandpass)
    {
        b0 = mQualityFactor*alpha;
        b1 = 0;
        b2 = -1*mQualityFactor*alpha;
        a0 = 1+alpha;
        a1 = -2*cos(omegaC);
        a2 = 1-alpha;

        mB0 = b0/a0;
        mB1 = b1/a0;
        mB2 = b2/a0;
        mA1 = a1/a0;
        mA2 = a2/a0;
    }
    else // High Pass
    {
        b0 = (1+cos(omegaC))/2;
        b1 = -1*(1+cos(omegaC));
        b2 = (1+cos(omegaC))/2;
        a0 = 1+alpha;
        a1 = -2*cos(omegaC);
        a2 = 1-alpha;

        mB0 = b0/a0;
        mB1 = b1/a0;
        mB2 = b2/a0;
        mA1 = a1/a0;
        mA2 = a2/a0;
    }
}