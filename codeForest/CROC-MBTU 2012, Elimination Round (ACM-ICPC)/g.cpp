/*
 * Author:  Troy
 * Created Time:  2012/11/20 1:29:26
 * File Name: g.cpp
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
const int N = 11111;
vector<int> vec[N];
map<string, int> id;
int n, m;
int cnt[N];
int ans[N];
bool aFriend[N];
void work(int a) {
    memset(cnt, 0, sizeof(cnt));
    memset(aFriend, false, sizeof(aFriend));
    aFriend[a] = true;
    for(int i = 0; i < vec[a].size(); i++) {
        int b = vec[a][i];
        aFriend[b] = true;
    }
    int maxNumber = 0;
    for(int i = 1; i <= n; i++) {
        if(aFriend[i]) continue;
        for(int j = 0; j < vec[i].size(); j++) {
            if(aFriend[vec[i][j]]) cnt[i]++;
        }
        maxNumber = max(maxNumber, cnt[i]);
    }
    for(int i = 1; i <= n; i++) {
        if(!aFriend[i] && cnt[i] == maxNumber) ans[a]++;
    }
}

int main() {
    while(cin >> m) {
        n = 0;
        id.clear();
        for(int i = 0; i < N; i++) vec[i].clear();
        for(int i = 0; i < m; i++) {
            string a, b;
            int u, v;
            cin >> a >> b;
            if(id[a] == 0) {
                id[a] = ++n;
            }
            u = id[a];
            if(id[b] == 0) {
                id[b] = ++n;
            }
            v = id[b];
            vec[u].pb(v);
            vec[v].pb(u);
        }
        cout << n << endl;
        memset(ans, 0, sizeof(ans));
        for(int i = 1; i <= n; i++) {
            work(i);
        }
        for(map<string, int>::iterator it = id.begin(); it != id.end(); it++) {
            cout << it->fi << " " << ans[it->se] << endl;
        }
    }
    return 0;
}

