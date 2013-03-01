#include <cstdio>
#include <ctype.h>
#include <iostream>
#include <string>
using namespace std;

string s;
int ans;
int main()
{
    while (getline(cin, s))
    {
       if (s == "*") break;
       ans = 0;
       for (int i=0; i<s.length(); i++)
       {
           char c = tolower(s[i]);
           if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u') ans++;     
       }
       cout <<ans <<endl;
          
    }
    return 0;
    }
