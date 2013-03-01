#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define fi first
#define se second
#define mp make_pair
#define Maxn 20010
using namespace std;

int c[Maxn];
int n, Q, t, tot; 
int pos[Maxn], def[Maxn]; 
pair<int,int> att[Maxn];
void init()
{
     memset(pos, 0, sizeof(pos));
     memset(def, 0, sizeof(def));
     memset(c, 0, sizeof(c));     
     tot = 0;
}
void add(int idx, int val)
{
     for (;idx; idx-=idx&-idx) c[idx] += val;
     }
int query(int idx)
{
    int ret = 0;
    for (;idx<=n;idx+=idx&-idx) ret += c[idx];
    return ret;
    }
int main()
{
    int T, x, a, b, ca=0;
    char op[15];
    scanf("%d", &T);
    while (T--)
    {
          printf("Case %d:\n", ++ca);
          scanf("%d%d%d", &n, &Q, &t);
          init();
          while (Q--)
          {
                scanf("%s", op);
                if (op[0] == 'Q')
                {
                     scanf("%d", &x);
                     if (t == 1)
                     {
                          printf("0\n");
                          continue;                          
                     }
                     int i=pos[x];
                     for (;i<tot; i++)
                     {
                         if (att[i].fi <= x && att[i].se >= x)
                         {
                             def[x]++;
                             pos[x] = i+t;
                             i += t-1;                                       
                         }                       
                     }
                     printf("%d\n", query(x) - def[x]);
                }
                else
                {
                    scanf("%d%d", &a, &b);
                    if (a > b) swap(a, b);
                    add(b, 1);
                    add(a-1, -1);
                    att[tot++] = mp(a, b);                    
                }  
          }
    }
    return 0; 
    }
