/*
 * Author:  Troy
 * Created Time:  2012/3/20 23:30:17
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

int g[55][55];
vector<pii> p;
bool f[55][55][2];
int calc(pii a, pii b)
{
    return (abs(a.fi - b.fi) + abs(a.se - b.se)) % 2;
}
class EvenRoute
{
    public:
    string isItPossible(vector <int> x, vector <int> y, int wantedParity)
    {
        p.pb(mp(0,0));
        REP(i, x.size()) p.pb(mp(x[i], y[i]));
        REP(i, p.size())
            REP(j, p.size())
            if (i != j) g[i][j] = calc(p[i], p[j]);
        memset(f, 0, sizeof(f));
        int n = p.size();
        FOR(i, 1, n) f[1][i][g[0][i]] = true;
        FOR(i, 2, n)
        {
            FOR(j, 1, n)
            {
                if (j < i) 
            }
        }
        
        
    
    }
};
int main() 
{
    return 0;
}

