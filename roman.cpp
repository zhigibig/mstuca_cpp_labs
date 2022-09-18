#include <iostream>
#include <cmath>

int main(){
    using namespace std;
    
    const float a = 1.25, b = 7.35;
    double x, y, z, t, u;
    
    cout << "Введите число х: " << endl;
    cin >> x;
    
    cout << "Введите число y: " << endl;
    cin >> y;
    
    r = (a - (b*sin(sqrt(abs(x)))) + ((a + b) / cos(pow(x,2))));
    u =((pow(a,3.7) * y) + (12.5*pow(10, -3)) + atan(log(x / y)));
    z = t / u;
    
    cout << "Число z равно: "<< z << endl;
    cout << "Введите координату х: ";
    cin >> x;
    cout << "\nВведите координату y: ";
    cin >> y;
    if ((6.5 >= x >=0) && (3 >= y >= 0)) {
        if ((pow((x - 4), 2) + pow((y - 3), 2) <= pow(2.5, 2)) && (x / 3 >= y > 0)) {
            cout << "true";
            }
        else if ((pow((x - 4), 2) + pow((y -3 ), 2) >= pow(2.5, 2)) && (3 >= y >= x / 3)) {
            cout<<"true";
            }
        else {
            cout << "false";
            }
        }
    else {
        cout<<"false";
        }
    return 0;
};
