#include<iostream>
#include<cmath>
#include <algorithm>
#include <functional>
using namespace std;

int T;
long long L, R, last;
long long ans[2][2];

void power(long long a, long long p, long long n, long long &result,bool &composite)
{
 long long x;
  if(p==0) result=1;
  else{
   power(a,p/2,n,x,composite);
            result=(x*x)%n;
   if((result==1)&&(x!=1)&&(x!=n-1))
    composite=true;
   if(p%2==1)
    result=(result*a)%n;
}
}

bool PrimeMC( long long n)
{

  long long a,result;
 bool composite=false;
 if (n == 3) return true;

 a = (rand()% (n-3))+2;
 
 power(a,n-1,n,result,composite);
 if(composite||(result!=1)) return false;

    return true;
}
int main()
{    
    srand(time(NULL));
    cin >>T;
    bool done;
    for (;T>0;T--)
      {
         cin >>L >>R;   

         last = -1;   done = false;
         ans[0][0] = 0; ans [0][1] = 1147483640;
         ans[1][0] = ans[1][1] = 0;
         if (L % 2 ==0) L++;
         if (L == 1) {L+=2; last = 2;}
         for (long long i=L; i<=R; i+=2)
           {
             if ((PrimeMC(i)))
               {
                  if (last == -1) {last = i; continue;}
                  if (i - last < ans[0][1] - ans[0][0])
                    {
                       ans[0][0] = last;
                       ans[0][1] = i;
                       done = true;
                    }
                  if (i - last > ans[1][1] - ans[1][0])
                    {
                       ans[1][0] = last;
                       ans[1][1] = i;
                       done = true;    
                    }
               last = i;
               }
           }     
         if (!done) cout <<"None." <<endl;
         else
           {
             cout <<"Closest: " <<ans[0][0] <<" " <<ans[0][1] <<endl;
             cout <<"Longest: " <<ans[1][0] <<" " <<ans[1][1] <<endl;
           }                  
      }


 system("pause");
 return 0;
}
