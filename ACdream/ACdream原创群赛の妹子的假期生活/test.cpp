/*
 * Author:  Troy
 * Created Time:  2013/1/18 23:07:42
 * File Name: test.cpp
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

int a[10000], n,m;
int ans;
int calc() {
    int ret = 0;
    FOR(i, 1, n+1)
        FOR(j, i+1, n+1)
            if (a[i] > a[j]) ret++;
    return ret;
}
int main() {
    freopen("b.in", "r", stdin);
    freopen("std.out", "w", stdout);
    int T;
    cin >>T;
    while (T--) {
        cin >>n >>m;
        FOR(i, 1, n+1) cin >>a[i];
        ans = 0;
        cout <<calc() <<endl;
        int op, x, y;
        while (m--) {
            cin >>op >>x>>y;
            if (op == 0) {
                a[x] = y;
            }
            else {
                swap(a[x], a[y]);
            }
            cout <<calc() <<endl;
        }
        cout <<endl;
    }
    return 0;
}

