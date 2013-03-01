/*
 * Author:  Troy
 * Created Time:  2012/5/18 21:40:08
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
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, hp[20];
int f[1<<16], val[20][20];

int dfs(int st)
{
    //cout <<st <<endl;
    if (f[st] != -1) return f[st];
    if (st == 0) return f[st] = 0;
    
    int mi, tmp;
    f[st] = maxint;
    REP(i, n)
        if ((1<<i)&st)
        {
            mi = hp[i];
            REP(j, n)
              if (i != j && ((1<<j)&st) && val[j][i] != 0)
                {
                    tmp = hp[i] / val[j][i] + (hp[i] % val[j][i] == 0 ? 0 : 1);
                    if (tmp < mi) mi = tmp;                    
                }  
            f[st] = min(f[st], dfs(st - (1<<i)) + mi);
        }
    //cout <<st << " "<<f[st] <<endl;
    return f[st];
}
int main() 
{
    int T, ca = 0;
    cin >>T;
    char ch;
    while (T--)
    {
        cin >>n;
        REP(i, n) cin >>hp[i];
        REP(i, n)
            REP(j, n)
            {
                cin >>ch;
                val[i][j] = ch - '0';
            }
        memset(f, -1, sizeof(f));
        cout <<"Case " <<++ca <<": " <<dfs((1<<n)-1) <<endl;
    }
    return 0;
}

