#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

int countSafe = 0;
const int MAX_SAFE = 3;

string line;
bool anySafe;


vector<int> parse(string line){
    vector<int> numbers;
    istringstream stream(line);
    int num;
    while(stream >> num){
        numbers.push_back(num);
    }
    return numbers;
}

vector<int> checkSafe(vector<int> numbers){
    int direction= 0;//-1 - decrementing 0 - undefined, 1 - incrementing
    bool isSafe = true;
    int index;

    for(int i = 0; i < numbers.size() - 1&& isSafe;i++){
        if((abs(numbers[i] - numbers[i + 1]) == 0)|| abs(numbers[i] - numbers[i + 1]) > MAX_SAFE){//check if change is too big
            isSafe = false;
            index = i;
        }
        if(numbers[i] > numbers[i + 1]){//check if incrementing when decrementing
            if(direction > 0){
                isSafe = false;
                index = i;
            }
            direction = -1;
        }
        if(numbers[i] < numbers[i + 1]){//check if decrementing when incrementing
            if(direction < 0){
                isSafe = false;
                index = i;
            }
            direction = 1;
        }
    }
    vector<int> result = {isSafe, index};
    return result;
}

auto consider(vector<int> numbers, int i){
    vector<int> vecCopy = numbers;
    vecCopy.erase(vecCopy.begin() + i);
    vector<int> result = checkSafe(vecCopy);
    if(result[0]){
        anySafe = true;
    }
}

int main(){
    ifstream file("input.txt");
    while(getline(file, line)){
        vector<int> numbers = parse(line);
        vector<int> result= checkSafe(numbers); 
        anySafe = false;
        if(!result[0]){  
            for(int i = 0; i < numbers.size(); i++){
                consider(numbers, i);
            }
        }
        if(result[0] || anySafe){
            countSafe++;
            for(int i = 0; i < numbers.size(); i++){
                cout << numbers[i] << ' ';
            }
            cout << '\n';
        }
    }
    cout << countSafe << '\n';
    return 0;
}