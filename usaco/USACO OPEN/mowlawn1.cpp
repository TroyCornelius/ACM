/* 
PROG: mowlawn
LANG: C++
ID: hacker_ja3
*/ 
#include <fstream>
#include <cstdio>
#include <string>
#include <cstring>
#define Maxn 100010
using namespace std;
FILE *fin = fopen("mowlawn.in", "r");
FILE *fout = fopen("mowlawn.out", "w");
int n, k;
int d[Maxn], f[2][1000];

void init()
{
     fscanf(fin, "%d%d",&n, &k);
     for (int i=1; i<=n; i++) fscanf(fin, "%d", &d[i]);
     return;
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
     fprintf(fout, "%d\n", ans);   
     }
int main()
{

    init();
    work();
    return 0;
    }
