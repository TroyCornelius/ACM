/* 
PROG: mowlawn
LANG: C++
ID: hacker_ja3    
*/ 
#include <iostream>
#include <cstdio>
#include <string>
#define Maxn 100010
using namespace std;

int n, k;
int d[Maxn], f[2][1000];

void init()
{
     scanf("%d%d",&n, &k);
     for (int i=1; i<=n; i++) scanf("%d", &d[i]);
     }
void work()
{
     memset(f, 0, sizeof(f));
     int t = 0;
     for (int i=1; i<=n; i++)
     {
         for (int j=0; j<=k; j++)
         {
             f[t][0] >?= f[1-t][j];
             if (j>0) f[t][j] >?= f[1-t][j-1] + d[i];             
         }
         t = 1 - t;
     }
     int ans = 0;
     for (int j=0; j<=k; j++) ans >?= f[1-t][j];
     cout <<ans <<endl;   
     }
int main()
{
    freopen("mowlawn.in", "r", stdin);
    freopen("mowlawn.out", "w", stdout);
    init();
    work();
    
    
    
    
    return 0;
    }
