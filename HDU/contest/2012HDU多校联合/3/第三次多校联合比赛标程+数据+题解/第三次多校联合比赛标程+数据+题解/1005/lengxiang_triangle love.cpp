#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
#include <ctime>
#include <cstring>
using namespace std;

typedef long long LL;
typedef pair<string,int> PSI;
typedef vector<int> VI;
typedef vector<string> VS;

#define mp make_pair
#define F first
#define S second
#define sz(x) ((int)(x.size()))
#define rep(i,n) for(int i=0;i<(n);i++)
#define FOR(i,l,r) for(int i=(l);i<=(int)(r);i++)
#define FORD(i,r,l) for(int i=(r);i>=(int)(l);i--)
#define pb push_back
#define N 2005
char g[N][N];
int o[N];
int main()
{
    int T;
    freopen("Triangle love.in", "r", stdin);
    freopen("Triangle lengxiang_love.out", "w", stdout);
    scanf("%d",&T);
    rep(cas,T)
    {
        int n;
        scanf("%d",&n);
        rep(i,n)scanf("%s",&g[i]);
        int flag=0;
        memset(o,0,sizeof(o));
        rep(i,n)
        {
            int out = 0 , num = 0;
            rep(j,i)
                if(g[i][j] == '1')
                {
                    out+=o[j];
                    num++;
                    o[i]++;
                }
            if(num * (num - 1) / 2 < out)
            {
                flag=1;
                break;
            }
            rep(j,i)
                if(g[j][i] == '1')
                    o[j]++;
        }
        if(flag)
            printf("Case #%d: Yes\n",cas+1);
        else printf("Case #%d: No\n",cas+1);
    }
}