/*
 * Author:  Troy
 * Created Time:  2012/11/12 0:14:40
 * File Name: e.cpp
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
#define ll long long
#define sf scanf
#define pf printf
#define Maxn 1000110
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

const int BN = 4;
int n, m;
int sum[Maxn*3][BN];
int mark[Maxn*3][BN];
//int le[Maxn*3], ri[Maxn*3];
int two[BN];
void push_up(int p) {
    REP(i, BN)
        sum[p][i] = sum[p<<1][i] + sum[p<<1|1][i];
}

void build(int p, int l, int r) {
    //le[p] = l; ri[p] = r;
    if (l == r) {
        int num;
        sf("%d", &num);
        REP(i, BN) {
            if (num&1) sum[p][i] = 1;
            else sum[p][i] = 0;
            num >>=1;
        }
        return;
    }
    int mid = (l + r) >>1;
    build(p<<1, l, mid);
    build(p<<1|1, mid+1, r);
    push_up(p);
}
/*
void xor_push_down(int p, int i) {
    int lson = (p<<1), rson = (p<<1|1);
    sum[lson][i] = ri[lson] - le[lson] + 1 - sum[lson][i];
    mark[lson][i] ^= 1;
    sum[rson][i] = ri[rson] - le[rson] + 1 - sum[rson][i];
    mark[rson][i] ^= 1;
    mark[p][i] = 0;
}
void modify_xor(int p, int l, int r, int x) {
    if (l <= le[p] && ri[p] <= r) {
        int tmp = x;
        REP(i, BN) {
            if (tmp&1) {
                mark[p][i] ^= 1;
                sum[p][i] = ri[p] - le[p] + 1 - sum[p][i];
            }
            tmp >>=1;
        }
        return;
    }
    REP(i, BN)
        if (mark[p][i] == 1) xor_push_down(p, i);
    int mid = (le[p] + ri[p]) >>1;
    if (l <= mid) modify(p<<1, l, r, x);
    if (r > mid) modify(p<<1|1, l, r, x);
    push_up(p);
}
void and_push_down(int p, int i) {
    
}
void modify_and(int p, int l, int r, int x) {
    if (l <= le[p] && ri[p] <= r) {
        int tmp = x;
        REP(i, BN) {
            if (tmp & 1) {
                mark_and[p][i] = 1;
                sum[p][i] = ri[p] - le[p] + 1;
            }
            else {
                mark_and[p][i] = 0;
                sum[p][i] = 0;
            }
            tmp >>= 1;
        }
        return;
    }
    REP(i, BN)
        if (mark_and[p][i] != -1) and_push_down(p, i);
    int mid = (le[p] + ri[p]) >>1;
    if (l <= mid) modify(p<<1, l, r, x);
    if (r > mid) modify(p<<1|1, l, r, x);
    push_up(p);
}
*/
//cmd : 1 for and, 2 for or, 3 for xor
void push_down(int p, int i, int le, int ri) {
    int lson = (p<<1), rson = (p<<1|1);
    int mid = (le + ri) >>1;
    if (mark[lson][i]) push_down(p<<1, i, le, mid);
    if (mark[rson][i]) push_down(p<<1|1, i, mid+1, ri);
    if (mark[p][i] == 1) {
        sum[lson][i] = sum[rson][i] = 0;
        mark[lson][i] = mark[rson][i] = 1;
        mark[p][i] = 0;
    }
    else if (mark[p][i] == 2) {
        sum[lson][i] = mid - le + 1;
        sum[rson][i] = ri - (mid+1) + 1;
        mark[lson][i] = mark[rson][i] = 2;
        mark[p][i] = 0;
    }
    else if (mark[p][i] = 3) {
        sum[lson][i] = mid - le + 1 - sum[lson][i];
        mark[lson][i] = 3;
        sum[rson][i] = ri - (mid+1) + 1 - sum[rson][i];
        mark[rson][i] = 3;
        mark[p][i] = 0;
    }
    return;
}
void modify(int p, int l, int r, int le, int ri, int x, int cmd) {
    REP(i, BN) 
        if (mark[p][i] != 0) push_down(p, i, le, ri);
    if (l <= le && ri <= r) {
        //cout <<l <<" "<<r <<" --- " <<le[p] <<" "<<ri[p] <<" : " <<x <<" " <<cmd <<endl;
        //REP(i, BN) cout <<sum[p][i] <<" ";
        //cout <<endl <<" ********************* " <<endl;
        int tmp = x;
        REP(i, BN) {
            //cout <<tmp <<" "<<i <<endl;
            if (tmp & 1) {
                if (cmd == 1) {
                    //continue;
                }
                else if (cmd == 2) {
                    sum[p][i] = ri - le + 1;
                    mark[p][i] = 2;
                }
                else if (cmd == 3) {
                    sum[p][i] = ri - le + 1 - sum[p][i];
                    mark[p][i] = 3;
                    //cout <<sum[p][i] <<" --- " <<endl;
                }
            }
            else {
                if (cmd == 1) {
                    sum[p][i] = 0;
                    mark[p][i] = 1;
                }
                else if (cmd == 2) {
                    //continue;
                }
                else if (cmd == 3) {
                    //continue;
                }
            }
            tmp >>= 1;
        }
        //REP(i, BN) cout <<sum[p][i] <<" ";
        //cout <<endl <<" ********************* " <<endl;
        return ;
    }
    //int mid = (le[p] + ri[p]) >>1;
    int mid = (le + ri) >>1;
    if (l <= mid) modify(p<<1, l, r, le, mid, x, cmd);
    if (r > mid) modify(p<<1|1, l, r, mid+1, ri, x, cmd);
    push_up(p);
}
int query(int p, int l, int r, int le, int ri) {
    int ret = 0;
    REP(i, BN)
        if (mark[p][i]) push_down(p, i, le, ri);
    if (l <= le && ri <= r) {
        REP(i, BN)
            ret += two[i] * sum[p][i];
        return ret;
    }
    //int mid = (le[p] + ri[p]) >>1;
    int mid = (le + ri) >>1;
    if (l <= mid) ret += query(p<<1, l, r, le, mid);
    if (r > mid) ret += query(p<<1|1, l, r, mid+1, ri);
    return ret;
}
int main() {
    int T;
    sf("%d", &T);
    two[0] = 1;
    for (int i = 1; i < BN; i++) two[i] = two[i-1] * 2;
    while (T--) {
        sf("%d%d", &n, &m);
        //for (int i = 1; i <= n; i++) sf("%d", &a[i]);
        memset(sum, 0, sizeof(sum));
        memset(mark, 0, sizeof(mark));
        build(1, 1, n);
        int l, r, x;
        int ans;
        char op[5];
        while (m--) {
            sf("%s", op);
            if (op[0] == 'S') {
                sf("%d%d", &l, &r);
                l++; r++;
                ans = query(1, l, r, 1, n);
                pf("%d\n", ans);
            }
            else if (op[0] == 'A'){
                sf("%d%d%d", &x, &l, &r);
                l++; r++;
                modify(1, l, r, 1, n, x, 1);
            }
            else if (op[0] == 'O'){
                sf("%d%d%d", &x, &l, &r);
                l++; r++;
                modify(1, l, r, 1, n, x, 2);
            }
            else if (op[0] == 'X'){
                sf("%d%d%d", &x, &l, &r);
                l++; r++;
                modify(1, l, r, 1, n, x, 3);
            }
        }
    }
    return 0;
}


