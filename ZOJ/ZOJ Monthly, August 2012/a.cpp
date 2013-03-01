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
//map<int,int>vis;
map<int,int>id;
vi loc[Maxn];
int cnt;
int pre[Maxn];
int main() 
{
    while (~sf("%d", &n)) {
        cnt = 0;
        id.clear();
        FOR(i, 1, n+1)  {
            sf("%d", &d[i]);
            if (id.find(d[i]) == id.end()) {
                loc[cnt].clear();
                id[d[i]] = cnt++;
            }
            loc[id[d[i]]].pb(i);
        }
        sf("%d", &m);
        REP(i, m) {
            sf("%d%d", &q[i].seg.fi, &q[i].seg.se);
            q[i].id = i;
        }
        sort(q, q+m);
        memset(ans, -1, sizeof(ans));
        memset(pre, -1, sizeof(pre));
        REP(i, cnt) {
            FORD(j, loc[i].size()-1, 1) {
                pre[loc[i][j]] = loc[i][j-1];
                //cout <<loc[i][j] <<" "<<loc[i][j-1] <<endl;
            }
            //cout <<"-------------------------" <<endl;
        }
        
        for (int i = 1; i <=n; i++) cout <<pre[i] <<" ";
        cout <<endl;
        int now = 0;
        /*
        for (int i = n; i > 0; i--) {
            if (pre[i] == -1) continue;
            if (now > m && q[now].seg.se < i) continue;
            while (now < m && i < q[now].seg.fi) now++;
            while (now < m && q[now].seg.fi <= pre[i]) {
                ans[q[now].id] = d[i];
                now++;
            }
        }
        */
        REP(i, m) {
            for (int j = q[i].seg.se; j >= q[i].seg.fi; j--) 
                if (pre[j] != -1 && pre[j] >= q[i].seg.fi) {
                    ans[q[i].id] = d[j];
                    break;
                }
        }
        REP(i, m)
            if (ans[i] == -1) puts("OK");
            else pf("%d\n", ans[i]);
        puts("");
        
        
        
    }
    return 0;
}

/*
7
1 2 3 2 1 1 2
5
1 3
2 4
1 7
5 6
5 7
*/   

