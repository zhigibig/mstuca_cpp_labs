#include <iostream> 
#include <cmath> 
#include <iomanip> 

bool entrance_checking(long double, long double);

int main() {
    using namespace std;

    /* Требуется вычислить

        (a + b) * e^2,3*y     + lg b^3               
    z = ---------------------------  + 2,85 * |y| * 10^-3
           a + 1 - sin( x^(7/2))

    
    Обозначения в программе 
    z = result 
    a = a
    b = b
    x = x
    y = y
    */

    const float a = 2.4, b = 3.81;
    long double x, y; 
    long double result;
    string enterance_check_res;

    cout << setw(6) << "X" << setw(6) << "Y" << setw(10) << "Result" << setw(13) << "Graph ent" << "\n" << endl;

    for (x = -1; x <= 2.5; x += 1) {
        for (y = -1; y <= 2.5; y += 1) {
            result = ((a + b) * exp(2.3 * y) + log(pow(b, 3)) / (a + 1) - sin(pow(x, 3.5))) + 0.00285 * abs(y);

            if ( entrance_checking(x, y) == 1 ) {
                enterance_check_res = "true";
            } else {
                enterance_check_res = "false";
            };

            cout << setw(6) << x << setw(6) << y << setw(10) << result << setw(13) << enterance_check_res << endl;

        };
    };

    return 0;
};

bool entrance_checking(long double posX, long double posY) {
    if (posX < 0 || posY < 0) {
        return false;
    };

    if (posX <= 1 && posY <= 1) {
        return true;
    };

    if ( (posX <= 2) && (posY <= 1.5) ) {
        return true;
    };

    return false;
};
