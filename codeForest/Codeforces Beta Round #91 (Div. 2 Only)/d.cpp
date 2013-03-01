#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cctype>
#include <map>
#include <vector>
#define pb push_back
using namespace std;

vector<string> s;
string st, s1;
map<string, int> vis;
int n, k, tot;
int main()
{
    int loc, loop = -1, cir;
    cin >>n >>k;
    cin >>st;
    vis.clear();
    s.clear();
    s.pb(st);
    vis[st] = 0;
    tot = 1;
    while (true)
    {
          st = s[tot-1];
          loc = st.find("47", 0);
          if (loc == string::npos) break;
          else
          {
              if (loc%2==0) st.replace(loc, 2, "44");
              else st.replace(loc, 2, "77");
              if (vis.find(st) == vis.end()) {vis[st] = tot++;s.pb(st);}
              else
              {
                  loop = vis[st];
                  break;                  
              }  
          }
    }
    if (loop == -1)
    {
        if (k >= tot) cout <<s[tot-1] <<endl;
        else cout <<s[k] <<endl;             
    }
    else
    {
        if (k - loop > 0) 
        {
            k-=loop;
            cir = tot - loop;
            k %= cir;
            cout <<s[loop+k] <<endl;
            
        }
        else cout <<s[k] <<endl;        
    }    
   // system("pause");
    
    
    return 0;
}
