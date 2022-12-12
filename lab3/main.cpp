#include <iostream>
#include <iomanip>
#include <cstdlib> 
#include <ctime> 



int main() {
  srand((unsigned)time(0)); 
  std::cout << "Вариант 1" << std::endl;

  long double dig_matrix[5][6];

  std::cout << "Enter values of matrix" << std::endl;
  for(int row = 0; row < 5; row++) {
    for(int column = 0; column < 6; column++) {
      dig_matrix[row][column] = (rand()%999999)+1;
    };
  };

  // Вычисление суммы элементов матрицы
  long double matrix_sum = 0;
  for(int row = 0; row < 5; row++) {
    for(int column = 0; column < 6; column++) {
      matrix_sum += dig_matrix[row][column];
    };
  };
  long double arithmetic_mean = matrix_sum / 30;

  std::string separator = "||==========||==========||==========||==========||==========||==========||";


  std::cout << separator << std::endl << "|| Данные 1 || Данные 2 || Данные 3 || Данные 4 || Данные 5 || Данные 6 ||" << std::endl << separator << std::endl;
  for(int row = 0; row < 5; row++) {
    std::cout << "||";
    for(int column = 0; column < 6; column++) {
      std::cout << std::setw(10) << dig_matrix[row][column] << "||";
    };

    std::cout << std::endl << separator << std::endl;
  };

  std::cout << std::endl << "arithmetic mean of matrix = " << arithmetic_mean << std::endl;

  return 0;
};
