#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <fstream>
#include <cassert>
#include <sstream>
using namespace std;

// 01:42:18.282
void getInput(vector<string> &vectH, vector<string> &vectQ);
void solve(vector<string> &h, vector<string> &q, map<string, string> &m);
void printSolution(vector<string> &q, map<string, string> &m);
void printInput(vector<string> &h, vector<string> &q);
void stall();
int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    // INPUT
    vector<string> hrml, queries;
    getInput(hrml, queries);

    // PROCESS
    map<string, string> dict;
    solve(hrml, queries, dict);

    // OUTPUT

    printSolution(queries, dict);
    // printInput(hrml,queries);
    return 0;
}
void getInput(vector<string> &vectH, vector<string> &vectQ)
{
    int n, q;
    cin >> n >> q; // endl left
    cin.ignore();  // handle endl
    string temp;
    for (int i = 0; i < n; i++)
    {
        getline(cin, temp);
        vectH.push_back(temp);
    }
    for (int i = 0; i < q; i++)
    {
        getline(cin, temp);
        vectQ.push_back(temp);
    }
}
void printSolution(vector<string> &q, map<string, string> &m)
{
    string word;
    for (auto str : q)
    {

        if (m.find(str) == m.end())
            word = "Not Found!";
        else
            word = m[str];
        cout << word << endl;
    }
    //stall();
}

void solve(vector<string> &h, vector<string> &q, map<string, string> &m)
{
    vector<string> tag_stack;
    for (int i = 0; i < h.size(); i++)
    {
        string temp = h[i];
        // Format hrml tags
        temp.erase(remove(temp.begin(), temp.end(), '\"'), temp.end());
        temp.erase(remove(temp.begin(), temp.end(), '>'), temp.end());
        // Pop if end-tag received
        if (temp.substr(0, 2) == "</")
            tag_stack.pop_back();
        else
        {
            temp.erase(remove(temp.begin(), temp.end(), '<'));
            stringstream ss;
            ss << temp;
            string tag, name, value;
            char ch;
            ss >> tag >> name >> ch >> value;
            string temp1 = "";
            if (tag_stack.size() > 0) // current tag is nested
            {
                temp1 = *(tag_stack.rbegin()); // unpack the iterator
                temp1 = temp1 + "." + tag;
            }
            else
            {
                temp1 = tag;
            }
            tag_stack.push_back(temp1); // add current tag in stack
            string key = *(tag_stack.rbegin()) + "~" + name;
            m[key] = value;
            while (ss)
            {
                ss >> name >> ch >> value;
                key = *(tag_stack.rbegin()) + "~" + name;
                m[key] = value;
            }
        }
    }
}

void printInput(vector<string> &h, vector<string> &q)
{
    for (auto str : h)
    {
        cout << str << endl;
    }
    for (auto str : q)
    {
        cout << str << endl;
    }
    stall();
}
void stall()
{
    cin.get();
    cin.get();
}
