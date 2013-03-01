/*
 * Author:  Troy
 * Created Time:  2013/2/12 0:42:45
 * File Name: d.cpp
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
#define ull unsigned long long
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

char str[1555], bad[30];
map<pair<ull, ull>, int> vis;
int k;
int main() {
    sf("%s", str);
    sf("%s", bad);
    sf("%d", &k);
    int ans = 0, n = strlen(str);
    
    ull h1, h2;
    REP(i, n) {
        h1 = h2 = 0;
        int cnt = 0;
        FOR(j, i, n) {
            if (bad[str[j]-'a'] == '0') cnt++;
            if (cnt > k) break;
            h1 = (h1 * 23) + (str[j]-'a'+1);
            h2 = (h2 * 31) + (str[j]-'a'+1);
            if (vis.find(mp(h1, h2)) == vis.end()) {
                vis[mp(h1,h2)] = 1;
                ans++;
            }
        }
    }
    pf("%d\n", ans);
    return 0;
}

