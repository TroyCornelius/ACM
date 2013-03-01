#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

string s;
int main()
{
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int ans = 0;
    while (cin >>s)
      {
          if (s == "!") continue;
          ans++;         
      }
    cout <<ans <<endl;
   // system("pause");
    
    return 0;
    }
