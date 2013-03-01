#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
#include <functional>
#include <cctype>
#define Maxn 510
using namespace std;


int T, r, c, D, ans;
int f[Maxn][Maxn];
long long dx1[Maxn][Maxn], dy1[Maxn][Maxn], t1[Maxn][Maxn];
long long dx2[Maxn][Maxn], dy2[Maxn][Maxn], t2[Maxn][Maxn];

void init()
{
     for (int i=0; i<=r; i++)
       for (int j=0; j<=c; j++)
         dx1[i][j] = dy1[i][j] = t1[i][j] = 0;
	
	char ch;
	
	for (int i=1; i<=r; i++)
	  for (int j=1; j<=c; j++)
	  {
         while (!isdigit(cin.peek())) getchar();
         ch = getchar();
         f[i][j] = int(ch - '0');
         dx2[i][j] = dx1[i][j] = (D + f[i][j]) * i;
         dy2[i][j] = dy1[i][j] = (D + f[i][j]) * j;
        
         t2[i][j] = t1[i][j] = (D + f[i][j]);
          
      } 
        
        for (int i=1; i<=r; i++)
          for (int j=1; j<=c; j++)
          {
              dx1[i][j] += dx1[i][j-1];
              dy1[i][j] += dy1[i][j-1];
              t1[i][j] += t1[i][j-1];              
          }

        for (int j=1; j<=c; j++)
          for (int i=1; i<=r; i++)
          {
              dx1[i][j] += dx1[i-1][j];
              dy1[i][j] += dy1[i-1][j];
              t1[i][j] += t1[i-1][j];              
          }     
     }

int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    cin >>T;
    for (int ct=1; ct<=T; ct++)
    {
        scanf("%d%d%d", &r, &c, &D);
        
        init();
		ans = 0;
		
		for (int i=1; i<=r; i++)
		  for (int j=1; j<=c; j++)
		  {
              int tmp = min(r-i, c-j);
              while (tmp + 1 >= 3)
              {
                 long long tx = dx1[i+tmp][j+tmp] + dx1[i-1][j-1] - dx1[i-1][j+tmp] - dx1[i+tmp][j-1] - dx2[i][j] - dx2[i][j+tmp] - dx2[i+tmp][j] - dx2[i+tmp][j+tmp];
                 long long ty = dy1[i+tmp][j+tmp] + dy1[i-1][j-1] - dy1[i-1][j+tmp] - dy1[i+tmp][j-1] - dy2[i][j] - dy2[i][j+tmp] - dy2[i+tmp][j] - dy2[i+tmp][j+tmp];
                 long long tt = t1[i+tmp][j+tmp] + t1[i-1][j-1] - t1[i-1][j+tmp] - t1[i+tmp][j-1] - t2[i][j] - t2[i][j+tmp] - t2[i+tmp][j] - t2[i+tmp][j+tmp];
              
                 if (tmp & 1)
                 {
                    tx *= 2;
                    ty *= 2; 
                    long long  px = i + i + tmp; 
                    long long  py = j + j + tmp;
                    if ((tx - tt * px == 0) && (ty - tt * py == 0)) ans = max(ans, tmp + 1);    
                 }
                 else
                 {
                     long long px = (i + i + tmp) / 2;
                     long long py = (j + j + tmp) / 2;
                     if ((tx - tt*px == 0) && (ty - tt*py==0)) ans = max(ans, tmp + 1);
                     
                 }
                 
                 tmp--;
              }
              
          }

		printf("Case #%d: ", ct);
		if (ans >= 3) printf("%d\n", ans);
		else printf("IMPOSSIBLE\n");
    }    
    
  //  system("pause");
    return 0;
    }
