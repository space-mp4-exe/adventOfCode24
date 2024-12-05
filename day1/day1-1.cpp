#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

std::vector<int> leftNumbers;
std::vector<int> rightNumbers;

std::string inputString;

char line[20];
char firstNumber[6], secondNumber[6];

int sum = 0;
int sim = 0;

int main(){
	FILE* file;
	file = fopen("input.txt", "r");
	while(fgets(line, sizeof line, file) != NULL){
		strncpy(firstNumber, line, 5);
		leftNumbers.push_back(std::stoi(firstNumber));
		strncpy(secondNumber, line + 8, strlen(line) - 6);
		rightNumbers.push_back(std::stoi(secondNumber));
	}

	stable_sort(leftNumbers.begin(), leftNumbers.end());
	stable_sort(rightNumbers.begin(), rightNumbers.end());

	for(int i; i < 1000; i++){
		int left = leftNumbers[i];
		int right = rightNumbers[i];
		sum += abs(left - right);
	}

	for(int i = 0; i < leftNumbers.size(); i++){
		int count = 0;
		for(int j = 0; j < rightNumbers.size(); j++){
			if(leftNumbers[i] == rightNumbers[j]){
				count++;
			}
		}
		sim += count * leftNumbers[i];
	}

	std::cout << sum << '\n';
	std::cout << sim << '\n';
	return -1;
}
