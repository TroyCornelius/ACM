#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const long long inf = (1LL<<62) - 1;
int n, k;
long long num[45], sum[45], ans;

void dfs(int idx, int tot, long long s)
{
     if (s < ans) ans = s;
     if (idx >= n || tot >= k) return;
     if ((s & sum[idx]) >= ans) return;
     dfs(idx+1, tot+1, s&num[idx]);
     dfs(idx+1, tot, s);
     }
int main()
{
    int ca = 0, T;
    scanf("%d", &T);
    while (T--)
    {
          scanf("%d%d", &n, &k);
          sum[n] = ans = inf;
          for (int i=0; i<n; i++) scanf("%I64d", &num[i]);
          sort(num, num+n);
          for (int i=n-1; i>=0; i--) sum[i] = sum[i+1] & num[i];
          dfs(0, 0, inf);       
          printf("Case #%d: %I64d\n", ++ca, ans);          
    }    
    return 0;
    }
