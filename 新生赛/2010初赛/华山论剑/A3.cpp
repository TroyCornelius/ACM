#include <iostream>
#define Maxn 70000
#define Maxm 1000010
using namespace std;

int T, tot, p;
long long L, R;
bool b[Maxn], bb[Maxm];
long long pr[Maxn], d[Maxm];
long long ans[2][2];
void Make_Prime()
{
     tot = 0;
     memset(b, true, sizeof(b));
     for (int i=2; i<=(1<<16)+5; i++)
       if (b[i])
         {
            for (int j=i+i; j<=(1<<16)+5; j+=i) b[j] = false;
         }
     for (int i=2; i<=(1<<16)+5; i++)
       if (b[i]) pr[tot++] = i;     
     }
void work()
{
     memset(bb, true, sizeof(bb));
     p = 0;
     if (L==1) {d[p++] = 2; L+=2;}
     else
     if (L%2==0) L++;     
     
     for (int i=0; i<tot; i++)
       {
         if (pr[i] > R) break;
         long long st = L / pr[i];
         if (L % pr[i]!=0) st++;
         st *= pr[i];
         if (pr[i] >= L) st = pr[i] + pr[i];
         for (; st<=R; st += pr[i]) bb[st-L] = false;  
       }
     
     for (int i=0; i<=R-L; i++)
       if (bb[i]) d[p++] = i + L;
     ans[0][0] = 0; ans [0][1] = 1147483640;
     ans[1][0] = ans[1][1] = 0;     
     if (p<2) cout <<"None." <<endl;
     else
       {
         long long last; int t;
         for (last=d[0], t=1; t<p; last=d[t],t++)
           {
              if (d[t] - last < ans[0][1] - ans[0][0])
                {
                   ans[0][0] = last;
                   ans[0][1] = d[t];

                }
              if (d[t] - last > ans[1][1] - ans[1][0])
                {
                   ans[1][0] = last;
                   ans[1][1] = d[t];   
                }    
           }
             cout <<"Closest: " <<ans[0][0] <<" " <<ans[0][1] <<endl;
             cout <<"Longest: " <<ans[1][0] <<" " <<ans[1][1] <<endl;
       }
     
     
     }
int main()
{
    Make_Prime();
    cin >>T;
    for (;T>0; T--)
      {
         cin >>L >>R;
         work();
      }
    system("pause");
    return 0;
    }
