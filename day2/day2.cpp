#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

int countSafe = 0;
const int MAX_SAFE = 2;

std::string line;

int main(){
    std::ifstream file("input.txt");
    while(std::getline(file, line)){
        std::cout << line << '\n';
    }
    return 0;
}