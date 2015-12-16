#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char const *argv[]) {
  std::ifstream file("input_3.txt");
  std::string line;

  int maxNorth = 0;
  int maxSouth = 0;
  int maxEast = 0;
  int maxWest = 0;

  int santaPositionX = 0;
  int santaPositionY = 0;

  while (std::getline(file,line)) {
    for (size_t i = 0; i < line.length(); i++) {
      if (line.at(i) == '>') {
        santaPositionX += 1;
        if (santaPositionX == maxEast) maxEast += 1;
      }
      if (line.at(i) == '<') {
        santaPositionX -= 1;
        if (santaPositionX == maxWest) maxWest -= 1;
      }
      if (line.at(i) == '^') {
        santaPositionY += 1;
        if (santaPositionY == maxNorth) maxNorth += 1;
      }
      if (line.at(i) == 'v') {
        santaPositionY -= 1;
        if (santaPositionY == maxSouth) maxSouth -= 1;
      }
    }
  }

  maxWest = -maxWest;
  maxSouth = -maxSouth;

  std::cout << "maxEast: " << maxEast << std::endl;
  std::cout << "maxWest: " << maxWest << std::endl;
  std::cout << "maxNorth: " << maxNorth << std::endl;
  std::cout << "maxSouth: " << maxSouth << std::endl;

  int mapSizeX = maxWest + maxEast + 1;
  int mapSizeY = maxNorth + maxSouth + 1;

  std::cout << mapSizeY << "x" << mapSizeX << std::endl;

  int **santaMap = new int*[mapSizeY];
  for (size_t i = 0; i < mapSizeY; i++) {
    santaMap[i] = new int[mapSizeX];
  }

  for (size_t i = 0; i < mapSizeY; i++) {
    for (size_t j = 0; j < mapSizeX; j++) {
      santaMap[i][j] = 0;
    }
  }

  santaPositionX = maxWest + 1;
  santaPositionY = maxSouth + 1;

  santaMap[santaPositionY][santaPositionX] += 1;

    for (size_t i = 0; i < line.length(); i++) {
      if (line.at(i) == '>') santaPositionX += 1;
      if (line.at(i) == '<') santaPositionX -= 1;
      if (line.at(i) == '^') santaPositionY += 1;
      if (line.at(i) == 'v') santaPositionX -= 1;
      santaMap[santaPositionY][santaPositionX] += 1;
    }

  int output = 0;

  for (size_t i = 0; i < maxNorth+maxSouth+1; i++) {
    for (size_t j = 0; j < maxEast+maxWest+1; j++) {
      if (santaMap[i][j] >= 1) output += 1;
    }
  }

  std::cout << "wynik: " << output <<  std::endl;

  for (size_t i = 0; i < mapSizeY; i++) {
    delete[] santaMap[i];
  }
  delete[] santaMap;

  return 0;
}
