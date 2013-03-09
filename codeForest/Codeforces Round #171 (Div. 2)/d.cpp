/*
 * Author:  Troy
 * Created Time:  2013/3/5 1:22:27
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

int n, a[30], ans;
int d[30];
bool dfs(int len,  int p) {
    if (p >= n) {
        return true;
    }
    REP(i, len)
        REP(j, len) {
            if (d[i] + d[j] == a[p]) {
                REP(k, len) {
                    int tmp = d[k];
                    d[k] = a[p];
                    if (dfs(len, p+1)) return true;
                    d[k] = tmp;
                }
            }
        }
    return false;
}
int main() {
    cin >>n;
    REP(i, n) cin >>a[i];
    ans = -1;
    FOR(i, 1, n+1) {
        d[0] = a[0];
        if (dfs(i, 1)) {
            ans = i;
            break;
        }
    }

    cout <<ans <<endl;
    return 0;
}

