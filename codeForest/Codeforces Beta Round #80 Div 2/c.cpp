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
#define Maxn 5000
#define inf 999999999
#define pb push_back
#define MyMax 110
using namespace std;


int n,m,ans,cnt;
int dfn[MyMax];
bool flag;
bool g[MyMax][MyMax];
int s;

void DFS(int v)
{
    for(int i=1;i<=n;i++)
    {
        if(g[v][i])
        {
            if(!dfn[i])
            {    
                g[i][v]=0;
                dfn[i]=dfn[v]+1;
                DFS(i);
            }
            else
            {
                int tmp=dfn[v]-dfn[i]+1;
               // if(tmp>ans) ans=tmp;
               if (s==0) flag=true;
               if (s==0) s++;
              //  cnt += tmp;
                if (tmp < 3) 
                {
                   flag = false;
                   return;       
                }
                
                g[i][v]=0;
            }
        }
    }
}

int main()
{
    int i,a,b,T;
        ans=0; cnt = 0;
        flag =false;
        memset(g,0,sizeof(g));
        memset(dfn,0,sizeof(dfn));
        cin>>n>>m;        
        for(i=0;i<m;i++)
        {
            cin>>a>>b;
            g[a][b]=g[b][a]=1;
        }
        for(i=1;i<=n;i++)
        {
            if(!dfn[i])
            {
                dfn[i]=1;
                DFS(i);
            }
        }
       // cout <<ans <<endl;
        if (flag==true) cout <<"FHTAGN!" <<endl;
        else cout <<"NO" <<endl;
       // system("pause");
    return 0;
}
