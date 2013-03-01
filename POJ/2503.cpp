#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
map<string,string> dic;
string s1, s2;
int main() 
{
    while (getline(cin, s1))
    {
        int loc = s1.find(" ", 0);
        if (loc != string::npos)
        {
            s2 = s1.substr(loc+1, s1.length() - loc - 1);
            dic[s2] = s1.substr(0, loc);
        }
        else break;
    }
    while (getline(cin, s1))
    {
        if (dic.find(s1) == dic.end()) cout <<"eh" <<endl;
        else cout <<dic[s1] <<endl;
    }
    return 0;
}

