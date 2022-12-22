#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <string>
#include <stdlib.h>
#include <time.h>



const int LINE_LENGTH = 64;
const int NUMBER_OF_STUDENTS = 374;



struct Student {
  unsigned int record_book_id;
  std::string group;
  std::string full_name;
  unsigned int grant;
  double gpa;
};



char convert_string_to_char(std::string);

int convert_string_to_int(std::string);

int get_record_book_id(std::string);

std::string get_group(std::string);

std::string get_fname(std::string);

int get_grant(std::string);

double get_gpa(std::string);

int GetRandomNumber(int, int);



int main() {
  using namespace std;
  ifstream file("/Users/gamzatshakhmanaev/Documents/Projects/SandBox/cpp.mstuca/labs/lab 7/Data.txt");

  Student students[NUMBER_OF_STUDENTS];  
  string line;

  int ind = 0;
  while(getline(file, line)) {
    std::cout << line << std::endl;

    students[ind].record_book_id = get_record_book_id(line);
    students[ind].group = get_group(line);
    students[ind].full_name = get_fname(line);
    students[ind].grant = get_grant(line);
    students[ind].gpa = get_gpa(line);
    
    ind++;    
  };
  

  long double average_entrance_score, scores_sum;
  scores_sum = 0;
  for(int i = 0; i < NUMBER_OF_STUDENTS; i++) {
    scores_sum += students[i].gpa;
  };
  average_entrance_score = scores_sum / NUMBER_OF_STUDENTS;

  std::cout << "Average enterance score = " << average_entrance_score << std::endl;

  file.close();
  return 0;
};



int convert_string_to_int(std::string str) {
  try {
        int res = std::stoi(str);
        return res;
    }
    catch(std::invalid_argument e) {
      int res = GetRandomNumber(50, 99);
      return res;
    }
};

int get_record_book_id(std::string line) {
  std::string required_data;

  for(int i = 0; i < LINE_LENGTH; i++) {
    if (i < 7) {
      required_data += line[i];
    };
  };
  
  return convert_string_to_int(required_data);
};

std::string get_group(std::string line) {
  std::string required_data;

  for(int i = 0; i < LINE_LENGTH; i++) {
    if ((i > 12) && (i < 16)) {
      if (line[i] != ' ') {
        required_data += line[i];
      };
    };
  };
  
  return required_data;
};

std::string get_fname(std::string line) {
  std::string required_data;

  for(int i = 0; i < LINE_LENGTH; i++) {
    if ((i > 20) && (i < 43)) {
      if (line[i] != ' ') {
        required_data += line[i];
      };
    };
  };

  return required_data;
};

int get_grant(std::string line) {
  std::string required_data;

  for(int i = 0; i < LINE_LENGTH; i++) {
    if ((i > 47) && (i < 53)) {
      required_data += line[i];
    };
  };

  return convert_string_to_int(required_data);
};

double get_gpa(std::string line) {
  std::string first_exam, sec_exam, third_exam;

  for(int i = 55; i < LINE_LENGTH; i++) {
    if ((i > 54) && (i < 57)) {
      first_exam += line[i];
    };

    if ((i > 58) && (i < 61)) {
      sec_exam += line[i];
    };

    if ((i > 62) && (i < 65)) {
      third_exam += line[i];
    };
  };

  int fe, se, te;
  fe = convert_string_to_int(first_exam);
  se = convert_string_to_int(sec_exam);
  te = convert_string_to_int(third_exam);

  double res = (fe + se + te) / 3;

  return res;
};

int GetRandomNumber(int min, int max) {
  srand(time(NULL));

  int num = min + rand() % (max - min + 1);

  return num;
};
