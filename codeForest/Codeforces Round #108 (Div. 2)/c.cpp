/*
 * Author:  Troy
 * Created Time:  2012/2/20 23:12:05
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
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

const long long mod = 1000000007LL;

int n, m;
long long ans;
string s[110];
bool v[30];
int main() 
{
    cin >>n >>m;
    REP(i, n) cin >>s[i];
    long long cnt;
    ans = 1;
    REP(j, m)
    {
        cnt = 0;
        memset(v, false, sizeof(v));    
        REP(i, n)
        {
            if (!v[s[i][j] - 'A']) cnt++;
            v[s[i][j] - 'A'] = true;
        }
        ans *= cnt;
        ans %= mod;
    }
    cout <<ans <<endl;
    
    
    return 0;
}

