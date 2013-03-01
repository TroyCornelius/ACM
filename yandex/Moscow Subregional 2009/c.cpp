/*
 * Author:  Teletubbies
 * Created Time:  2012年10月03日 星期三 13时35分36秒
 * File Name: c.cpp
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
#define Maxn 50010
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

string s;
int n;
int x[Maxn], y[Maxn], k[Maxn];
int main() {
    ios::sync_with_stdio(false);
    while (cin >>s) {
        cin >>n;
        REP(i, n) cin >>x[i] >>y[i] >>k[i];
        FORD(i, n-1, 0) {
            x[i]--; y[i]--;
            string st = s.substr(x[i], y[i]-x[i]+1);
            string tmp = st.substr(0, k[i]);
            st = st + tmp;
            st.erase(0, k[i]);
            s.replace(x[i], y[i]-x[i]+1, st);
        }
        cout <<s <<endl;
    }
    return 0;
}

