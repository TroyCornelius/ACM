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

using namespace std;

char a[1010][1010];
int c[1010][3];
int d[1010];
int ans,n,m,k;

void dfs(int s,int summ)
{
    if (s==k+1) {if (summ>ans) ans=summ; return ;}
    else
    {
        for (int i=0; i<=k; i++)
        {
            if (d[i]==0)
            {
                if (c[i][1]+1<=n && c[i][1]+1>=1)
                    if (a[c[i][1]+1][c[i][2]]=='P')
                    {
                        d[i]=1;
                        a[c[i][1]+1][c[i][2]]='Q';
                        dfs(s+1,summ+1);
                        d[i]=0;
                        a[c[i][1]+1][c[i][2]]='P';
                    }
                if (c[i][1]-1<=n && c[i][1]-1>=1)
                    if (a[c[i][1]-1][c[i][2]]=='P')
                    {
                        d[i]=1;
                        a[c[i][1]-1][c[i][2]]='Q';
                        dfs(s+1,summ+1);
                        d[i]=0;
                        a[c[i][1]-1][c[i][2]]='P';
                    }
                if (c[i][2]-1<=m && c[i][2]-1>=1)
                    if (a[c[i][1]][c[i][2]-1]=='P')
                    {
                        d[i]=1;
                        a[c[i][1]][c[i][2]-1]='Q';
                        dfs(s+1,summ+1);
                        d[i]=0;
                        a[c[i][1]][c[i][2]-1]='P';
                    }
                if (c[i][2]+1<=m && c[i][2]+1>=1)
                    if (a[c[i][1]][c[i][2]+1]=='P')
                    {
                        d[i]=1;
                        a[c[i][1]][c[i][2]+1]='Q';
                        dfs(s+1,summ+1);
                        d[i]=0;
                        a[c[i][1]][c[i][2]+1]='P';
                    }
                d[i]=1;
                dfs(s+1,summ);
                d[i]=0;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    getchar();
    ans=-(1<<30);
    k=-1;
    for (int i=1; i<=n; i++)
    {
       for (int j=1; j<=m; j++)
       {
           scanf("%c",&a[i][j]);
           if (a[i][j]=='W')
           {
               k++;
               c[k][1]=i;
               c[k][2]=j;
           }
       }
       getchar();
    }
    memset(d,0,sizeof(d));
    dfs(0,0);
    cout << ans << endl;
    return 0;
}
