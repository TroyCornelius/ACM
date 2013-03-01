#include <cstdio>
#include <cstring>
#include <iostream>
#define FOR(i, a, b) for(int i(a); i<(b); i++)
#define REP(i, b) FOR(i, 0, b)
using namespace std;

int n, m, goal[25], hab[20][25];
int ans;
bool check(int s)
{
    int tot[25];
    memset(tot, 0, sizeof(tot));
    REP(i, m)
    if ((1<<i)&s)
    {
        REP(j, n) tot[j] += hab[i][j];    
    }
    REP(i, n)
        if (goal[i] > tot[i]) return false;
    return true;
}
int main()
{
    int cnt, anss;
    while (~scanf("%d", &n))
    {
        REP(i, n) scanf("%d", &goal[i]);
        scanf("%d", &m);
        REP(i, m)
        {
            REP(j, n) scanf("%d", &hab[i][j]);        
        }
        ans = anss = 0;
        FOR(st, 1, 1<<m)
        {
            cnt = 0;
            REP(i, m)
                if ((1<<i)&st) cnt++;
            if (cnt > ans && check(st)) ans = cnt, anss = st;
        }       
        printf("%d", ans);
        REP(i, m)
            if ((1<<i)&anss) printf(" %d", i+1);
        printf("\n");
    }
    return 0;
}
