#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
#include <functional>
#include <cctype>
using namespace std;

int T;
long long n;
bool f[10000];
bool check(int k)
{
     for (int i=2; i*i <= k; i++)
       if (k%i==0) return false;
     
     return true;     
     }
int chu(int m, int c)
{
    int ret = 0;
    while (m >= c) 
    {
           ret ++;
           m /= c;
    }
    return ret;
         }
int main()
{
    freopen("C-small-practice.in", "r", stdin);
    freopen("C-small-practice.out", "w", stdout);
    cin >>T;
    memset(f, true, sizeof(f));
    for (int i=2; i<=1000; i++)
      if (f[i])
      {
         for (int j=i+i; j<=1000; j+=i) f[j] = false;
               
      }
    for (int ct=1; ct<=T; ct++)
    {
        cin >>n;
        if (n==1) {printf("Case #%d: 0\n", ct); continue;}
        int sm = 0, bi=0;
        for (int i=2; i<=n; i++)
        if (check(i)) sm++;
        
        for (int i=2; i<=n; i++)
        if (f[i])
        {
           bi += chu(n, i);                 
        }
   		printf("Case #%d: %d\n", ct, bi - sm + 1);
        
    }
    
    
    
    return 0;
    }
