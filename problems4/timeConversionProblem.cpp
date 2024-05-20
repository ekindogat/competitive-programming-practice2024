#include <bits/stdc++.h>
// 00:29:03.068
using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s)
{
    // 12:13:32PM
    stringstream ss(s);
    string token;
    int hour, min, sec;
    bool isAM;
    for (int i = 0; i < 3; i++)
    {
        getline(ss, token, ':');
        switch (i)
        {
        case 0:
            hour = stoi(token);
            break;
        case 1:
            min = stoi(token);
            break;
        case 2:
            sec = stoi(token.substr(0,2));
            token.substr(2,4) == "AM" ? isAM = true : isAM = false;
            break;
        }
    }
    if(!isAM){ // PM 13 14 15 12pm -> 12
        hour = hour == 12 ? hour : hour + 12;
    }else{ // AM 12am -> 00 9am -> 
        hour = hour == 12 ? 0 : hour;
    }
    string str_hour = hour<10 ? "0" + to_string(hour) : to_string(hour);
    string str_min = min<10 ? "0" + to_string(min) : to_string(min);
    string str_sec = sec<10 ? "0" + to_string(sec) : to_string(sec);
    return str_hour +":"+ str_min +":"+ str_sec; // 12:13:33
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
