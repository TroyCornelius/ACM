/*
 * Author:  Troy
 * Created Time:  2012/11/20 1:24:17
 * File Name: f.cpp
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

int n, m;
vector<int> msg;
string now;
bool ans;
const int nmonth[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
inline int conv(char ch) {
    return (int)ch - '0';
}
int calc(string s) {
    int mon = conv(s[5]) * 10 + conv(s[6]);
    int day = conv(s[8]) * 10 + conv(s[9]);   
    for (int i = 1; i < mon; i++) day += nmonth[i];
    int hh = conv(s[11]) * 10 + conv(s[12]);
    int mm = conv(s[14]) * 10 + conv(s[15]);
    int ss = conv(s[17]) * 10 + conv(s[18]);
    return ((day * 24 + hh) * 60 + mm) * 60 + ss;
}
int main() {
    string s;
    cin >>n >>m;
    getline(cin, s);
    int tot = 0, last = 0;
    while (getline(cin, s)) {
        int ti = calc(s);
        msg.pb(ti);
        while (ti - msg[last] >= n) last++;
        if ((int)msg.size() - last >= m) {
            cout <<s.substr(0, 19) <<endl;
            return 0;
        }
    }
    cout <<-1 <<endl;
    return 0;
}

