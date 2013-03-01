#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

struct Tnode
{
       int id;
       string s;
       };
Tnode c[250];
string num[10]={"0","1","2","3","4","5","6","7","8","9"};
vector <int> ans[220];
int n, k, d;
inline string get_s(int p)
{
       string ret="";
       while (p > 0)
       { 
          ret = num[p%10] + ret;
          p/=10;     
       }
       return ret;
       }
bool cmp(const Tnode &a, const Tnode &b)
{
     if (a.s == b.s) return a.id < b.id;
     return a.s < b.s;
     }
int main()
{
    for (int i=0; i<=210; i++) {c[i].s.clear();c[i].id=i;ans[i].clear();}
    scanf("%d", &n);
    for (int i=1; i<=n*(n-1)/2; i++)
    {
       scanf("%d", &k);
       for (int j=0; j<k; j++)
       {
           scanf("%d", &d);
           c[d].s = c[d].s + "+" + get_s(i);           
       }        
    }
    sort(c, c+201, cmp);
    int p1=-1, p2=0, p=0;
    while (p < n && p2 <= 200)
    {
       if (c[p2].s == "") {p2++;continue;}
       if (p1 == -1) 
       {
          ans[p].push_back(c[p2].id);
          p1 = p2;
          p2++;
          continue;                
       }
       else
       {
           if (c[p1].s == c[p2].s)
           {
              ans[p].push_back(c[p2].id);
              p2++;
              continue;           
           }
           else
           {
               p++;
               ans[p].push_back(c[p2].id);
               p1 = p2;
               p2++;
               continue;        
           }           
       }          
    }
    for (int i=0; i<n; i++)
    {
        printf("%d ", int(ans[i].size()));
        for (int j=0; j<ans[i].size()-1; j++)
        {
            printf("%d ", ans[i][j]);
        }
        printf("%d\n", ans[i][ans[i].size()-1]);        
    }  
    

    return 0;
    }
