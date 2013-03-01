/*
 * Author:  Troy
 * Created Time:  2012/8/16 18:35:27
 * File Name: 4371.cpp
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

int n, m, x, mi;
int main() 
{
    int T, ca = 0;
    cin >>T;
    while (T--)
    {
        cin >>n >>m;
        mi = maxint;
        REP(i, m)
        {
            cin >>x;
            mi = min(mi, x);
        }
        n = n / mi;
        if (n & 1) cout <<"Case #" <<++ca <<": Bob" <<endl;
        else  cout <<"Case #" <<++ca <<": Alice" <<endl;
    }
    return 0;
}

