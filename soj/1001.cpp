#include <iostream>
#include <string> 
#include <stdio.h>
#include <functional>
#include <algorithm>
#include <string.h>
#include <memory.h>
using namespace std;

string s;
long long f[100000];
class A
{
     private:
     int c[4];
     static const int a[1] = {10};
     public:
};
inline bool check(int x)
{
       int sum = 0;
       sum = (int(s[x]-'0'))*10 + int(s[x+1]-'0');
       return sum <= 26;       
       }
void dp()
{
     int len = int(s.size()) - 1;
     memset(f, 0, sizeof(f));
     if (s[len] != '0') f[len] = 1;
     if (len > 0 && s[len-1] != '0') f[len-1] = 1;
     if (len > 0 && check(len-1)) f[len-1]++;
     for (int i=len-2; i>=0; i--)
       {
          if (s[i] != '0') f[i] = f[i+1];
          if (s[i] != '0' && check(i)) f[i] += f[i+2];   
          else f[i] = f[i+2];           
       }
     cout <<f[0] <<endl;     
     }

int main()
{
    while (1)
    {
       cin >>s;
       if (s == "0") break;
       dp();
    }
    system("pause");
    return 0;
    }
