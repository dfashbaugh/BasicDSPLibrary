#include "BasicDSP.h"

bool IsThresholdExceeded(int threshold, int curSample)
{
	return curSample > threshold;
}