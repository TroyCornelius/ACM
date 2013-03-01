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

const int inf = 1 << 29;
int maz[55][55], lx[55], ly[55], match[55], sx[55], sy[55], slack[55];
int n, m, x[55], g[55][55], v[55];
bool con[55][55];
//map<int,bool> vis;

vi vec;
int tot;
bool flag = false;
void work(int p)
{
    vec.clear();
    int mid = x[p] / 2, sum;
    FOR(i, 0, 1<<mid)
    {
        sum = 0;
        REP(j, mid)
            if ((1<<j)&i) sum += g[p][j];
      //  vis[sum] = true;
        vec.pb(sum);
    }
    sort(all(vec));
    vector<int>::iterator en = unique(all(vec));
    FOR(i, 0, 1<<(x[p] - mid))
    {
        sum = 0;
        REP(j, (x[p]-mid))
            if ((1<<j)&i) sum += g[p][j+mid];
        REP(x, m)
        if (v[x] >= sum)
        {
            vector<int>::iterator it = lower_bound(vec.begin(), en, v[x]-sum);
            if (it != en && *it == v[x]-sum) {
                flag = true;
                con[x][p] = true;
            }
        }
    }
}


void build() {
    if (n < m) n = m;
    memset(maz, 0, sizeof(maz));
    memset(ly, 0, sizeof(ly));
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) { 
            if(con[i-1][j-1]) maz[i][j] = v[i-1];
        }
    }
    for(int i = 1; i <= m; i++) {
        lx[i] = -inf;
        for(int j = 1; j <= n; j++) {
            lx[i] = max(lx[i], maz[i][j]);
        }
    }
}

bool dfs(int t) {
    sx[t] = 1;
    for(int i = 1; i <= n; i++) {
        if(sy[i]) continue;
        if(maz[t][i] == lx[t] + ly[i]) {
            sy[i] = 1;
            if(match[i] == -1 || dfs(match[i])) {
                match[i] = t;
                return 1;
            }
        } else slack[i] = min(slack[i], lx[t] + ly[i] - maz[t][i]);
    }
    return 0;
}

void Change() {
    int Min = inf;
    for(int i = 1; i <= n; i++) 
        if(!sy[i]) Min = min(Min, slack[i]);
    for(int i = 1; i <= m; i++)
        if(sx[i]) lx[i] -= Min;
    for(int i = 1; i <= n; i++) {
        if(sy[i]) ly[i] += Min;
        else slack[i] -= Min;
    }
        
}

int KM() { 
    if (n < m) n = m;
    int ans = 0;
    int cnt = 0;
    memset(match, -1, sizeof(match));
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++) {
            slack[j] = inf;
        }
        cnt = 0;
        while(1) {
            memset(sy, 0, sizeof(sy));
            memset(sx, 0, sizeof(sx));
            if(dfs(i)) break;
            Change();
        }
    }
    for(int i = 1; i <= n; i++)
        if(match[i] != -1) ans += maz[match[i]][i];
    return ans;
}

int main() 
{
    int T;
    sf("%d", &T);
    while (T--)
    {
        sf("%d%d", &m, &n);
        flag = false;
        memset(con, false, sizeof(con));
        REP(i, m) sf("%d", &v[i]);
        REP(i, n)
        {
            sf("%d", &x[i]);
            REP(j, x[i]) sf("%d", &g[i][j]);
        }
        tot = 0;
        REP(i, n) work(i);
       /*
        REP(i, m)
        {
            REP(j, n)
                cout <<con[i][j] <<" ";
            cout <<endl;
        }*/
          
        build();
        int ans = 0;
        if(flag) ans = KM();
        //cout << ans << endl;
        pf("%d\n", ans);
        
    }
    
    return 0;
}

