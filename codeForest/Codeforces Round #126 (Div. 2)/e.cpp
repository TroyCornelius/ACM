/*
 * Author:  Troy
 * Created Time:  2012/6/27 19:39:21
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
#define sf scanf
#define pf printf
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, s;
int c[8], ansf, ans[4];

inline int f(int x1, int x2, int x3)
{
    return abs(c[3]*x1 - c[4]*x2) + abs(c[4]*x2 - c[5]*x3);
}
int main() 
{
    cin >>n >>s;
    memset(c, 0, sizeof(c));
    int num;
    REP(i, n)
    {
        cin >>num;
        c[num]++; 
    }
    int k3, tmp;
    memset(ans, -1, sizeof(ans));
    ansf = maxint;
    REP(k1, 2001)
        FOR(k2, k1, 2001)
        {
            k3 = s - c[3] * k1 - c[4] * k2;
            if (k3 <= 0 || k3 % c[5] != 0) continue;
            k3 /= c[5];
            if (k3 < k2) continue;
            tmp = f(k1, k2, k3);
            if (tmp < ansf) ansf = tmp, ans[0] = k1, ans[1] = k2, ans[2] = k3;
        }
    if (ans[0] == -1) cout <<-1  <<endl;
    else cout <<ans[0] <<" "<<ans[1] <<" "<<ans[2] <<endl;
    
    return 0;
}

