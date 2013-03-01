/*
 * Author:  Troy
 * Created Time:  2013/3/1 1:09:32
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
using namespace std;
const int maxint = -1u>>1;
const int inf = 1<<30;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
const double dinf = 1e30;
const ll linf = 1LL << 55;
const int N = 1111;
pii point[N];
int n;
int ans, eh[N], tot, low[N], p[N]; 
double anscost;
double dist[N];
int S, T; //源，汇
struct Edge {
    int u, v;
    double cost;
    int cap, flow, next; 
} et[3333333];
bool visit[N];
bool spfa() {
    queue<int> que;
    memset(visit, false, sizeof (visit));
    memset(p, -1, sizeof (p));
    memset(low, 0, sizeof(low));
    for (int i = 0; i < N; i++) {
        dist[i] = dinf;
    }
    visit[S] = true, low[S] = inf, dist[S] = 0.0;
    que.push(S);
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        visit[u] = false;
        for (int i = eh[u]; i != -1; i = et[i].next) {
            int v = et[i].v;
            double cost = et[i].cost;
            int cap = et[i].cap, flow = et[i].flow;
            if (flow < cap && dist[u] + cost + 1e-8 < dist[v]) {
                dist[v] = dist[u] + cost;
                p[v] = i; //注意，这里是 i
                low[v] = min(low[u], cap - flow);
                if (!visit[v]) {
                    visit[v] = true;
                    que.push(v);
                }
            }
        }
    }
    return dist[T] + 1e-8 < dinf;
}

void costflow() {
    ans = 0, anscost = 0;
    while (spfa()) {
        int x = p[T];
        ans += low[T];
        anscost += low[T] * dist[T];
        while (x != -1) {
            et[x].flow += low[T];
            et[x^1].flow -= low[T];
            et[x^1].cost = -et[x].cost;
            x = p[et[x].u];
        }
    }
}
void add(int u, int v, double cost, int cap, int flow) {
    Edge e = {u, v, cost, cap, flow, eh[u]};
    et[tot] = e;
    eh[u] = tot++;
}
void addedge(int u, int v, double cost, int cap) {
    add(u, v, cost, cap, 0), add(v, u, -cost, 0, 0);
}
void init() {
    tot = 0;
    memset(eh, -1, sizeof (eh));
}

double getDist(pii a, pii b) {
    return sqrt(1.0 * (a.fi - b.fi) * (a.fi - b.fi) + 1.0 * (a.se - b.se) * (a.se - b.se));
}

bool cmp(pii a, pii b) {
    return a.se > b.se;
}

bool check() {
    sort(point, point+n, cmp);
    if (point[0].se == point[1].se) return false;
    else {
        ll tmp = 2;
        int i = 1;
        while (i < n) {
            int j = i+1;
            for (; j < n && point[i].se == point[j].se; j++);
            if (tmp < j - i) return false;
            else tmp += j - i;
            i = j;
        }
    }
    return true;
}

int main() {
    while (cin >> n) {
        pii xpoint = mp(inf, inf);
        for (int i = 0; i < n; i++) {
            cin >> point[i].fi >> point[i].se;
            if (point[i].se > xpoint.se) {
                xpoint = point[i];
                S = i;
            }
        }
        if (!check()) {
            puts("-1");
            continue;
        }
        T = 2 * n;
        init();
        for (int i = 0; i < n; i++) {
            addedge(i, i + n, -(1e8), 2);
        }
        for (int i = 0; i < n; i++) {
            addedge(i + n, T, 0, 1);
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (point[i].se > point[j].se) {
                    addedge(i + n, j, getDist(point[i], point[j]), 1);
                    //cout << i + n << " " << j << endl;
                }
            }
        }
        costflow();
        for (int i = 0; i < n; i++) {
            anscost += et[i << 1].flow * (1e8);
        }
        printf("%.15f\n", anscost);
    }
    return 0;
}

