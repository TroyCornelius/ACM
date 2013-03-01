#include <iostream>
#include <cstdio>
#include <functional>
#define Maxn 1000005
using namespace std;

int n;
char c;
int main()
{
    scanf("%d", &n);
    int tot=0, ans[3];
    memset(ans, 0, sizeof(ans));
    for (int i=0; i<n; i++)
      {
         cin >>c;
         if (c=='0') tot++;
         else
         if (tot!=0)
           {
             ans[2] = tot;
             sort(ans, ans+3, greater<int>()); 
             tot = 0;                     
           }
      }
         if (tot!=0)
           {
             ans[2] = tot;
             sort(ans, ans+3, greater<int>()); 
             tot = 0;                     
           }
    cout <<ans[0]+ans[1] <<endl;

    return 0;
    }
