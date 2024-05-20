#include <iostream>
#include <string>
using namespace std;
// g++ -std=c++14 -o stringStream stringStreamProblem.cpp
// 7dk
void swap(string& str1,string& str2){
    char c = str1[0];
    str1[0] = str2[0];
    str2[0] = c;
}
int main() {
	// Complete the program
    string str1, str2;
    std::getline(cin, str1);
    std::getline(cin, str2);
    std::cout << (int)str1.size()<< " " << (int)str2.size() << std::endl;
    std::cout << str1+str2 << std::endl;
    swap(str1,str2);
    std::cout << str1 + " " + str2;
    return 0;

}