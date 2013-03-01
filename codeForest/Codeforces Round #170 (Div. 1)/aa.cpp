/*
 * Author:  Troy
 * Created Time:  2013/2/28 23:35:37
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
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, m;
bool con[110][110], vis[110];
int fa[110], ans;
int find(int a) {
    if (fa[a] == a) return a;
    else return fa[a] = find(fa[a]);
}
int main() {
    cin >>n >>m;
    memset(con, false, sizeof(con));
    int x, a;
    ans = 0;
    int tot = 0;
    FOR(i, 1, n+1) {
        cin >>x;
        if (!x) ans++;
        while (x--) {
            cin >>a;
            con[i][a] = true;
            tot = 1;
        }
    }
    FOR(i, 1, n+1) fa[i] = i;
    FOR(i, 1, n+1) 
        FOR(j, i+1, n+1) 
            FOR(k, 1, m+1) {
                if (con[i][k] && con[j][k]) {
                    fa[find(i)] = find(j);
                }
            }
    vi cnt;
    FOR(i, 1, n+1) {
        find(i);
        cnt.pb(fa[i]);
    }
    //FOR(i, 1, n+1) cout <<fa[i] <<endl;
    sort(all(cnt));
    cout <<unique(all(cnt)) - cnt.begin()<<endl;
    return 0;
}

