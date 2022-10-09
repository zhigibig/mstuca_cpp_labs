#include <iostream>

int main() {
  using namespace std;
  
  char city_name[50];

  cout << "Hello, do you have any excursion tours?" << endl;
  cout << "Yes, for example "; cin.getline(city_name, 50);
  cout << '\n' << city_name << "? Very interesting. And how much does it cost?" << endl;

  int price;
  cin >> price;
   
  cout << '\n' << price << "$ - ";

  if (price > 500) {
    cout << "it's too expensive for me!" << endl;
  } else if (price > 200) {
    cout << "it's too expensive for so short travell!" << endl;
  } else if (price > 200) {
    cout << "normal price, but i don't have any money. I'll be tomorrow" << endl;
  } else {
    cout << "I'm takin' it" << endl;
  };

  return 0;
};
