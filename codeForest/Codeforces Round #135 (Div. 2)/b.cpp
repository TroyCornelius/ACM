/*
 * Author:  Troy
 * Created Time:  2012/8/28 0:05:22
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

unsigned long long p, d;
int main() 
{
    cin >>p >>d;
    unsigned long long ans = 0;
    unsigned long long tmp = 9, s = 10;
    while (tmp < p) {
        unsigned long long res = p - tmp;
        res %= s;
        unsigned long long t = p - res;
        if (t < p && t >= p - d) {
            ans = t;
        }
        tmp = tmp * 10 + 9;
        s *= 10LL;
    }
    if (ans == 0) ans = p;
    cout <<ans <<endl;
    return 0;
}

