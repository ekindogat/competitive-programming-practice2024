
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;
// g++ -std=c++14 -o stringStream stringStreamProblem.cpp
vector<int> parseInts(string str) {
	// Complete this function
    stringstream ss(str);
    vector<int> vect;
    string token;
    while(getline(ss, token, ',')){
        vect.push_back(stoi(token));
    }
    return vect;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    //cin.get();
    //cin.get();
    return 0;
}
