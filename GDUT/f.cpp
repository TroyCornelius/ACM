/*
 * Author:  Troy
 * Created Time:  2012/3/18 13:31:57
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
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

double n, a, ans;
int main() 
{
    freopen("1.in", "r", stdin);
    freopen("f.out", "w", stdout);
    while (cin >>n >>a)
    {
        if (n < 3) cout <<"0.0000" <<endl;//printf("0.0000\n");
        else
        {
            ans = 1.0/4.0*a*a*n*tan(pi/2.0 - pi/n);
            cout <<fixed <<setprecision(4) << ans <<endl;
        }
      //  printf("%.4f\n", 1.0/4.0*a*a*n*tan(pi/2.0 - pi/n));
    }
    return 0;
}

