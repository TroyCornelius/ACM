/*
 * Author:  Troy
 * Created Time:  2012/4/6 12:52:57
 * File Name: 
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
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
typedef map<int,int>::iterator mit;
int n;
map<int, int> f, dp;

void init()
{
    int u, w;
    f.clear();
    dp.clear();
    sf("%d", &n);
    REP(i, n)
    {
        sf("%d%d", &u, &w);
        f[u] += w;        
    }
    //for (mit it = f.begin(); it != f.end(); it++) cout <<it->fi <<" "<<it->se <<endl;
}

int dfs(int rt)
{
    if (rt == 1) return 0;
    if (dp.find(rt) == dp.end())
    {
        int tmp = dfs(rt / 2);
        dp[rt] = tmp + f[rt];
    }
    return dp[rt];    
}
bool cmp(pii a, pii b)
{
    return a.se < b.se;
}
int main() 
{
    int T, ca = 0;
    sf("%d", &T);
    while (T--)
    {
        init();
        for (mit it = f.begin(); it != f.end(); it++) dfs(it->fi);  
        pii ans = *max_element(dp.begin(), dp.end(), cmp);
        pf("Case %d: %d\n", ++ca, ans.se);
    }
    return 0;
}

