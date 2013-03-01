/*
 * Author:  Troy
 * Created Time:  2012/3/18 0:17:42
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


bool vis[3000];
bool check(int X, int Y)
{
   /* for (int i = 0; i<=2000; i+=X)
        for (int j=0; j<=2000 - i; j+=Y)
        {
            if (i + j > 2000) break;
            if (!vis[i+j]) return false;
        }*/
    bool b[2600];
    memset(b, false, sizeof(b));
    b[0] = true;
    for (int i = 0; i<=2500; i++)
    {
        if (vis[i] && !b[i]) return false;
        if (b[i])
        {
            if (i + X <= 2500) b[i+X] = true;
            if (i + Y <= 2500) b[i+Y] = true;
        }
    }
    return true;
}
class KingXNewCurrency
{
    public:
    int howMany(int A, int B, int X)
    {
        memset(vis, false, sizeof(vis));
        vis[0] = true;
        for (int i=0; i<=2000; i++)
        if (vis[i])
        {
            if (i + A <= 2500) vis[i+A] = true;
            if (i + B <= 2500) vis[i+B] = true;
        }
        int ans = 0;
        REP(i, 201)
        if (i != X)
        {
            if (check(X, i)) ans++;            
        }
        return (ans == 200 ? -1 : ans);
    }
};
 
int main() 
{
    return 0;
}

