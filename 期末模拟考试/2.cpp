#include <iostream>
#include <string>
using namespace std;

string s, t;
bool check(string s1)
{
     int lo = 0, ri = s1.size() - 1;
     while (lo <= ri)
       {
          if (s1[lo] != s1[ri]) return false;
          lo++;
          ri--;           
       }
     return true;
     }
int main()
{
    getline(cin, s);
    bool flag = check(s);
    if (!flag)
      {
         for (int i=0; i<s.size(); i++)
           {
              t = s;
              t.erase(i,1);
              if (check(t)) {flag =true; break;}                  
           }             
      }
    if (flag) cout <<"Y" <<endl;
    else cout <<"N" <<endl;
    system("pause");
    return 0;
    }
