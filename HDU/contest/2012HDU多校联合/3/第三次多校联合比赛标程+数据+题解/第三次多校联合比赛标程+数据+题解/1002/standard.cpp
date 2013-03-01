#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define INF 0x3fffffff
#define LL long long

LL a, b, n;
LL solve_sub(int idx, LL len)
{
    LL i, ret = 0, bit = (1LL << idx);
    LL start = 0, end, slen;
    while(start < len)
    {
        slen = (bit - (b + start * a) % bit) / a;
        for(end = max(start + 1, start + slen - 5); end <= min(start + slen + 5, len - 1); end++)
        {
            if(((b + end * a) & bit) != ((b + start * a) & bit))
                break;
        }
        end = min(end, len);
        if((b + start * a) & bit)
            ret += end - start;
        start = end;
    }
    return ret;
}

LL solve(int idx)
{
    LL i, ret = 0, bit = (1LL << (idx + 1));
    if(n / bit > 0)
        ret += (n / bit) * solve_sub(idx, bit);
    ret += solve_sub(idx, n % bit);
    return ret;
}

int main()
{
  //  freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, i, j, cas = 1;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%I64d%I64d%I64d", &a, &b, &n);
        b += a;
        LL ans = 0;
        for(i = 0; i < 63; i++)
        {
            ans += solve(i);
        }
        printf("Case #%d: %I64d\n", cas++, ans);
    }
    return 0;
}
