#include <iostream> 
#include <cmath> 
#include <iomanip> 

bool enterance_checking(long double var1, long double var2) {
    if (var1 < 0 || var2 < 0) {
        return false;
    } else if (var1 <= 1 && var2 <= 1) {
        return true;
    } else if ( (var1 <= 2) && (var2 <= 1.5) ) {
        return true;
    } else {
        return false;
    };
};

int main() {
    using namespace std;

    /* Требуется вычислить

        (a + b) * e^2,3*y     + lg b^3               
    z = ---------------------------  + 2,85 * |y| * 10^-3
           a + 1 - sin( x^(7/2))
           
    */

    const float a = 2.4, b = 3.81;
    long double x, y; 
    long double result;
    string enterance_check_res;

    cout << setw(6) << "X" << setw(6) << "Y" << setw(10) << "Result" << setw(13) << "Graph ent" << "\n" << endl;

    for (x = -3; x <= 3; x += 0.5) {
        for (y = 0-3; y <= 3; y += 0.5) {
            result = ((a + b) * exp(2.3 * y) + log(pow(b, 3)) / (a + 1) - sin(pow(x, 3.5))) + 0.00285 * abs(y);

            if ( enterance_checking(x, y) == 1 ) {
                enterance_check_res = "true";
            } else {
                enterance_check_res = "false";
            };

            cout << setw(6) << x << setw(6) << y << setw(10) << result << setw(13) << enterance_check_res << endl;

        };
    };

    return 0;
};
