/*
 * Author:  Troy
 * Created Time:  2012/5/27 0:21:11
 * File Name: bb.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <time.h>
#include <cctype>
#include <functional>
#include <deque>
#include <iomanip>
#include <bitset>
#include <assert.h>
#include <numeric>
#include <sstream>
#include <utility>

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,b) FOR(i,0,b)
#define sf scanf
#define pf printf
#define Maxn 1100
using namespace std;
const int inf = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
int n,w,l,r[Maxn],h[Maxn];
bool flag;
double x[Maxn],y[Maxn],s[Maxn];
double calc(int x,int y)
{
    int t=rand()%1000000+1;
    int s=rand()%t+1;
    return (y-x)*(s*1.0/t)+x;
}
double getdis(double x,double y,double a,double b)
{
    return sqrt( (x-a)*(x-a)+(y-b)*(y-b) );
}
void dfs(int m)
{
    double cx,cy;
    int j;
    bool f=false;
    s[h[m]]=inf;
    if (m>n)
    {
        //for (i=1;i<=n;i++) 
        FOR(i, 1, n+1)
        {
            pf(" %.2lf %.2lf",x[i],y[i]);
        }
        pf("\n");
        flag = true;
        return ;
    }
    FOR(i, 1, 101)
    {
        double ss=inf,t;
        cx=calc(0,w);
        cy=calc(0,l);
        for (j = 1; j<m; j++)
            if ((t=getdis(x[h[j]],y[h[j]],cx,cy))<r[h[j]]+r[h[m]])
            {
                if (ss>t) ss=t;
                break;
            }
        if (j==m)
        {
            if (s[h[m]]==inf || s[h[m]]>ss)
                x[h[m]]=cx,y[h[m]]=cy,s[h[m]]=ss;
            f=true;
        }
    }
    if (!f) return;
    dfs(m+1);
    if (!flag) dfs(m);
}
bool cmp(int x, int y)
{
    return r[x] > r[y];
}
int main()
{
    int T,ca=0;
    freopen("B-large.in","r",stdin);
    freopen("B.out","w",stdout);
    sf("%d",&T);
    while (T--)
    {
        sf("%d%d%d",&n,&w,&l);
        FOR(i, 1, n+1) 
        {
            sf("%d", &r[i]);
            h[i]=i;
        }
        sort(h+1,h+n+1,cmp);
        pf("Case #%d:",++ca);
        
        
        flag=false;
        dfs(1);
    }
    return 0;
}
