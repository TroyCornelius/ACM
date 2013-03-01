/*
 * Author:  Troy
 * Created Time:  2012/11/10 16:24:20
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

int n;
int ans[222][222];
bool vis[222];
inline int search() {
    for (int i = 1; i <= 2*n+1; i++)
        if (!vis[i]) return i;
    return -1;
}
void solve(int id, int st) {
    memset(vis, false, sizeof(vis));
    int p = st;
    bool flag;
    vis[st] = true;
    
    while (true) {
        int i = search();
        if (i == -1) break;
        vis[i] = true;
        for (int j = 1; j <= 2*n+1; j++) {
            if (!vis[j] && !ans[i][j]) {
                ans[i][j] = ans[j][i] = id;
                vis[j] = true;
                break;
            }
        }
    }
        for (int i = 1; i <= 2*n+1; i++) {
            for (int j = 1; j <= 2*n+1; j++)
                pf("%d%c", ans[i][j], j == 2*n+1?'\n':' ');
        }
        cout <<"***************" <<endl;
        //*/
        /*
    for (int i = 1; i <= 2*n+1; i++)
        for (int j = 1; j <= 2*n+1; j++) {
            if (i == j) continue;
            if (!vis[i] && !vis[j] && ans[i][j] == 0) {
                ans[i][j] = ans[j][i] = id;
                vis[i] = vis[j] = true;
            } 
        }
        */
}
int main() {
    while (cin >>n) {
        memset(ans, 0, sizeof(ans));
        int p = 0;
        for (int i = 1; i <= 2*n+1; i++) {
            p++;
            solve(i, p);
        }
        for (int i = 1; i <= 2*n+1; i++) {
            for (int j = 1; j <= 2*n+1; j++)
                pf("%d%c", ans[i][j], j == 2*n+1?'\n':' ');
        }
    }
    return 0;
}

