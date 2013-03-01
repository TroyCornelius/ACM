/*
 * Author:  Troy
 * Created Time:  2012/12/2 17:41:13
 * File Name: g.cpp
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

string s;
int B;
ll ans;
int ml[1010];


inline ll pow_mod(int x, ll k) {
    ll ret = 1, t = x;
    //cout <<x <<"^"<<k <<" = " ;
    while (k) {
        if (k & 1) ret = (ret * t) % B;
        t = t * t % B;
        k >>= 1;
    }
    //cout <<ret <<endl;
    return ret;
}
pair<ll,ll> solve(int l, int r) {
    ll ret = 0, len = 0;
    int i = l;
    while (i <= r) {
        if (isdigit(s[i])) {
            ret = ret * 10 + s[i] -'0';
            ret %= B;
            i++;
            len++;
        }
        else {
            int next = ml[i];
            int cnt = s[next+1] - '0';
            pair<ll,ll> tmp = solve(i+1, next-1);
            //cout <<tmp.fi <<" "<<tmp.se <<" with " <<cnt <<endl;
            REP(j, cnt) {
                ret = ret * pow_mod(10, tmp.se) % B + tmp.fi;
                ret %= B;
                len += tmp.se;
                //if (tmp.fi == 11) cout <<ret <<" "<<len <<endl;
            }
            i = next + 2;
        }
        //cout <<i <<" "<<ret <<" "<<len << " in [" <<l <<"," <<r <<"]" <<endl;
    }
    return mp(ret, len);
}
int main() {
    int T;
    cin >>T;
    while (T--) {
        cin >>s;
        cin >>B;
        stack<int> stk;
        REP(i, s.size()) {
           if (s[i] == '[') stk.push(i);
           else if (s[i] == ']') {
               ml[stk.top()] = i;
               ml[i] = stk.top();
               stk.pop();
           }
       }
       pair<ll,ll> A = solve(0, (int)s.size() - 1);
       //cout <<A <<endl;
       ans = A.fi;
       cout <<ans <<endl;
    }
    return 0;
}

