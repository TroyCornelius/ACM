/*
 * Author:  Troy
 * Created Time:  2012/2/17 23:45:13
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
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
const long long mod = 1000000007LL; 

int n, m, k;

long long pm(long long a, long long b)
{
    long long ret = 1;
    REP(i, a) 
    {
        ret *= b;
        ret %= mod;
    }
    return ret%mod;
}
long long calc()
{
    if (n < k) k = 1;
    if (k == 1) return pm(n, m);
    else
        if (k < n)
        {
            if (k % 2 == 0) return m;
            else return (1LL * m * m) % mod;
        }
        else if (k == n)
        {
            if (k % 2 == 0) return pm(k/2, m);
            else return pm(k/2+1, m);
            
        }
}
int main() 
{
    cin >>n >>m >>k;
    cout <<calc() <<endl;   
    return 0;
}

