/*
 * Author:  Troy
 * Created Time:  2012/11/20 0:32:00
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
const int Maxn = 150;
int n;
int ans[Maxn];
int b[Maxn][Maxn];
int main() {
    while(cin >> n) {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> b[i][j];
        memset(ans, 0, sizeof(ans));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                for(int k = 0; k < 31; k++) {
                    if(b[i][j] >> k & 1) {
                        ans[i] |= 1 << k;
                        ans[j] |= 1 << k;
                    }
                }
            }
        }
        for(int i = 0; i < n; i++) {
            pf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
        }
    }
    return 0;
}

