#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

string s1, s2;
int loc1, loc2;
int main()
{
    while (cin >>s1 >>s2)
      {
         if (s1.length() < s2.length()) swap(s1, s2);
         loc1 = s1.find("*", 0);
         loc2 = s2.find("*", 0);
         
          
      }
    
    return 0;
    }
