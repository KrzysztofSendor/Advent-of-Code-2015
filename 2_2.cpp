#include <iostream>
#include <string>
#include <fstream>
#include <cstddef>
#include <cstdlib>
#include <algorithm>

int main(int argc, char const *argv[]) {
  std::ifstream file("input_2.txt");
  std::string line;
  char separator = 'x';
  int output = 0;
  while (std::getline(file, line))
  {
    size_t mesurement[3];
    for (size_t i = 0; i < 2; i++) {
      size_t position = line.find_first_of(separator);
      mesurement[i] = atoi((line.substr(0,position)).c_str());
      line = line.substr(position+1,line.length());
    }
    mesurement[2] = atoi(line.c_str());
    std::sort(mesurement, mesurement + 3);
    output += mesurement[0]*2 + mesurement[1]*2 + mesurement[0]*mesurement[1]*mesurement[2];
  }
  std::cout << "wynik: " << output << std::endl;
  return 0;
}
