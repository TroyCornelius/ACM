#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <set>
#include <algorithm>
#include <functional>
#include <vector>
#include <cctype>
#include <queue>
#define lim_t 625000
using namespace std;

int f[100], tot;
struct Tnode
{
       int loc, t;
       Tnode(int a=0, int b=0)
       {
          loc=a; t=b;        
       }
       };
queue<Tnode> q;

class KindAndCruel
{
      public :
      int crossTheField(string s, int K, int C)
      {
          while (!q.empty()) q.pop();
          tot = 0;
          q.push(Tnode(0,0,0));
          
          while (!q.empty())
          {
             Tnode now = q.front();
             q.pop();
             
             if (tot > lim_t) break;
             
             if (now.loc+1<s.size())
             {
                if (now.loc+1 == s.size()-1) return now.t+1;
                
                if (s[now.loc+1] == 'K' && (now.t+1)%K!=0) q.push(Tnode(now.loc+1, now.t+1));
                else
                if (s[now.loc+1] == 'C' && (now.t+1)%C==0) q.push(Tnode(now.loc+1, now.t+1));
                else
                if (s[now.loc+1]== '.') q.push(Tnode(now.loc+1, now.t+1));                                    
             }
             

             if (s[now.loc]=='K' && (now.t+1)%K!=0) q.push(Tnode(now.loc, now.t+1));
             
             if (now.loc - 1 >= 0)
             {
                if (s[now.loc] != '.')
                {
                   if (s[now.loc-1]=='K' && (now.t+1)%K != 0)
                   {
                     q.push(Tnode(now.loc-1, now.t+1));                                   
                   }
                   else
                   if (s[now.loc-1]=='C' && (now.t+1)%C==0)
                   {
                     q.push(Tnode(now.loc-1, now.t+1));                                   
                   }
                   else
                   if (s[now.loc-1]=='.')
                     q.push(Tnode(now.loc-1, now.t+1, now.done+1));
                }     
             if (s[now.loc]=='.') q.push(Tnode(now.loc, now.t+1));
             tot++;
             }
                
          }
          
          return -1;
      }
      
      
      }d;
int main()
{
    string ss;
    int a, b;
    while (cin >>ss)
    {
          cin >>a >>b;
          cout <<d.crossTheField(ss, a, b) <<endl;
          
    }
    
    return 0;
    }
