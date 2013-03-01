/*
 * Author:  Troy
 * Created Time:  2012/11/3 20:19:37
 * File Name: 1000.cpp
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
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

struct Tnode{
    int a[13];
    int val;
}st;

int n, tar;
int d[2000000];
inline int calc(int num[]) {
    int ret = 0;
    for (int i = 0; i < n; i++)
        ret = ret * 3 + num[i];
    return ret;
}
inline int work() {
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
        if (st.a[i] == 1) cnt1++;
        else if (st.a[i] == 2) cnt2++;
    int ret = 0;
    REP(i, cnt1) ret = ret * 3 + 1;
    REP(i, n-cnt1-cnt2) ret *= 3;
    REP(i, cnt2) ret = ret * 3 + 2;
    return ret;
}
queue<Tnode> que;
int bfs() {
    while (!que.empty()) que.pop();
    memset(d, -1, sizeof(d));
    REP(i, n) sf("%d", &st.a[i]);
    tar = work();
    int v = calc(st.a);
    st.val = v;
    d[v] = 0;
    if (v == tar) return 0;
    que.push(st);
    int tmp[13];
    Tnode nt;
    while (!que.empty()) {
        Tnode now = que.front();
        que.pop();
        
        REP(i, n) {
            if (i >= 1 && now.a[i] == 1 && now.a[i-1] == 0) {
                memcpy(tmp, now.a, sizeof(now.a));
                swap(tmp[i], tmp[i-1]);
                v = calc(tmp);
                if (d[v] == -1) {
                    d[v] = d[now.val] + 1;
                    if (v == tar) return d[v];
                    nt.val = v;
                    memcpy(nt.a, tmp, sizeof(tmp));
                    que.push(nt);
                }
            }
            if (i - 2 >= 0 && now.a[i] == 1 && now.a[i-1] != 0 && now.a[i-2] == 0) {
                memcpy(tmp, now.a, sizeof(now.a));
                swap(tmp[i], tmp[i-2]);
                v = calc(tmp);
                if (d[v] == -1) {
                    d[v] = d[now.val] + 1;
                    if (v == tar) return d[v];
                    nt.val = v;
                    memcpy(nt.a, tmp, sizeof(tmp));
                    que.push(nt);
                }

            }
        }
        for (int i = n-1; i >= 0; i--) {
            if (i + 1 < n && now.a[i] == 2 && now.a[i+1] == 0) {
                memcpy(tmp, now.a, sizeof(now.a));
                swap(tmp[i], tmp[i+1]);
                v = calc(tmp);
                if (d[v] == -1) {
                    d[v] = d[now.val] + 1;
                    if (v == tar) return d[v];
                    nt.val = v;
                    memcpy(nt.a, tmp, sizeof(tmp));
                    que.push(nt);
                }
            }
            if (i + 2 < n && now.a[i] == 2 && now.a[i+1] != 0 && now.a[i+2] == 0) {
                memcpy(tmp, now.a, sizeof(now.a));
                swap(tmp[i], tmp[i+2]);
                v = calc(tmp);
                if (d[v] == -1) {
                    d[v] = d[now.val] + 1;
                    if (v == tar) return d[v];
                    nt.val = v;
                    memcpy(nt.a, tmp, sizeof(tmp));
                    que.push(nt);
                }
            }
        }
    }
    return -1;
}
int main() {
    while (~sf("%d", &n)) {
        int ans = bfs();
        pf("%d\n", ans);
    }
    return 0;
}

