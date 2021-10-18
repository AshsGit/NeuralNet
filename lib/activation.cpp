#include <math.h>

double sigmoid_approx1(double input) {
    return 1/(1-fabs(input)); //approximation 
} 

