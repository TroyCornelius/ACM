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
#define Maxn 200110
#define ll long long
using namespace std;
const int inf=0x7fffffff;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, m;
struct Tnode {
    int x, y, di;
    int id;
    bool operator<(const Tnode &b) const{
        return x < b.x || (x == b.x && y < b.y) ;
    }
}d[Maxn];

bool b[Maxn];
int xx[Maxn], nx;
int nid[Maxn], st[Maxn];

inline ll ABS(ll fx) {
    return fx < 0 ? -fx : fx;
}

int bsearch(int yys) {
    int le = 0, ri = nx - 1;
    while (le <= ri) {
        int mid = (le+ri)>>1;
        if (xx[mid] == yys) return mid;
        else if (xx[mid] < yys) le = mid + 1;
        else ri = mid-1;
    }
    return -1;
}


void get_range(int le, int ri, ll lval, ll rval, int &pl, int &pr) {
    int tl = le, tr = ri;
    pl = ri + 1;
    pr = le - 1;
    while (tl <= tr) {
        int mid = (tl + tr) >>1;
        if ((ll)d[mid].y >= lval) {
            pl = mid;
            tr = mid - 1;
        }
        else tl = mid+1;
    }
    
    tl = le, tr = ri;
    while (tl <= tr) {
        int mid = (tl + tr) >>1;
        if ((ll)d[mid].y <= rval) {
            pr = mid;
            tl = mid + 1;
        }
        else tr = mid-1;
    }
}

int que[Maxn*10];
int bfs(int ter) {
    if (b[ter]) return 0;
    int head, tail;
    head = tail = 0;
    que[tail++] = ter;
    b[ter] = true;
    while (head < tail) {
        int now = que[head++];
        int tx = bsearch(d[now].x);
        
        for (int i = tx; i < nx && ABS(0LL + xx[i] - d[now].x) <= (ll)d[now].di; i++) {
            int le = st[i], ri = st[i+1]-1;
            int pl, pr;
            get_range(le, ri, 0LL+d[now].y-d[now].di, 0LL+d[now].y+d[now].di, pl, pr);
            while (pl <= pr) {
                if (!b[pl]) {
                    que[tail++] = pl;
                    b[pl] = true;
                }
                pl++;
            }
        }
        
        
        for (int i = tx-1; i >= 0 && ABS(0LL + xx[i] - d[now].x) <= (ll)d[now].di; i--) {
            int le = st[i], ri = st[i+1]-1;
            int pl, pr;
            get_range(le, ri, 0LL+d[now].y-d[now].di, 0LL+d[now].y+d[now].di, pl, pr);
            while (pl <= pr) {
                if (!b[pl]) {
                    que[tail++] = pl;
                    b[pl] = true;
                }
                pl++;
            }
        }
    }
    //cout <<1123<<endl;
    return tail;
}


int main() {
    int ca = 0, x, y, di;
    while (~sf("%d", &n), n) {
        REP(i, n)  {
            sf("%d%d%d", &x, &y, &di);
            d[i].x = x+y; d[i].y = x - y; d[i].di = di;
            d[i].id = i;
        }
        memset(b, false, sizeof(b));
        sort(d, d+n);
        int pre = -inf;
        nx = 0 ;
        REP(i, n) {
            nid[d[i].id] = i;
            if (d[i].x != pre) {
                pre = d[i].x;
                xx[nx] = d[i].x;
                st[nx++] = i;
            }
        }
        
        st[nx] = n;
        int Q, yyh;
        sf("%d", &Q);
        pf("Case #%d:\n", ++ca);
        while (Q--) {
            sf("%d", &yyh);
            yyh--;
            //cout <<nid[yyh] <<endl;
            pf("%d\n", bfs(nid[yyh]));
        }
    }
    return 0;
}

