/*
 * Author:  Troy
 * Created Time:  2012/6/8 22:02:05
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
#define sf scanf
#define pf printf
#define Maxn 1010
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int mod = 1000003;

int n, m, tot;
int c[Maxn][Maxn];
struct Tnode
{
    int val, le, ri, cl, cr;
    void cle()
    {
        val = le = ri = -1;
        cl = cr = 0;
    }
}t[Maxn*2];
void init()
{
     c[0][0] = 1;
     FOR(i, 1, 1001)
     {
         c[i][0] = 1;
         FOR(j, 1, 1001)
             c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
     }
}
void insert(int r, int v)
{
    if (v < t[r].val)
    {
        t[r].cl++;
        if (t[r].le != -1) insert(t[r].le, v);
        else
        {
            t[++tot].cle();
            t[r].le = tot;
            t[tot].val = v;
            return;
        }
    }
    else
    {
        t[r].cr++;
        if (t[r].ri != -1) insert(t[r].ri, v);
        else
        {
            t[++tot].cle();
            t[r].ri = tot;
            t[tot].val = v;
            return;
        }
    }
}
int dfs(int r)
{
    int ret = c[t[r].cl + t[r].cr][t[r].cl];
    int s1, s2;
    if (t[r].le == -1) s1 = 1;
    else s1 = dfs(t[r].le);
    if (t[r].ri == -1) s2 = 1;
    else s2 = dfs(t[r].ri);
    //cout <<s1 <<" "<<s2 << " "<<ret <<endl;
    
    ret = 1LL * ((1LL * ret * s1) % mod) * s2 % mod;
    return ret;
    
}
int main() 
{
    int T, num;
    sf("%d", &T);
    init();
    //cout <<c[3][1] <<endl;
    while (T--)
    {
        sf("%d%d", &n, &m);
        tot = 0;
        t[0].cle();
        sf("%d", &num);
        t[0].val = num;
        REP(i, n-1)
        {
            sf("%d", &num);
            insert(0, num);
        }
        //cout <<t[0].cl <<" "<<t[0].cr <<endl;
        pf("%d\n", (int)(1LL * dfs(0) * c[m][n] % mod));
    }
    return 0;
}

