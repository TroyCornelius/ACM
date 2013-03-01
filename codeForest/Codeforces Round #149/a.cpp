/*
 * Author:  Troy
 * Created Time:  2012/11/12 1:03:35
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
vector<pii> d;
int x, y, a, b;
int main() {
    cin >>x >>y >>a >> b;
    int ans = 0;
    d.clear();
    for(int i = a; i <= x; i++) {
        for(int j = b; j <= y; j++) {
            if(i > j) d.pb(mp(i, j));
        }
    }
    cout << d.size() << endl;
    for(int i = 0; i < d.size(); i++) {
        cout << d[i].fi << " " << d[i].se << endl;
    }
    return 0;
}

