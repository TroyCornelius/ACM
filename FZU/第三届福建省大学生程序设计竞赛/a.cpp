/*
 * Author:  Troy
 * Created Time:  2012/12/2 15:00:27
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

string A, B;
int a, b;
int to_num(string s, int base) {
    int ret = 0, t = 1;
    reverse(all(s));
    REP(i, s.size()) {
        int dig = isdigit(s[i])?s[i]-'0':s[i]-'a'+10;
        ret += dig * t;
        t *= base;
    }
    return ret;
}
int main() {
    int T;
    cin >>T;
    int base;
    while (T--) {
        cin >>A >>B >>base;
        a = to_num(A, base);
        b = to_num(B, base);
        int k = a / b;
        int d = a % b;
        cout <<"(" <<k <<","<<d <<")" <<endl;
    }
    return 0;
}

