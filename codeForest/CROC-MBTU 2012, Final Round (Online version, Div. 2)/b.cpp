/*
 * Author:  Troy
 * Created Time:  2012/11/27 22:26:16
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

int n, tot;
string s, str;
int ans[10];
int conv(string st) {
    int ret = 0;
    REP(i, st.size()) {
        int num = isdigit(st[i]) ? (st[i] - '0') : (10 + st[i] - 'a');
        ret = ret * 16 + num;
    }
    return ret;
}
int main() {
    cin >>n;
    while (n--) {
        cin >>s;
        str.clear();
        tot = 0;
        int tmp = 0;
        memset(ans, 0, sizeof(ans));
        bool flag = false;
        REP(i, s.size()) {
            if (s[i] == ':') {
                ans[tot++] = tmp;
                tmp = 0;
                if (i + 1 < s.size() && s[i+1] == ':') {
                    str = s.substr(i+2);       
                    flag = true;
                    break;
                }
            }
            else {
                int dig = isdigit(s[i]) ? (s[i] - '0') : (10 + s[i] - 'a');
                tmp = tmp * 16 + dig;
            }
        }
        if (!flag) ans[tot++] = tmp;
        if (str != "") {
            tot = 8;
            string tt ;
            tt.clear();
            for (int i = str.size()-1; i >= 0; i--) {
                if (str[i] == ':') {
                    ans[--tot] = conv(tt);
                    tt.clear();
                }
                else {
                    tt = str[i] + tt;
                }
            }
            ans[--tot] = conv(tt);
        }
        REP(i, 8) pf("%04x%c", ans[i], i == 7 ? '\n' :':');
    }
    return 0;
}

