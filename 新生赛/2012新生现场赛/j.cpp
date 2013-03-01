#include <iostream>
#include <cstdio>
#include <cstring>

#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define REP(i,b) FOR(i, 0, b)
using namespace std;

int n, m, f[110][110][2];
int v[2][110];
void dp()
{
    memset(f, 0, sizeof(f));
    FOR(i, 1, n+1)
    {
        REP(k, 2)
        {
            f[i][0][k] = f[i-1][0][k] + v[k][i];
            FOR(j, 1, m+1)
            {
                f[i][j][k] = max(f[i][j][k], f[i-1][j][k] + v[k][i]);
                f[i][j][k] = max(f[i][j][k], f[i-1][j-1][1-k] + v[k][i]);
            }
        }
    }
    int ans = 0;
    REP(i, m+1)
    {
        ans = max(ans, max(f[n][i][0], f[n][i][1]));
    }
    printf("%d\n", ans);
}
int main()
{
    while (~scanf("%d%d", &m, &n))
    {
        FOR(i, 1, n+1) scanf("%d", &v[0][i]);
        FOR(i, 1, n+1) scanf("%d", &v[1][i]);
        dp();
    }
    
    return 0;
}
