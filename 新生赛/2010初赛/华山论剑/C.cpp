#include <iostream>
#define Maxn 50005
#define oo 999999999
using namespace std;

int n, m, p1, p2;
double f[Maxn];
struct stone
{
       int wi, val;
       }st[110];
struct lique
{
       int s;
       double  vsum;
       }li[110];
bool cmp(const lique &a, const lique &b)
{
     return (a.vsum/double(a.s)) > (b.vsum/double(b.s));     
     }
void init()
{
     scanf("%d%d", &n, &m);
     int a, b, c;
     p1 = p2 = 0;
     for (int i=0; i<n; i++)
       {
          scanf("%d%d%d", &a, &b, &c);
          if (c == 0)
            {
               st[p1].wi = a;
               st[p1++].val = b;                
            }
          else
            {
               li[p2].s = a;
               li[p2++].vsum = double(b);                            
            }
       }
     sort(li, li+p2, cmp);
     }
void dp()
{
     for (int i=0; i<=m; i++) f[i] =-oo;
     f[0] = 0;
     for (int i=0; i<p1; i++)
       {
          for (int j=m; j>=st[i].wi; j--)
            f[j] >?= f[j-st[i].wi] + st[i].val;              
       }
     double ans = 0;
     for (int i=0; i<=m; i++)
       {
         int tmp = m - i;
         double sum = f[i];
         for (int j=0; j<p2; j++)
           {
             
             if (tmp - li[j].s > 0) {sum += li[j].vsum; tmp-=li[j].s;}
             else
               {
                  sum += tmp * (li[j].vsum / double(li[j].s));
                  break;
               } 
           }
         ans >?= sum;
       }
     printf("%.2lf\n", ans);
     
     }
int main()
{
    init();
    dp();
    system("pause");
    return 0;
    }
