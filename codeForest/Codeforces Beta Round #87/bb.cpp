#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int a[1000][1000];
int ans,n,m,k;
char tmp;


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
           scanf("%c",&tmp);
           if (tmp=='P')
           {
                a[i][j]=0;
           }
           else
           if (tmp=='W')
           {
               a[i][j]=1;
           }
           else a[i][j]=-1;
       }
       getchar();
    }
  //  for (int i=0; i<=k; i++) cout << c[i][1] << " " << c[i][2]<<endl;
  //  cout << k << endl;
    ans=0;
    for (int i=1; i<=n;i++)
    {
        for (int j=1; j<=m-1; j++)
        {
            if (a[i][j]==0)
            {
                if (a[i][j+1]==1)
                {
                    ans++;
                    a[i][j+1]=-1;
                }
            }
            else
            if (a[i][j]==1)
            {
                if (a[i][j+1]==0)
                {
                    ans++;
                    a[i][j]=-1;
                }
            }
        }
    }
    for (int j=1; j<=m; j++)
    {
        for (int i=1; i<=n-1; i++)
        {
             if (a[i][j]==0)
            {
                if (a[i+1][j]==1)
                {
                    ans++;
                    a[i+1][j]=-1;
                }
            }
            else
            if (a[i][j]==1)
            {
                if (a[i+1][j]==0)
                {
                    ans++;
                    a[i][j]=-1;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}

