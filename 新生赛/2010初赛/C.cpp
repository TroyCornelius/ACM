#include <iostream>
#include <cstdio>
using namespace std;

int n, q, ki;

int ask(int m)
{
    if (n > 3)
      {
          int mid = (n+1)/2;
          if (m>mid) return m-2-1;
          else
            return n-2-m;          
      }
    else
      {
         if (n==3)
           {
              if (m==1 || m==3) return 1;
              else return 0;                  
           }
         else
         if (n<=2) return 0;
      }
    
    }
int main()
{
    
    while (scanf("%d%d",&n,&q)!=EOF)
      {
         for (int i=0; i<q; i++)
           {
              scanf("%d", &ki);
              cout<< ask(ki) <<" ";
           }
         cout <<endl;
      }
    return 0;
    }
