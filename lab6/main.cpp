#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;
ofstream fout;

//----------------------------- Вычисление факториала-----------------------
long fact (int n) {
  if (n < 0) return 0;
  else if (n == 0) return 1;
  else return n * fact (n - 1);
}

//--------------------------------Вычисление x n -------------------------------
double stx (double x, int n) {
  if (n == 0) return 1;
  if (x == 0) return 0;
  if (n == 1) return x;
  if (n > 0) return (x * stx (x, n - 1));
  if (n < 0) return (stx (x, n + 1) / x);
}

//----------------------------------Вычисление (-1) n -------------------------
int st (int n) {
  if ((n == 0) || (n % 2 == 0)) return 1;
  else return -1;
}

//--------------------- Функция вычисления очередного члена ряда----------
double next (double x, int n) {
  return st(n)*stx(x,2*n+1)/(2*n+1);}

typedef double (*func) (double, int);
//--------Вычисление суммы с помощью while и рекуррентной формулы----
double S1 (int n, double x, double e) {
  double a =x, s=0;
  while (fabs(a)>e)
  {s+=a; a*= (-1* x*x * (2*n+1)/((2*n+3))); n++;}
  return (s+a);
}

//-------Вычисление суммы с помощью do-while и рекуррентной формулы-
double S2 (int n, double x, double e) {
  double a =x, s=0;
  do
  {s+=a; a*= (-1* x*x * (2*n+1)/((2*n+3))); n++;}
  while (fabs(a)>e);
  return (s+a);
}

//----------Вычисление суммы с помощью while и параметра – функции-----
double S3 (int n, double x, double e, func fn) {
  double f = fn (x, n), s=0;
  while(fabs(f)>e){s+=f; n++; f=fn (x, n);}
  return (s+f);
}

//--------Вычисление суммы с помощью do-while и параметра – функции---
double S4 (int n, double x, double e, func fn) {
  double f=fn (x, n), s=0;
  do
  {s+=f; n++; f=fn (x, n);}
  while(fabs(f)>e);
  return (s+f);
}

//-----С помощью рекурсивного суммирования и параметра – функции-----
double S5 (int n, double x, double e, func fn) {
  double f = fn (x, n);
  if(fabs(f)<e) return f;
  else return (f+ S5(n+1, x, e, fn));
}

//------------------------------------Главная функция-----------------------------------
int main () {
  double e = 1.e-5;
  fout.open ("/Users/gamzatshakhmanaev/Documents/Projects/SandBox/cpp.mstuca/labs/lab 6/data.txt");
  if (!fout) {
    cout << "Ошибка открытия файла результатов";
    exit (0);
  }

//----------------------------Вывод заголовка и шапки таблицы---------------------
  fout << "\t\t\tResults for e = " << e <<'\n'
       << "|-----|----------|----------|----------|----------|----------|----------|" <<'\n'
       << "|  x  |  arctg   |     S1   |    S2    |    S3    |    S4    |    S5    |" <<'\n'
          << "|-----|----------|----------|----------|----------|----------|----------|";
//-------------------------------Вывод значений----------------------------------
  for (double x=-0.5; x<=0.5; x+=0.3)
  {fout<< endl<<'|'<<setw (4) <<x<<setw (2) <<'|'<<setw (10) <<atan (x)<<'|'
       <<setw (10) << S1(0, x, e) <<'|'<<setw (10) << S2(0, x, e) << '|' << setw (10)
       << S3(0, x, e, next) << '|' << setw (10) << S4(0, x, e, next) << '|' << setw (10) << S5(0, x, e, next) << '|';
  }
  fout<<'\n'<<"|-----|----------|----------|----------|----------|----------|----------|";
  fout.close ();
}
