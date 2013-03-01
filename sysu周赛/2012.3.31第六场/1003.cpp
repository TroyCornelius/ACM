/*
 * Author:  Troy
 * Created Time:  2012/3/31 19:55:47
 * File Name: 1003.cpp
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

int n, k;
int a[25];
long long f[25], m;
bool b[25];
void work(long long tot)
{
    memset(b, false, sizeof(b));
    FOR(i, 1, n+1)
    {
        FOR(j, 1, n+1)
        {
            if (b[j]) continue;
            if (tot - f[n - i] > 0)
            {
                tot -= f[n-i];
            }
            else
            {
                a[i] = j;
                b[j] = true;
                break;
            }
        }
       // cout <<tot <<" "<<i <<" "<<a[i] <<endl;
    }
  //  FOR(i, 1, n+1) if (!b[i]) a[n] = i;
    FOR(i, 1, n+1) pf("%d%c", a[i], i==n?'\n':' ');
}
long long sum(int p)
{
    long long ret = 0;
    FOR(i, 1, p)
        if (!b[i]) ret++;
    return ret;
}
void calc()
{
    long long ret = 0;
    memset(b, false, sizeof(b));
    FOR(i, 1, n+1)
    {
        long long tmp = sum(a[i]);        
        ret += tmp * f[n-i];
        b[a[i]] = true;
    }
    cout <<ret+1 <<endl;
}
int main() 
{
    f[1] = 1; f[0] = 1;
    FOR(i, 2, 21) f[i] = f[i-1] * (long long)i;
    char op[3];
    while (~sf("%d%d", &n, &k))
    {
        while (k--)
        {
            sf("%s", op);
            if (op[0] == 'P')
            {
                cin >>m;
                work(m);
            }
            else
            {
                FOR(i, 1, n+1) sf("%d", &a[i]);
                calc();
            }
        }
    }
    return 0;
}

