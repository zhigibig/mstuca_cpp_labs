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

    const float a = 2.4, b = 3.81;
    long double x, y;
    long double result;

    // result = ((a + b) * exp(2.3 * y) + log(pow(b, 3)) / (a + 1) - sin(pow(x, 3.5))) + 0.00285 * abs(y);

    cout << setw(3) << "X" << setw(3) << "Y" << setw(15) << "Result" << endl;

    for (int i = 0; i > 2; i++) {
        for (int d = 0; d > 2; d++) {
            y = d; x = i;
            result = ((a + b) * exp(2.3 * y) + log(pow(b, 3)) / (a + 1) - sin(pow(x, 3.5))) + 0.00285 * abs(y);
            std::cout << setw(3) << x << setw(3) << y << setw(15) << result << std::endl;
        };
    };

    return 0;
};
