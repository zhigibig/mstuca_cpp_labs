#include <iostream>
#include <cmath>
#include <iomanip>


int main() {
    using namespace std;

    /* Требуется вычислить
                    2,3*y        3
        (a + b) * e^      + lg b^                      -3
    z = ---------------------------  + 2,85 * |y| * 10^
           a + 1 - sin( x^(7/2))
    */

    const float A = 2.4, B = 3.81;
    long double var1, var2; 
    long double result;

    for (var1 = 0; var1 < 3; var1++) {
        for (var2 = 0; var2 < 3; var2++) {
            result = ((A + B) * exp(2.3 * var2) + log(pow(B, 3)) / (A + 1) - sin(pow(var1, 3.5))) + 0.00285 * abs(var2);
            std::cout << setw(3) << var1 << setw(3) << var2 << setw(15) << result << std::endl;
        };
    };

    return 0;
};
