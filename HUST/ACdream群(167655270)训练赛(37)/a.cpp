/*
 * Author:  Troy
 * Created Time:  2012/6/15 19:12:51
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
#define sf scanf
#define pf printf
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int main() 
{
    int T, n, cnt, ca = 0;
    cin >>T;
    while (T--)
    {
        cin >>n;
        cnt = 0;
        while (n)
        {
            if (n%2 == 1) cnt++;
            n/=2;
        }
        if (cnt % 2 != 0) pf("Case %d: odd\n", ++ca);
        else pf("Case %d: even\n", ++ca);
    }
    return 0;
}

