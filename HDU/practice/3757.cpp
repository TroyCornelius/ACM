#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<iostream>
#include<string>
#include<cmath>
#define Maxn 4010
using namespace std;
const int inf = 1000000010;
int n, m, nn;
int ans[Maxn];
long long sum;
struct Tnode
{
       int id, loc;
       bool operator <(const Tnode &b)const
       {
            return loc < b.loc;
       }
       }d[Maxn], shel[Maxn];
inline int RD()
{
    char c = getchar();
    int t = 0;
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9')
    {
        t = t * 10 + c - '0';
        c = getchar();
    }
    return t;
}
void print()
{
    printf("%lld\n", sum);
    for (int i=0; i<n-1; i++) printf("%d ", ans[i]+1);
    printf("%d\n", ans[n-1]+1);
    
}
int main()
{
    int T, p1, p2;
    T = RD();
    while (T--)
    {
        sum = 0;
        n = RD();
        for (int i=0; i<n; i++) d[i].loc = RD(), d[i].id = i;
        m = RD();
        for (int i=0; i<m; i++) shel[i].loc = RD(), shel[i].id = i;
        sort(d, d+n);
        sort(shel, shel+m);
        p1 = 0; p2 = m-1;
        int v, tmp, tt;
        while (p1 <= p2)
        {
            tmp = inf;
            for (int i=0; i<n; i++)
            if (d[i].loc != -1)
            {
                tt = abs(d[i].loc - shel[p1].loc);
                if (tt < tmp)
                {
                    tmp = tt;
                    v = i;
                }
                else break;
            }
            sum += tmp;
            d[v].loc = -1;
            ans[d[v].id] = p1++;
            if (p1 > p2) break;            
            tmp = inf;
            for (int i=n-1; i>=0; i--)
            if (d[i].loc != -1)
            {
                tt = abs(d[i].loc - shel[p1].loc);
                if (tt < tmp)
                {
                    tmp = tt;
                    v = i;
                }
                else break;
            }
            sum += tmp;
            d[v].loc = -1;
            ans[d[v].id] = p2--;
        }
       // for (int i=0; i<n; i++) cout <<ans[i] <<" ";
     //   cout <<endl;
      //  nn = unique(loc, loc + n) - loc - 1;
        
     //   cout <<n <<endl;
       /* if (nn == 0) print();
        else
        {
            for ()
            
        }*/
        for (int i=0; i<n; i++)
        if (d[i].loc != -1)
        {
            tmp = inf;
            for (int j=0; j<m; j++)
            {
                tt = abs(d[i].loc - shel[j].loc); 
                if (tmp > tt)
                {
                   tmp = tt;
                   v = j;                        
                }                
            }
            sum += tmp;
            ans[d[i].id] = v;     
        }
        printf("%I64d\n", sum);
        for (int i=0; i<n; i++) 
        {
            if (i) printf(" ");
            printf("%d", ans[i]+1);
        }
        printf("\n");        
    }

    return 0;
}
