/*
 * Author:  Troy
 * Created Time:  2012/6/22 23:26:43
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

double k, b, n, t;
double ans;
int main() 
{
    cin >>k >>b >>n >>t;
    if (k != 1)
    {
        double t1 = (k + b - 1.0) / (t * k - t + b);
        t1 = log(t1);
        t1 /= log(k);
        ans = t1 + n;
        //cout <<ans <<endl;
        if (ans < 0.0) ans = 0.0;
        cout <<(long long)ceil(ans) <<endl;
    }
    else
    {
        ans = (b * n - t) / b;
        if (ans < 0) ans = 0.0;
        cout <<(long long)ceil(ans) <<endl;
    }
    
    return 0;
}

