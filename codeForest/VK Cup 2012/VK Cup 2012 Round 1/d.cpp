/*
 * Author:  Troy
 * Created Time:  2012/3/11 23:26:41
 * File Name: d.cpp
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
#define Maxn 50050
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, k;
int cnt[Maxn];
vi g[Maxn];
long long ans;
void dfs(int u, int fa, int len)
{
    cnt[len]++;
    REP(i, g[u].size())
    {
        if (g[u][i] != fa)
        {
            dfs(g[u][i], u, len+1);
        }
    }
    return;
}
int main() 
{
    ios::sync_with_stdio(false);
    memset(cnt, 0, sizeof(cnt));
    cin >>n >>k;
    int x, y;
    REP(i, n-1)
    {
        cin >>x >>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(1, -1, 0);
    ans = 0;
    FOR(i, 0, k+1) ans += 1LL * cnt[i] * cnt[k-i];
    cout <<ans / 2 <<endl;
    return 0;
}

