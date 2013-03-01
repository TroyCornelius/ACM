#include <iostream>
#include <cstdio>
#include <algorithm>
#include <functional>
#define Maxn 1100
using namespace std;

int n, F, W, G;
long long ans;
int a[Maxn], d[Maxn];
int main()
{
    ios::sync_with_stdio(false);
    bool flag;
    while (cin >>n >>F >>W >>G)
    {
          for (int i=1; i<=n; i++) cin >>a[i] >>d[i];
          d[0] = G;
          int def = 0;
          flag = false;
          for (int i=1; i<=n; i++)
          {
              if (def < a[i])
              {
                  for (int j=i-1; j>=0; j--)
                  {
                      if (d[j] + def >= a[i])
                      {
                          d[j] -= (a[i] - def);
                          def = a[i];
                          break;                               
                      }
                      else
                      {
                          def += d[j];
                          d[j] = 0;                          
                      }                      
                  }
                  if (def < a[i]) {flag = true; break;}                      
              }
          }
          
          if (flag)
          {
              cout <<"It's useless to collect wood." <<endl;
              continue;                   
          }
          ans = 0;
          long long rate = W, far = 0, gold = 0;
          for (int i=0; i<=n; i++)
          {
              gold += d[i];
              long long tmp = gold / F;
              gold %= F;
              ans += far * rate;
              if (far + tmp > rate)
              {
                  tmp = tmp+far - rate;
                  far = rate + tmp/2;
                  rate += tmp/2;
                  if (tmp%2) far++; 
              }
              else far += tmp;
          }
          cout <<ans <<endl;
    }
    return 0;
    }
