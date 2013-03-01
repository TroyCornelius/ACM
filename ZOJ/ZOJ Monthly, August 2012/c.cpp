/*
 * Author:  Troy
 * Created Time:  2012/8/26 13:01:05
 * File Name: c.cpp
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
#define Maxn 50010
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, m, d[Maxn];
int ans[Maxn];
int t[Maxn];

void add(int idx, int val) {
    for (;idx<=n; idx+=idx&-idx) t[idx] += val; 
}
int find(int k){
    int cnt=0, ret=0;
    for(int i=20; i>=0; i--) {
        ret+=(1<<i);
        if(ret >= n || cnt+t[ret] >= k) ret-=(1<<i);
        else cnt+=t[ret];
    }
    return ret+1;
}

int main() 
{
    while (~sf("%d", &n)) {
        memset(t, 0, sizeof(t));
        FOR(i, 1, n+1) add(i, 1);
        FOR(i, 1, n+1) {
            sf("%d", &d[i]);
            ans[i] = find(d[i]);
            add(ans[i], -1);
        }
        sf("%d", &m);
        int x;
        while (m--) {
            sf("%d", &x);
            pf("%d%c", ans[x], m == 0?'\n':' ');
        }
    }
    return 0;
}

