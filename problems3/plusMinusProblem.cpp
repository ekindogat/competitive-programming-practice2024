#include <bits/stdc++.h>

//00:09:30.210
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'plusMinus' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void plusMinus(vector<int> arr) {
    int n_count=0, p_count=0, z_count=0; // negative_count, positive_count, zero_count
    for (auto i : arr)
    {
        if(i < 0) n_count++;
        else if(i > 0) p_count++;
        else z_count++;
    }
    float total_count = n_count + p_count + z_count;
    // ratio calculation
    float n_ratio, p_ratio, z_ratio;
    n_ratio = n_count / total_count;
    p_ratio = p_count / total_count;
    z_ratio = z_count / total_count;

    // output formatting:   positive -> negative -> zero
    printf("%.6f\n%.6f\n%.6f\n",p_ratio,n_ratio,z_ratio);
    
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    plusMinus(arr);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
