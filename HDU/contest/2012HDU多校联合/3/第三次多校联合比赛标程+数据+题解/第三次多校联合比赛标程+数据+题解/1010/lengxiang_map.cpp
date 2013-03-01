#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
#include <ctime>
#include <cstring>
#include <sstream>
using namespace std;

typedef long long LL;
typedef pair<string,int> PSI;
typedef vector<int> VI;
typedef vector<string> VS;

#define mp make_pair
#define F first
#define S second
#define sz(x) ((int)(x.size()))
#define rep(i,n) for(int i=0;i<(n);i++)
#define FOR(i,l,r) for(int i=(l);i<=(int)(r);i++)
#define FORD(i,r,l) for(int i=(r);i>=(int)(l);i--)
#define pb push_back
char a[105][10010];
char b[105][10010];
double f(char *aa,char *bb)
{
    map <string,int> v;
    istringstream a(aa);
    istringstream b(bb);
    string s;
    double ret=0;
    int num=0,id=0,cnt=0;
    a>>s;
    while(a>>s)
    {
        v[s]=1;
        num++;
    }
    b>>s;
    while(b>>s)
    {
        cnt++;
        if(v[s])
        {
            id++;
            ret+=1.0*id/cnt;
        }
    }
    return ret/num;
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        rep(i,n)gets(a[i]);
        rep(i,n)gets(b[i]);
        double ans = 0;
        rep(i,n)ans+=f(a[i],b[i]);
        printf("%.6lf\n",ans/n);
    }
}

































