/*
 * Author:  Troy
 * Created Time:  2012/5/18 1:18:12
 * File Name: d.cpp
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
#define Maxn 10000010
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

long long n, ans;
int p[Maxn], tot;
bool b[Maxn+10];
void init()
{
    tot = 0;
    memset(b, true, sizeof(b));
    for (int i=2; i<=Maxn; i++)
    if (b[i])
    {
        p[tot++] = i;
        for (int j = i+i; j<=Maxn; j+=i)
            b[j] = false;
    }
}
inline bool check(long long x)
{
    for (int i=-2; i<=2; i++)
        if ((x+i)*(x+i) == n) return true;
    return false;
}
int main() 
{
    init();
    int cnt = 0;
    long long tmp;
    while (cin >>n)
    {
        ans = 1;
        for (int i = 0; n > 1 && i < tot; i++)
        {
            cnt = 0; tmp = 1;
            while (n % p[i] == 0)
            {
                tmp *= p[i];
                cnt++;
                n /= p[i];
            }
            if (cnt & 1) tmp /= p[i];
            ans *= tmp;
        }
        if (n > 1)
        {
            long long t = sqrt((double)n);
            if (check(t)) ans *= n;            
        }
        cout <<ans <<endl;
    }
    return 0;
}

