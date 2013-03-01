/*
 * Author:  Teletubbies
 * Created Time:  2012年10月07日 星期日 17时00分37秒
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
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<long long, long long> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, m;
struct Rules{
    bool allow;
    pii seg;
    int ti;
}d[100100];

struct Query {
    long long pos;
    int ti;
}q[100100];
pii calc(char s[]) {
    int len = strlen(s);
    pii ret;
    long long x = 0, tmp = 0;
    bool flag = false;
    REP(i, len) {
        if (s[i] == '.') {
            x <<= 8;
            x += tmp;
            //cout <<x <<" "<<tmp <<endl;
            tmp = 0;
        }
        else if (s[i] == '/') {
            ret.fi = (x<<8) + tmp;
            tmp = 0;
            flag = true;
        }
        else {
            tmp = tmp * 10 + s[i] - '0';
        }
    }
    //cout <<flag <<" "<<tmp <<endl;
    if (flag) ret.se = ret.fi + (1LL<<(32-tmp))-1;
    else ret.se = ret.fi = (x << 8) + tmp;
    return ret;
}
char ans[100100];
long long num[300100];

int pw, col[300100*3];
int tot, H;

void build() {
    memset(col, -1, sizeof(col));
}
void push_down(int p) {
    col[p<<1] = col[p];
    col[p<<1|1] = col[p];
    col[p] = -1;
}

void modify(int p, int le, int ri, int l, int r, int val) {
    //cout <<le <<" "<<ri <<" "<<l <<" "<<r <<" "<<val <<endl;
    if (l <= le && ri <= r) {
        col[p] = val;
        //cout <<le <<" " <<ri <<" "<<val <<" mark"<<endl;
        return;
    }
    if (col[p] != -1) push_down(p);
    int mid = (le + ri)>>1;
    if (l <= mid) modify(p<<1, le, mid, l, r, val);
    if (r > mid) modify(p<<1|1, mid+1, ri, l, r, val);
}
int query(int p, int le, int ri, int pos) {
    //cout <<le <<" "<<ri <<" " <<pos <<" "<<col[p] <<endl; 
    if (le == ri && le == pos) return col[p];
    if (col[p] != -1) push_down(p);
    int mid = (le + ri)>>1;
    if (pos <= mid) return query(p<<1, le, mid, pos);
    else return query(p<<1|1, mid+1, ri, pos);
}
/*
void modify(int l, int r, int mark) {
    for (l += pw-1, r += pw+1; l^r^1; l>>=1, r>>=1) {
        if (~l&1) col[l^1] = mark;
        if (r&1) col[r^1] = mark;
    }
}

inline void push_leaf(int p) {
    int lson = p<<1, rson = p<<1|1;
    
}
void push_down(int p) {
    for (int i = H; i; i--) {
        if (col[p>>i] != -1) push_leaf(p>>i);
    }
}
int query(int p) {
    push_down(p);
    return col[p+=pw];
}
*/

int main() {
    freopen("access.in", "r", stdin);
    freopen("access.out", "w", stdout);
    while (~sf("%d", &n)) {
        char op[8], str[8];
        char addr[30];
        //num.clear();
        tot = 0;
        REP(i, n) {
            sf("%s%s%s", op, str, addr);
            //pf("%s %s %s\n", op, str, addr);
            if (op[0] == 'a') {
                d[i].allow = true;
                //d[i].ti = i;
                d[i].seg = calc(addr);
                //num.pb(seg.fi);
                //num.pb(seg.se);
                num[tot++] = d[i].seg.fi;
                num[tot++] = d[i].seg.se;
            }
            else {
                d[i].allow = false;
                //d[i].ti = i;
                d[i].seg = calc(addr);
                num[tot++] = d[i].seg.fi;
                num[tot++] = d[i].seg.se;
            }
            //cout <<d[i].seg.fi <<" "<<d[i].seg.se <<endl;
        }
        //cout <<tot <<endl;
        sf("%d", &m);
        REP(i, m) {
            sf("%s", addr);
            q[i].ti = i;
            pii tmp = calc(addr);
            q[i].pos = tmp.fi;
            //num.pb(q[i].pos);
            num[tot++] = q[i].pos;
            //cout <<q[i].pos <<endl;
        }
        //cout <<tot <<endl;
        sort(num, num+tot);
        //REP(i, tot) cout <<num[i] <<" ";
        //cout <<endl;
        int nn = unique(num, num+tot) - num;
        //cout <<tot <<endl;
        //REP(i, nn) cout <<num[i] <<" ";
        //cout <<endl;
        //cout <<nn <<" "<<num[nn-1] <<endl;
        build();
        //for (int i = 1; i <= nn; i++) cout <<query(1, 1, nn, i) <<" ";
        //cout <<endl <<"******************" <<endl;
        for (int i = n-1; i >= 0; i--) {
            int l = lower_bound(num, num+nn, d[i].seg.fi) - num + 1;
            int r = lower_bound(num, num+nn, d[i].seg.se) - num + 1;
            //cout <<l <<" "<<r <<" "<<i <<endl;
            modify(1, 1, nn, l, r, i);
        }
        //cout <<"fuck" <<endl;
        //
        //for (int i = 1; i <= nn; i++) cout <<query(1, 1, nn, i) <<" ";
        //cout <<endl <<"******************" <<endl;
        
        REP(i, m) {
            int idx = lower_bound(num, num+nn, q[i].pos) - num + 1;
            int p = query(1, 1, nn, idx);
            //cout <<p <<" "<<idx <<endl;
            if (p == -1 || d[p].allow) ans[i] = 'A';
            else ans[i] = 'D';
        }
        //cout <<"fuck" <<endl;
        ans[m] = '\0';
        puts(ans);
    }
    return 0;
}

