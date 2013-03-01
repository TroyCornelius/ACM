#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

int n, m;
char g[200][200];
const int dy[2]={1, -1};
bool check(int row)
{
     for (int j=1; j<=m; j++)
     if (g[row][j] == 'W') return false;
     return true;
     }
int main()
{
    cin >>n >>m;
    for (int i=1; i<=n; i++)
      for (int j=1; j<=m ; j++)
         cin >>g[i][j];
    
    int ans = 0, c=0;
    int now = 1, tmp=n;
    for (int i=n; i>=1; i--)
    if (check(i)) tmp--;
    else break;
    n = tmp;
    for (int i=1; i<=n; i++)
    {
        tmp = now;
        for (int j=now; j <= m && j>=1; j+=dy[c])
        {
            if (g[i][j] == 'W') tmp = j;            
        }
      //  cout <<tmp <<endl;
      
        if (i < n){
        for (int j=tmp; j <= m && j>=1; j+=dy[c])
        {
            if (g[i+1][j] == 'W') 
            {
               if (c == 0) tmp = max(tmp, j); 
               else tmp = min(tmp, j);
            }           
        }
        }
      //  cout << tmp <<" "<<now <<" "<<ans <<endl;
        ans += abs(tmp - now);
        now = tmp;
        ans++;    
        c = 1 - c;    
    }
    if (n == 0) cout <<0 <<endl;
    else
    cout <<ans - 1 <<endl;
    return 0;
    }
