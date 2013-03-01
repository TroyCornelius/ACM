/*
 * Author:  Troy
 * Created Time:  2012/11/17 0:35:16
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
#define fst first
#define snd second
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,b) FOR(i,0,b)
#define ll long long
#define sf scanf
#define pf printf
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

typedef map<int, int> mm;
typedef map<int, int>::iterator mit;

const int N = 100010;
const int M = 33;
const int K = 3;
const int LIT = 2500;
const int INF = 1 << 30;
const int dir[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const int gcd(int a, int b) {return b ? gcd(b, a % b) : a;}

int n, m, h, t;
vi g[N];
set<int> fnd[N];

void out(int u, int v, vi cu, vi cv) {
    cout<<"YES"<<endl;
    printf("%d %d\n", u, v);
    for(int i = 0; i < cu.size(); i++) printf("%d ", cu[i]); 
    puts("");
    for(int i = 0; i < cv.size(); i++) printf("%d ", cv[i]); 
    puts("");
}

int check(int u, int v) {
    set<int> ret;
    vi cu, cv;
    int s = g[v].size(), need = (h + t) * 2;
    for(int i = 0; i < s && cv.size() < t && ret.size() < need; i++) {
        int x = g[v][i];
        if(x == u) continue;
        if(fnd[u].count(x)) ret.insert(x);
        else cv.pb(x);
    }
    s = g[u].size();
    for(int i = 0; i < s && cu.size() < h; i++) {
        int x = g[u][i];
        if(x == v) continue;
        if(ret.count(x)) continue;
        else cu.pb(x);
    }
    
    for(set<int>::iterator it = ret.begin(); it != ret.end(); it++) {
        int x = *it;
        if(cu.size() < h) cu.pb(x);
        else if(cv.size() < t) cv.pb(x);
        else break;
    }
    
    if(cu.size() != h || cv.size() != t) return 0;
    else out(u, v, cu, cv);
    return 1;
}

void solve()
{
    for(int i = 1; i <= n; i++) {
        int s = g[i].size();
        for(int j = 0; j < s; j++) {
            int v = g[i][j];
            int di = s - 1, dj = g[v].size() - 1;
            if(di < h) continue;
            if(dj < t) continue;
            if(check(i, v)) return ;
        }
    }
    cout<<"NO"<<endl;
}

int main()
{
    sf("%d%d%d%d", &n, &m, &h, &t);
    for(int i = 1; i <= n; i++) g[i].clear(), fnd[i].clear();
    for(int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].pb(v); 
        fnd[u].insert(v);
        g[v].pb(u); 
        fnd[v].insert(u);
    }
    solve();
    
    return 0;
}

