#include <iostream>
#include <cstdio>
#include <cstring>
#define MOD 100000007
#define Maxn 100010
using namespace std;

int n, m;
long long t[Maxn], ans;
inline int getint(){
    char c = getchar();
    int t = 0;
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9'){
        t = t * 10 + c - '0';
        c = getchar();
    }
    return t;
}
void insert(int idx)
{
     for (;idx<=n; idx+=idx&-idx) 
     {
         t[idx]++;
        // if (t[idx]>=MOD) t[idx] -= MOD;
     }
     }
long long query(int idx)
{
     long long ret = 0;
     for (;idx;idx-=idx&-idx) ret += t[idx];
     return ret;
     }
int main()
{
    int T, ca=0, num;
    long long tmp, c;
    T = getint();
    while (T--)
    {
          memset(t, 0, sizeof(t));
          ans = 0;
          n = getint();
          for (int i=0; i<n; i++)
          {
              num = getint();
              insert(num);
              tmp = query(num-1);
              c = n - num - (i - 1 - tmp);
              ans -= tmp * c;
              ans += c * (c-1) / 2;    
             // ans %= MOD;          
          }
          printf("Case #%d: %I64d\n", ++ca, ans%MOD);          
    }
    return 0;
    }
