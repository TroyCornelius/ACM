/*
 * Author:  Troy
 * Created Time:  2012/11/27 20:20:46
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

int n;
vector<vi> ans;
int main() {
    cin >>n;
    int a, cnt = 0;
    vi tmp;
    REP(i, n) {
        cin >>a;
        if (a < 0 && cnt >= 2) {
            ans.pb(tmp);
            tmp.clear();
            cnt = 0;
        }
        tmp.pb(a);
        if (a < 0) cnt++;
    }
    if (tmp.size() != 0) ans.pb(tmp);
    cout <<ans.size() <<endl;
    REP(i, ans.size()) cout <<ans[i].size() <<" ";
    cout <<endl;
    return 0;
}

