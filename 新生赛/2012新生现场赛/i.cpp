#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,b) FOR(i,0,b)
using namespace std;

int x, n, ans;
int v[15], ti[15];
int main()
{
    int T, ts, vs;
    cin >>T;
    while (T--)
    {
        cin >>n >>x;
        REP(i, n) scanf("%d%d", &v[i], &ti[i]);
        ans = 0;
        FOR(i, 1, (1<<n))
        {
            ts = vs = 0;
            REP(j, n)
                if ((1<<j)&i) ts += ti[j], vs += v[j];
            if (ts <= x) ans = max(ans, vs);                
        }
        printf("%d\n", ans);
    }
    return 0;
}
