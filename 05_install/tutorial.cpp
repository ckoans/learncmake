#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "TutorialConfig.h"

#ifdef USE_CUSTOM
#include "MathFunctions/custom.h"
#endif

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stdout, "%s Version %d.%d\n", argv[0], Tutorial_VERSION_MAJOR, Tutorial_VERSION_MINOR);
        fprintf(stdout, "Usage: %s number\n", argv[0]);
        return 1;
    }
    double inputValue = atof(argv[1]);
    double outputValue = sqrt(inputValue);

    fprintf(stdout, "The square root of %g is %g\n", inputValue, outputValue);

    #ifdef USE_CUSTOM
        double outputValue2 = timesTwo(inputValue);
        fprintf(stdout, "Multiplying %g by 2 gives us %g\n", inputValue, outputValue2);
    #endif

    return 0;
}
