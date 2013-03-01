#include <iostream>
#define oo 999999999.0
using namespace std;

int T, E, S, mon;
double v;
int n, m;
struct weapon
{
       int cost;
       double acce;       
       }w[105];
struct NPC
{
       int ex;
       double discount;
       }p[105];
double fdis[105], f[105];
void init()
{
     scanf("%d%d%d%lf", &E, &S, &mon, &v);
     scanf("%d", &n);
     for (int i=0; i<n; i++) 
       {
          scanf("%d %lf", &p[i].ex, &p[i].discount);          
       }
     scanf("%d", &m);
     for (int i=0; i<m; i++) scanf("%d %lf", &w[i].cost, &w[i].acce);
     }
void dp()
{
     for (int i=0; i<=E; i++) fdis[i] = 1.0;
     for (int i=0; i<n; i++)
       for (int j=E; j>=p[i].ex; j--)
         {
            fdis[j] <?= fdis[j-p[i].ex]*p[i].discount;                
         }    
     }
void work()
{
     dp();
     double ans = oo, tmp=0;
     for (int k=0; k<=E; k++)
       {
          for (int t=0; t<=mon; t++) f[t] = -oo;
          f[0]=0.0; tmp=0;
          for (int i=0; i<m; i++)
            for (int j=mon; j>=max(1,int(w[i].cost*fdis[k])); j--)
              {
                 f[j] >?= f[j-max(1,int(w[i].cost*fdis[k]))] + w[i].acce;  
                 tmp >?= f[j];                   
              }
          ans <?= double((S-(E-k)))/(v*(tmp+1.0));              
       }
     printf("%.2lf\n", ans);    
     }
int main()
{
    cin >>T;
    while (T>0)
      {
         init();
         work();
         T--;          
      }    

    return 0;
    }
