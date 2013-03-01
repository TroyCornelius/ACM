#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int T;
long long L, R, last;
long long ans[2][2];
long long Pow_mod(long long bs, long long power, long long diver)
{
     if (power==0) return 1;
     else 
     if (power==1) return bs;
     else
     if ((power&1)==0) return Pow_mod(bs*bs%diver, (power>>1), diver);
     else return Pow_mod(bs*bs%diver, power/2, diver) * bs % diver;
     }
bool M_R(long long base, long long num)
{
     long long d = num - 1;
     while ((d&1)==0)
       {
          d = (d>>1);           
       }
     if ((Pow_mod(base,d,num)==1)||(Pow_mod(base,d,num)==num-1)) return true;
     else
       {
          long long t = (num-1)/2;
          while (d != t)
            {
               d = (d<<1);
               if (Pow_mod(base,d,num)==num-1) return true;                
            }
          return false;                                                   
       }     
     }
int main()
{
    cin >>T;
    srand(time(NULL));
    bool flag, done;
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
             flag = true;
             for (int test = 1; test<=7; test++)
               {
                  long long tmp = rand() % i;
                  if (tmp < 2) tmp+=2;
                  if ( !M_R(tmp, i)) {flag = false; break;}
               } 
             if (flag)
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
    return 0;
    }
