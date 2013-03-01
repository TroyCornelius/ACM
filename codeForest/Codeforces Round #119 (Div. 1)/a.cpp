#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>

#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,b) FOR(i,0,b)
#define sf scanf
#define pf printf
#define Maxn 200010
using namespace std;

int n, a[Maxn], b[Maxn];
bool vis[Maxn];
int main() 
{
    
    
    sf("%d", &n);
    REP(i, n) sf("%d", &a[i]);
    REP(i, n) sf("%d", &b[i]);
    memset(vis, false, sizeof(vis));
    int tot = 0;
    int h = 0, t = n-1;
    
    REP(i, n)
    {
        if (b[i] == a[h]) 
        {
            h++;
            continue;
        }
        else 
        {
            if (vis[b[i]]) continue;
            else
            {
                while (t >= h && a[t] != b[i])
                {
                    tot++;
                    vis[a[t]] = true;
                    t--;
                }
                tot++;
                t--;
            }
        }
    }
    pf("%d\n", tot);
    return 0;
}

