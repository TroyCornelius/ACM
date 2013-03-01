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
bool flag;
string s;
bool ask(int a, int b) {
    cout <<1 <<" " <<a <<" "<<b <<endl;
    cout.flush();
    
    if (cin >>s) {
        return s == "YES";
    }
    else flag = true;
    return false;
}

vi solve(int l, int r) {
    if (l == r) {
        return vector<int>(1, l);
    }
    vi ret;
    if (flag) return ret;
    int mid = (l + r) >>1;
    vi lans = solve(l, mid);
    vi rans = solve(mid+1, r);
    int i, j;
    for (i = 0, j = 0; i < lans.size() && j < rans.size(); ) {
        if (ask(lans[i], rans[j])) {
            ret.pb(lans[i++]);
        }
        else ret.pb(rans[j++]);
        if (flag) return ret;
    }
    while (i < lans.size()) ret.pb(lans[i++]);
    while (j < rans.size()) ret.pb(rans[j++]);
    return ret;
}

int main() {
    cin >>n;
    vi ans = solve(1, n);
    cout <<0;
    if (flag) {
        REP(i, n) cout <<" 0" <<endl;
    }
    else {
        REP(i, ans.size()) cout <<" "<<ans[i];
    }
    cout <<endl;
    return 0;
}

