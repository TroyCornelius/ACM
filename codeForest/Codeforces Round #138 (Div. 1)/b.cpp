/*
 * Author:  Troy
 * Created Time:  2012/9/17 1:12:16
 * File Name: b.cpp
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
#define Maxn 200100
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

string s, t;
bool b[Maxn];
int main() {
    ios::sync_with_stdio(false);
    cin >>s;
    cin >>t;
    memset(b, false, sizeof(b));
    int p = 0;
    bool flag = true;
    REP(i, s.length()) {
        if (p < t.size()) {
            if (s[i] == t[p]) p++;
        }
    }
    if (!flag || p < t.size()) cout <<"No" <<endl;
    else cout <<"Yes" <<endl;
    return 0;
}

