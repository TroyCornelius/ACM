/*
 * Author:  Troy
 * Created Time:  2012/8/15 0:40:09
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
#define sf scanf
#define pf printf
#define Maxn 100110
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n;
int lim;
struct BIT
{
    int t[Maxn];
    void clr()
    {
        memset(t, 0, sizeof(t));
    }
    void add(int idx)
    {
        for (;idx <= lim; idx += idx&-idx) t[idx]++;
    }
    int query(int idx)
    {
        int ret = 0;
        for (;idx;idx-=idx&-idx) ret += t[idx];
        return ret;
    }
    int gsum(int a, int b)
    {
        return query(b) - query(a-1);
    }
};
BIT le, ri;

vi g[1010];
int main() 
{
    ios::sync_with_stdio(false);
    cin >>n;
    int num, k;
    REP(i, n)
    {
        cin >>k;
        REP(j, k)
        {
            cin >>num;
            g[i].pb(num);
            lim = max(lim, num);
        }
        sort(all(g[i]));
    }
    lim += 10;
    int ans = 0, c1, c2;
    REP(i, n)
    {
        if (g[i].size() == 0) continue;
        int p1 = (i + 1) % n, p2 = (i - 1 + n) % n;
        le.clr(); ri.clr();
        REP(j, g[p1].size()) le.add(g[p1][j]);
        REP(j, g[p2].size()) ri.add(g[p2][j]);
        //cout <<p1 <<" "<<p2;
        REP(j, g[i].size() - 1)
        {
            c1 = le.gsum(g[i][j], g[i][j+1]);
            c2 = ri.gsum(g[i][j], g[i][j+1]);
            if (c1 != c2) ans++;
        }
        //cout <<i <<" "<<ans <<endl;
    }
    cout <<ans <<endl;
    return 0;
}

