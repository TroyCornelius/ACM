/*
 * Author:  Troy
 * Created Time:  2012/5/25 21:40:50
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
#define Maxn 1000000
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, m;
int p[Maxn+10];
bool b[Maxn+10];
void init()
{
    memset(b, true, sizeof(b));
    m = 0;
    for (int i = 2; i<=Maxn; i++)
    if (b[i])
    {
        p[m++] = i;
        for (int j = i + i; j<=Maxn; j+=i) b[j] = false;
    }
}
inline int getDigitsum(int x)
{
    int ret = 0;
    while (x)
    {
        ret += x % 10;
        x /= 10;
    }
    return ret;
}
bool check(int k)
{
    int s1 = getDigitsum(k);
    int s2 = 0;
    if (k <= Maxn && b[k]) return false;
    REP(i, m)
    {
        if (k % p[i] == 0)
        {
            while (k % p[i] == 0)
            {
                s2 += getDigitsum(p[i]);
                k /= p[i];
            }
        }
    }
    //cout <<n <<" "<<k <<endl;
    if (n == k) return false;
    if (k != 1) s2 += getDigitsum(k);
    return s1 == s2;
}
int main() 
{
    init();
    int T;
    cin >>T;
    while (T--)
    {
        cin >>n;
        n++;
        for (;;n++)
        {
            if (check(n))
            {
                cout <<n <<endl;
                break;
            }
        }
    }
    
    return 0;
}

