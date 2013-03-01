/*
 * Author:  Troy
 * Created Time:  2012/11/10 20:24:12
 * File Name: e.cpp
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

double a, b;
int main() {
    int T;
    //for (double x = 1.0; x <= 60.0; x += 1.0) {
        //double t = pow(2.0, x) + 1;
        //pf("%.8f\n", log10(t)/log10(2.0));
    //}
    cin >>T;
    double ans;
    while (T--) {
        cin >>a >>b;
        if (a < b) swap(a, b);
        ans = b-1.0;
        a -= b;
        if (a < 30.0) {
            double t = pow(2.0, a) + 1;
            ans += log10(t) / log10(2.0);
        }
        else ans += a;
        pf("%.5f\n", ans);
}
    return 0;
}

