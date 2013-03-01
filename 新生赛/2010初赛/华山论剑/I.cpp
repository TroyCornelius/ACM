#include <iostream>
#include <cstdio>
using namespace std;

int n;
unsigned long long ans;
int d[55];

void dfs(int tot)
{
     if (tot == n)
       {
          ans++;
    //      for (int i=0; i<n; i++) cout<<d[i] <<" ";
   //       cout<<endl;
          return;             
       }
     else
     if (tot == n-1)
       {
          for (int i=1; i<=3; i++)
            if (i != d[0] && i != d[tot-1]) {d[tot]=i;dfs(tot+1);}
       }
     else
       {
          for (int i=1; i<=3; i++)
            if (i != d[tot-1])
              {
                 d[tot] = i;
                 dfs(tot+1);
              }
       }
     return;     
     }
int main()
{
    freopen("ans.out", "w", stdout);
    //cout <<3<<","<<6<<",";
    for (int i=25; i<=25; i++)
      {
         n = i;
         ans = 0;
         dfs(0);       
        cout<<ans <<endl; 
             
      }
    
    return 0;
    }
