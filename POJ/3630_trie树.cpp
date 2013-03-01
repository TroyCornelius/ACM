#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#define Maxn 1000000
using namespace std;

struct Tnode
{
       int flag, next[10];
       void clr(){memset(next, -1, sizeof(next));flag = false;}       
       }t[Maxn];
int n, T, m;
string s;
bool done;
void insert(string s1, int root)
{
     int tid;
     for (int i=0; i<s1.length(); i++)
     {
         tid = s1[i] - '0';
         if (t[root].next[tid] == -1)
         {
            t[++m].clr();
            t[root].next[tid] = m;                                                 
         }
         root = t[root].next[tid];         
     }
     t[root].flag = true;    
     }
void query(int root)
{
     if (!done) return;
     
     if (t[root].flag)
     {
        for (int i=0; i<10; i++)
          if (t[root].next[i] != -1)
          {
             done = false;
             return;       
          }
     }
     for (int i=0; i<10; i++)
     if (t[root].next[i] != -1) query(t[root].next[i]);     
     }
int main()
{
    ios::sync_with_stdio(false);
    cin >>T;
    for (;T>0;T--)
    {
        cin >>n;
        m = 0;
        t[0].clr();
        for (int i=0; i<n; i++)
        {
            cin >>s;
            insert(s, 0);  
        }
        done = true;
        query(0);
        if (!done) cout <<"NO" <<endl;
        else cout <<"YES" <<endl;      
    }
    
    system("pause");
    return 0;
    }
