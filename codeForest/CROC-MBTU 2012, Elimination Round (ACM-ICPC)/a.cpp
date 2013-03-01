/*
 * Author:  Troy
 * Created Time:  2012/11/19 23:31:55
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

int n, a, b;
int main() {
    while (cin >>n) {
        int ra = 0, ca = 0, rb = 0, cb = 0;
        int id;
        REP(i, n) {
            cin >>id >>a >>b;
            if (id == 1) {
                ra += a;
                ca += a + b;    
            }
            else {
                rb += a;
                cb += a + b;
            }
        }        
        if (ra * 2 >= ca) cout <<"LIVE" <<endl;
        else cout <<"DEAD" <<endl;
        if (rb * 2 >= cb) cout <<"LIVE" <<endl;
        else cout <<"DEAD" <<endl;
    }
    return 0;
}

