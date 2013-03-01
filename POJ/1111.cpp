#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>
#include <cstring>

using namespace std;

const int dx[] = {0,0,1,-1,1,-1,1,-1};
const int dy[] = {1,-1,0,0,1,1,-1,-1};
int n, m, sx, sy, ans;
char g[25][25];

void dfs(int x, int y)
{
     if (g[x][y] == 'X')
     {
        g[x][y] = 'Y';        
        for (int i=0; i<8; i++) dfs(x+dx[i], y+dy[i]);
     }
     return;
     }
int main()
{
    while (cin >>n >>m >>sx >>sy)
    {
          if (n == m && n == 0) break;
          for (int i=0; i<=n+1; i++)
            for (int j=0; j<=m+1; j++)
              g[i][j] = '.';
          for (int i=1; i<=n; i++)
            for (int j=1; j<=m; j++)
               cin >>g[i][j];
          
          dfs(sx, sy);
          ans = 0;
          for (int i=1; i<=n; i++)
            for (int j=1; j<=m; j++)
            if (g[i][j] == 'Y')
            {
               for (int k=0; k<4; k++)
               if (g[i+dx[k]][j+dy[k]]!='Y') ans++;                
            }
          cout <<ans <<endl;
    }
    
    
    return 0;
    }
