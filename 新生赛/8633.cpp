#include <iostream>
#include <string>
#define Maxnum 999999999
using namespace std;

string s;
int T, f[1005];

bool check(int st, int en)
{
     int le = st, ri = en;
     while (le <= ri)
       {
           if (s[le] != s[ri]) return false;
           le++;
           ri--;           
       }
     return true;
     }
void dp()
{
     for (int i=0; i<=s.size(); i++) f[i] = Maxnum;
     f[0] = 1;
     for (int i=1; i<s.size(); i++)
       {
          if (check(0,i)) {f[i] = 1; continue;}
          for (int j=0; j<i; j++)
            if (check(j+1, i)) f[i] <?= f[j] + 1;              
       }
     cout <<f[s.size()-1] <<endl;     
     }
int main()
{
    cin >>T;
    while (T>0)
      {
         T--;
         cin >>s;
         dp();          
      }
    return 0;
    }
