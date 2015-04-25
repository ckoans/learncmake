#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "TutorialConfig.h"

#include <cmath>
#include <limits>
#include <iomanip>
#include <type_traits>
#include <algorithm>

#ifdef USE_CUSTOM
#include "MathFunctions/custom.h"
#endif

template<class T>
typename std::enable_if<!std::numeric_limits<T>::is_integer, bool>::type
    almost_equal(T x, T y, int ulp)
{
    // the machine epsilon has to be scaled to the magnitude of the values used
    // and multiplied by the desired precision in ULPs (units in the last place)
    return std::abs(x-y) < std::numeric_limits<T>::epsilon() * std::abs(x+y) * ulp
    // unless the result is subnormal
           || std::abs(x-y) < std::numeric_limits<T>::min();
}

double sq_root(double x)
{
    double rt = 1, ort = 0;
    while(ort!=rt)
    {
        ort = rt;
        rt = ((x/rt) + rt) / 2;
    }
    return rt;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stdout, "%s Version %d.%d\n", argv[0], Tutorial_VERSION_MAJOR, Tutorial_VERSION_MINOR);
        fprintf(stdout, "Usage: %s number\n", argv[0]);
        return 1;
    }

    double inputValue = atof(argv[1]);
    double outputValue = 0;
    double one = 1.0;

    if (inputValue > 0) {
        if (almost_equal(inputValue, one, 10)) {
            outputValue = 1;
        } else {
            outputValue = sq_root(inputValue);
        }
    }

    fprintf(stdout, "The square root of %g is %f\n", inputValue, outputValue);

    #ifdef USE_CUSTOM
        double outputValue2 = timesTwo(inputValue);
        fprintf(stdout, "Multiplying %g by 2 gives us %g\n", inputValue, outputValue2);
    #endif

    return 0;
}
