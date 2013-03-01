/*
 * Author:  Troy
 * Created Time:  2012/11/16 23:25:25
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
#define ll long long
#define sf scanf
#define pf printf
#define Maxn 100100
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, a[Maxn];
long long ans;
vi loc[21];
bool vis[1<<21+10];
inline void chk(int &num) {
    if (!vis[num]) ans++, vis[num] = true;
}
int main() {
    sf("%d", &n);
    REP(i, n) sf("%d", &a[i]);
    
    ans = 0;
    memset(vis, false, sizeof(vis));
    REP(i, n) {
        for (int j = 0, x = a[i]; x; x >>=1, j++) {
            if (x & 1) loc[j].pb(i);
        }
    }    
    
    int num;
    REP(i, n) {
        num = a[i];
        chk(num);
        while (true) {
            int mi = n+1;
            vi p;
            REP(j, 20) {
                if ((1<<j)&num) continue;
                vit it = upper_bound(all(loc[j]), i);
                if (it != loc[j].end()) {
                    if (*it < mi) {
                        p.clear();
                        mi = *it;
                        p.pb(j);
                    }
                    else if (*it == mi) {
                        p.pb(j);
                    }
                }
            }
            if (mi == n+1) break;
            else {
                REP(k, p.size()) num |= (1<<p[k]);
                chk(num);
            }
        }
    }
    cout <<ans <<endl;

    return 0;
}

