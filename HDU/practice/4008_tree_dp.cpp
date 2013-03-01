#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define pb push_back
#define Maxn 100000
using namespace std;


int n, Q;
vector<int> g[Maxn];
void init()
{
     int a, b;
     scanf("%d%d", &n, &Q);
     for (int i=0; i<=n; i++) g[i].clear();
     for (int i=1; i<n; i++)
     {
         scanf("%d%d", &a, &b);
         g[a].pb(b);
         g[b].pb(a);    
             
     }   
     a = 'a';
     a = a+3, a+2;
     cout <<a <<endl;
     }
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
          init();
          
    }
    
    
    
    return 0;
    }
