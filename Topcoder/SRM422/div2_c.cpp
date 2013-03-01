/*
 * Author:  Troy
 * Created Time:  2012/7/12 23:01:11
 * File Name: div2_c.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>

#include <map>
#include <time.h>
#include <cctype>
#include <functional>

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
#define Maxn 250000
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
const int inf = 1 << 29;

typedef vector<int> vi;

int n;
int dp[55][Maxn+10];
vi bri;
    int dfs(int k, int D)
    {
        if (D > Maxn) return -inf;
        int &ret = dp[k][D];
        if (ret != -1) return ret;
        if (k == n) return D == 0 ? 0 : -inf;
        
        int val = bri[k];
        int fa = dfs(k+1, D);
        int fb = dfs(k+1, D + val);
        int fc;
        if (bri[k] > D) fc = D + dfs(k+1, bri[k] - D);
        else fc = bri[k] + dfs(k+1, D - bri[k]);
        ret = max(fa, max(fb, fc));
        return ret;        
    }

class EqualTowers
{
    public:
    int height(vector <int> bricks)
    {
        n = bricks.size();
        bri = bricks;
        memset(dp, -1, sizeof(dp));
        int ret = dfs(0, 0);
        return ret == 0 ? -1 : ret;
    }
};

EqualTowers test;
int main() 
{
    vi a;
    a.pb(2);a.pb(10);a.pb(11);
    cout <<test.height(a) <<endl;
    
    return 0;
}

