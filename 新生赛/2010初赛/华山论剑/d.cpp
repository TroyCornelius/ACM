#include <iostream>
#include <algorithm>
#include <functional>
#define Maxn 10005
#define MOD 1000000007
using namespace std;

int T, n;
long long d[Maxn], ans;

int main()
{
    //freopen("1.in", "r", stdin);
  //  freopen("1.out", "w", stdout);
    cin >>T;
    for (; T>0; T--)
      {
         cin >>n;
         ans = 1;
         for (int i=0; i<n; i++) scanf("%I64d", &d[i]);
         sort(d, d+n, less<int>());
         for (long long i=0; i<n; i++)
           {
             if (i >= d[i]) {ans = 0; break;}             
             ans *= d[i] - i; 
             if (ans % MOD != 0) ans %= MOD;           
           }
         cout <<(ans%MOD) <<endl;       
      }

    return 0;
    }
