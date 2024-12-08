#include <string>
#include <sstream>
#include <fstream>
#include <regex>
#include <iostream>
using namespace std;

string input; 
int total = 0;

struct notDigit{
    bool operator()(const char c){
        return c != ',' && ' ' && !isdigit(c);
    }
};

int main(){
    ifstream stream("input.txt");
    stringstream buffer;
    buffer << stream.rdbuf();
    input = buffer.str();

    string match = "mul\\([0-9]{1,3},[0-9]{1,3}\\)";
    regex reg(match);
    auto wordsBegin = sregex_iterator(input.begin(), input.end(), reg);
    auto wordsEnd = sregex_iterator();

    for(sregex_iterator i = wordsBegin; i != wordsEnd; ++i){
        vector<int> filtered;
        smatch foundMatch = *i;
        string matchStr = foundMatch.str();
        notDigit notDigit;
        string::iterator end = remove_if(matchStr.begin(), matchStr.end(), notDigit);
        string allNumbers(matchStr.begin(), end);
        stringstream ss(allNumbers);
        for(int j = 0; ss >> j;){
            filtered.push_back(j);
        }
        cout << filtered[0] << '*' << filtered[1] << '\n';
        total += filtered[0] * filtered[1];
    }

    cout << total << '\n';

    return 0;
}