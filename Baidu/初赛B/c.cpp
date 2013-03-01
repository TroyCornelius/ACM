#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define Maxn 1000010
using namespace std;

int d[Maxn], n, m;
long long ot1, ot2;
long long sum[Maxn];
struct Tnode
{
       long long s;
       long long tot;
       double ave;       
       }f[Maxn];
double ans;
int gcd(long long a,long long b)
{
    if (a%b==0) return b;
    else return gcd(b, a%b);
    }
int main()
{
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &d[i]);
        sum[i] = (i==1)?d[i]:sum[i-1]+d[i];
        if (i > m) sum[i] -= d[i-m];
    }
    
    f[m].tot = m;
    f[m].s = sum[m];
    f[m].ave = (double)f[m].s/(double)f[m].tot;
    ans = 0.0;
    for (int i=m+1; i<=n; i++)
    {
        double t1 = (double)(sum[i]) / double(m);
        double t2 = double(f[i-1].s + d[i]) / (double)(f[i-1].tot+1);
        
        if (t1 > t2)
        {
           f[i].tot = m;
           f[i].s = sum[i];
           f[i].ave = t1;      
           if (f[i].ave > ans)
           {
              ans = f[i].ave;
              ot1 = f[i].s;
              ot2 = f[i].tot;                        
           }         
        }
        else
        {
           f[i].tot = f[i-1].tot+1;
           f[i].s = f[i-1].s + d[i];
           f[i].ave = t2;           
           if (f[i].ave > ans)
           {
              ans = f[i].ave;
              ot1 = f[i].s;
              ot2 = f[i].tot;                        
           }              
        }
    }
    if (ot1 % ot2 == 0) cout <<(ot1/ot2) <<endl;
    else cout <<(ot1/gcd(ot1, ot2))<<"/"<<(ot2/gcd(ot1,ot2)) <<endl;

    return 0;
}
