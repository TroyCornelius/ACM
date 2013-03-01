/*
 * Author:  Troy
 * Created Time:  2012/8/31 23:28:37
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
#define sf scanf
#define pf printf
#define maxn 100050
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
vi v, val;
int n, x;
int main() {
    cin >>n;
    v.resize(n);
    val.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> x;
        v[i] = val[i] = x;
    }
    sort(v.begin(), v.end());
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(v[i] != val[i]) cnt++;
    }
    cnt = (cnt + 1) >> 1;
    if(cnt > 1) puts("NO");
    else puts("YES");
    return 0;
}

