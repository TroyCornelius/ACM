/*
 * Author:  Troy
 * Created Time:  2012/11/5 0:06:31
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

int y, n, k;
vi ans;
int main() {
    cin >>y >>k >>n;
    int x = n - y;
    int st = y / k;
    if (y % k != 0) st++;
    st = st * k - y;
    if (st == 0) st += k;
    for (int i = st; i <= x; i += k) ans.pb(i);
    if (ans.size() == 0) cout <<-1 <<endl;
    else {
        cout <<ans[0];
        for (int i = 1; i < ans.size(); i++) cout <<" "<<ans[i];
        cout <<endl;
    }
    return 0;
}

