/*
 * Author:  Troy
 * Created Time:  2012/11/30 19:32:21
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
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n;
bool vis[1100];
int calc(int m) {
    memset(vis, true, sizeof(vis));
    int now = m, tot = m;
    cout <<"............" <<endl;
    while (tot > 1) {
        for (int cnt = 0; cnt < 2; ) {
            now = (now + 1) % m;
            if (now == 0) now = m;
            if (vis[now]) {
                cnt++;
            }
        }
        vis[now] = false;
        //cout <<m <<": " <<now <<" --" <<tot <<endl; 
        tot--;
    }
    for (int i = 1; i<=m; i++)
        if (vis[i]) return i;
}
int solve(int n) {
    int tmp = 1;
    while (n > tmp) {
        n -= tmp;
        tmp <<= 1;
    }
    return 2 * n - 1;
}
int main() {
    //freopen("tmp.txt", "w", stdout);
    //for (int i = 1; i <= 1000; i++) {
        //cout <<i <<" : " <<calc(i) <<endl;
    //}
    while (cin >>n) {
        cout <<solve(n) <<endl;
    }
    return 0;
}

