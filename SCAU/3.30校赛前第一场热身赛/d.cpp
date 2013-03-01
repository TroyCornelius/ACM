/*
 * Author:  Troy
 * Created Time:  2012/3/30 19:14:18
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
#define Maxn 500000
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n;
bool p[Maxn+10];
vi d;
void init()
{
    memset(p, true, sizeof(p));
    p[1] = false;
    FOR(i, 2, Maxn+1)
        if (p[i])
        {
            d.pb(i);
            for (int j = i+i; j<=Maxn; j+=i) p[j] = false;
        }
}
bool check(int k)
{
    int t;
    REP(i, d.size())
        if (k % d[i] == 0)
        {
            t = k / d[i];
            if (p[t]) return true;
        }
        else if (d[i] > k) break;
    return false;
}
int main() 
{
    init();
    while (~sf("%d", &n))
    {
        if (check(n)) pf("Yes\n");
        else pf("No\n");

    }
    return 0;
}

