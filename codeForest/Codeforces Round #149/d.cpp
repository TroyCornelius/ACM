/*
 * Author:  Troy
 * Created Time:  2012/11/12 0:59:23
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
using namespace std;
const int inf = 1 << 29;
const double dinf = 1e30;
const ll linf = 1LL << 58;
const int N = 110000;
vector<int> vec[N];
int a[N];
int n, m;
bool visit[N];
int cnt[N];
void bfs() {
    queue<int> que;
    memset(visit, true, sizeof(visit));
    for(int i = 1; i <= n; i++) {
        cnt[i]++;
        if(cnt[i] == a[i]) {
            que.push(i);
        }
    }
    while(!que.empty()) {
        int u = que.front();
        que.pop();
        visit[u] = false;
        cnt[u]--;
        for(int i = 0; i < vec[u].size(); i++) {
            int v = vec[u][i];
            cnt[v]--;
            if(cnt[v] == a[v]) {
                que.push(v);
            }
        }
    }
}
int main() {
    cin >>n >>m;
    for(int i = 1; i <= n; i++) vec[i].clear();
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        vec[u].pb(v);
        vec[v].pb(u);
        cnt[u]++;
        cnt[v]++;
    }
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    bfs();
    vector<int> sch;
    for(int i = 1; i <= n; i++) {
        if(visit[i]) sch.pb(i);
    }
    cout << sch.size() << endl;
    for(int i = 0; i < sch.size(); i++) {
        printf("%d%c", sch[i], i == sch.size() - 1 ? '\n' : ' ');
    }
    return 0;
}
