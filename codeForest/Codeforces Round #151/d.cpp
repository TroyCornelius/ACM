/*
 * Author:  Troy
 * Created Time:  2012/11/22 0:08:20
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
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

const int N = 122222;
int cnt[N];
int color[N];
bool isExist[N];
map<int, bool> v[N];
int n, m;

int main() {
    while(cin >> n >> m) {
        memset(isExist, false, sizeof(isExist));
        int maxColor = 0;
        for(int i = 1; i <= n; i++) {
            cin >> color[i];
            maxColor = max(maxColor, color[i]);
            isExist[color[i]] = true;
        }
        for(int i = 0; i < N; i++) v[i].clear();
        for(int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            if(color[a] == color[b]) continue;
            if(v[color[a]].find(color[b]) == v[color[a]].end()) v[color[a]].insert(pair<int, bool>(color[b], true));
            if(v[color[b]].find(color[a]) == v[color[b]].end()) v[color[b]].insert(pair<int, bool>(color[a], true));
        }
        int ans = -1, ansColor = -1;
        for(int i = 1; i <= maxColor; i++) {
            if(isExist[i] && ans < (int)v[i].size()) {
                ans = v[i].size();
                ansColor = i;
            }
        }
        cout << ansColor << endl;
    }
    return 0;
}

