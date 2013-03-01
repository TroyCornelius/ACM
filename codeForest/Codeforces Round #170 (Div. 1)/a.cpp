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
const int N = 131;
int fa[N];
bool visit[N];
void init() {
    for (int i = 0; i < N; i++) {
        fa[i] = i;
    }
}
int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

bool Union(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    fa[a] = b;
    return true;
}

int a[N];
int main() {
    int n, m;
    cin >>n >>m;
    memset(visit, false, sizeof(visit));
    int ans = 0;
    init();
    int flag = 0;
    for (int i = 0, num; i < n; i++) {
        cin >> num;
        if (num == 0) ans++;
        for (int j = 0, x; j < num; j++) {
            cin >> a[j];
            flag = 1;
            visit[a[j]] = true;
            for (int k = 0; k < j; k++) {
                Union(a[j], a[k]);
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        if (visit[i] && fa[i] == i) {
            ans++;
        }
    }
    cout << ans - flag << endl;
    return 0;
}

