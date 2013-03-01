/*
 * Author:  Troy
 * Created Time:  2012/8/26 12:03:50
 * File Name: a.cpp
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
#define Maxn 500100
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, d[Maxn];
int m;
int ans[50100];
struct Query {
    pii seg;
    int id;
    bool operator<(const Query &b) const {
        return seg.se > b.seg.se || (seg.se == b.seg.se && seg.fi < b.seg.fi);
    }
}q[50100];
map<int,int>vis;
int main() 
{
    while (~sf("%d", &n)) {
        FOR(i, 1, n+1) sf("%d", &d[i]);
        sf("%d", &m);
        REP(i, m) {
            sf("%d%d", &q[i].seg.fi, &q[i].seg.se);
            q[i].id = i;
        }
        sort(q, q+m);
        int now = 0;
        int head = n, tail = n;
        vis.clear();
        memset(ans, -1, sizeof(ans));
        while (tail > 0) {
            //cout <<tail <<" "<<d[tail] <<" is: " <<vis[d[tail]] <<endl;
            while (tail > 0 && vis[d[tail]] == 0) {
                vis[d[tail]] = 1;
                tail--;
            }
            if (tail <= 0) break;
            while (head > tail && d[head] != d[tail]) {
                vis[d[head]] = 0;
                head--;
            }
            while (now < m && q[now].seg.se >= head) {
                if (q[now].seg.fi <= tail) ans[q[now].id] = d[tail];
                now++;
            }
            //cout <<head <<" "<<tail <<endl;
            //REP(i, m) cout <<ans[i] <<" ";
            //cout <<endl;
            head--;
            tail--;
        }
        REP(i, m) 
            if (ans[i] == -1) puts("OK");
            else pf("%d\n", ans[i]);
        puts("");
        
    }
    return 0;
}

