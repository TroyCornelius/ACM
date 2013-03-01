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
int B, ans;
int ml[1010];
string solve(int l, int r) {
    string ret;
    int i = l;
    while (i <= r) {
        if (isdigit(s[i])) {
            ret = ret + s[i];
            i++;
        }
        else {
            int next = ml[i];
            int cnt = s[next+1] - '0';
            string tmp = solve(i+1, next-1);
            REP(j, cnt) ret = ret + tmp;
            i = next + 2;
        }
    }
    return ret;
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
       string A = solve(0, (int)s.size() - 1);
       //cout <<A <<endl;
       ans = 0;
       REP(i, A.size()) {
           ans = ans * 10 + A[i] - '0';
           ans %= B;
       }
       cout <<ans <<endl;
    }
    return 0;
}

