/*
 * Author:  Troy
 * Created Time:  2012/9/29 14:27:21
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
#define sf scanf
#define pf printf
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

double vec[15][12], dis[15];
double dest[12];
int main() {
    int T;
    sf("%d", &T);
    while (T--) {
        REP(i, 12) {
            REP(j, 11)
                sf("%lf", &vec[i][j]);
            sf("%lf", &dis[i]);
        }
        /*
        REP(i, 11) cin >>dest[i];
        double tmp = 0;
        REP(i, 12) {
            tmp = 0;
            REP(j, 11) tmp += (dest[j] - vec[i][j]) * (dest[j] - vec[i][j]);
            cout <<sqrt(tmp ) <<endl;
        }*/        
    }
    return 0;
}

