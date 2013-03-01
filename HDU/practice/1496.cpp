#include <iostream>
#include <cstdio>
#include <cstring>
#define Maxn 1000000
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define REP(i,b) FOR(i,0,b)
using namespace std;
int a, b, c, d, ans;
int hash[Maxn*3+10];
int main()
{
    while (~scanf("%d%d%d%d", &a, &b, &c, &d))
    {
        if ((a>0 && b>0 && c>0 && d>0) || (a<0 && b<0 && c<0 && d<0)) {printf("0\n");continue;}
        ans = 0;
        memset(hash, 0, sizeof(hash));
        FOR(i, 1, 101)
          FOR(j, 1, 101)
            hash[a*i*i + b*j*j + Maxn]++;
        FOR(i, 1, 101)
            FOR(j, 1, 101)
              ans += hash[-(c*i*i + d*j*j) + Maxn];
        printf("%d\n", 16*ans);    
    }
    
    return 0;
}
