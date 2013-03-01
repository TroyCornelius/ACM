/*
 * Author:  Troy
 * Created Time:  2012/8/15 0:03:42
 * File Name: b.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <time.h>
#include <cctype>
#include <functional>
#include <deque>
#include <iomanip>
#include <bitset>
#include <assert.h>
#include <numeric>
#include <sstream>
#include <utility>

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,b) FOR(i,0,b)
#define sf scanf
#define pf printf
#define maxn 150
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

bool maz[maxn][maxn];
bool vis[maxn];
int cnt, n, m;

void dfs(int u, int s, int fa, int len) 
{
    vis[u] = 1;
    for(int i = 1; i <= n; i++) 
    {
        if(i == fa || i == u) continue;
        if(maz[u][i])
        {
            if(!vis[i]) dfs(i, s, u, len + 1);
            else if(i == s)
            {
                if(!(len & 1)) cnt++;
            }
        }
    }
}
int main() 
{
    ios::sync_with_stdio(false);
    int a, b;
    cin >>n >>m;
    memset(maz, 0, sizeof(maz));
    memset(vis, false, sizeof(vis));
    for(int i = 0; i < m; i++) 
    {
        cin >>a >>b;
        maz[a][b] = maz[b][a] = 1;
    }
    cnt = 0;
    for(int i = 1; i <= n; i++) 
    {
        if(!vis[i]) dfs(i, i, -1, 0);
    }
    n -= cnt;
    if(n & 1) cnt++;
    cout << cnt << endl;
    return 0;
}
