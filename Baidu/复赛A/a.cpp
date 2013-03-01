#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define Maxn 3010
using namespace std;

int f[2][Maxn][Maxn];
int n, ans, s1, s2;
int p[Maxn], q[Maxn];
int s[2][Maxn];
int d[Maxn][2];


void init()
{
     memset(s, 0, sizeof(s));
     for (int i=1; i<=n; i++)
     {
         s[0][i] = s[0][i-1] + p[i];
         s[1][i] = s[2][i-1] + q[i];        
     }

     for (int i=1; i<=n; i++)
     {
       f[0][i][i] = 0;
       f[1][i][i] = 0;
       for (int j=i+1; j<=n+1; j++)
       {
           f[0][i][j] += f[0][i][j-1] + p[j-1];     
           if (j > i+1) f[0][i][j] += s[0][j-2] - s[0][i-1];
           f[1][i][j] += f[1][i][j-1] + q[j-1];
           if (j > i+1) f[1][i][j] += s[1][j-2] - s[1][i-1];
       }         
     }          
     }

void dp()
{
     for (int i=2; i<=n+1; i++)
     {
         for (int k=0; k<2; k++)
         {
             d[i][k] = d[i-1][k];
             for (int j=i-1; j>=1; j--)
             {
                 d[i][k] = max(d[i][1-k], d[j][k] + f[1-k][j][i]);                 
             }      
                  
         }   
       //  cout <<d[i][0] <<"   "<<d[i][1] <<endl;     
     }
     
     
     printf("%d\n", max(d[n+1][0], d[n+1][1]));
     
     }
int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++) scanf("%d %d", &p[i], &q[i]);
    
    init();
    dp();
    
    system("pause");
    return 0;
    }
