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

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define Maxn 101000
#define FOR(i,a,b) for (int i(a); i<(b); i++)
#define REP(i, b) FOR(i,0,b)
using namespace std;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
const int inf = 1<<29;
typedef pair<int,int> pii;
typedef vector<int>::iterator vit;

const long long MOD = 1000000007 ;
int n, k, cnt;
int a[Maxn];
map<int,int> num;
vector<int> d;
long long f[1200][1200];
inline bool check(int t)
{
    while (t)
    {
        if (t%10!=4 && t%10!=7) return false;
        t /= 10;    
    }
    return true;
}
void egcd(long long a,long long b,long long &x,long long &y)
{
	if (b==0)
	{
		x=1;
		y=0;
	}
	else
	{
		egcd(b,a%b,x,y);
		long long k=a/b;
		k=x-k*y;
		x=y;
		y=k;
	}
	return;
}
long long r(long long n)  //求n的逆元，x返回，a/b%MOD = a*r(b)%MOD
{
	long long x,y;
	egcd(n,1000000007,x,y);
	x%=1000000007;
	if (x<0)
		x+=1000000007;
	return x;
}
long long C(long long a,long long b)
{
    long long result=1;
    for(long long i=1;i<=b;i++)
    {
       result = result*(a-i+1) * r(i);
       result %= MOD;
    }
    return result % MOD;
}
int main()
{
   // while (1){
    cnt = 0;
    vector<int> tmp;
    num.clear();
    scanf("%d%d", &n, &k);
    REP(i, n) 
    {
        scanf("%d", &a[i]);
        if (check(a[i]))
        {
            if (num[a[i]] == 0) 
            {
                num[a[i]] = 1;
                tmp.pb(a[i]);
            }
            else num[a[i]]++;        
        }
        else cnt++;
    }
    d.clear();
    REP(i, tmp.size())
    {
        d.pb(num[tmp[i]]);    
    }
    int nn = d.size();
    FOR(i, 0, nn+1) f[0][i] = 0;
    f[0][0] = 1; 
    if (d.size() > 0) f[0][1] = d[0];
    else f[0][1] = 1; 
    FOR(i, 1, nn)
    {
        FOR(j, 0, k)
        {
            if (j == 0) f[i][j] += f[i-1][j];
            else
            {
                f[i][j] = f[i-1][j] + f[i-1][j-1] * (1LL * d[i]);     
                if (f[i][j] >= MOD) f[i][j] %= MOD;       
            }
        }    
    }

    long long ans = C(cnt, k);
    ans %= MOD;
    for (int i=1; i<=nn; i++)
    {
        if (i > k ) break;
     /*   if (cnt - (k-i) <= 0) 
        {
           ans += (f[nn-1][k]);
           break;
        }*/
        ans += (f[nn-1][i] * C(cnt, k-i) % MOD);
        if (ans >= MOD) ans %= MOD;
    }
    
    cout <<ans % MOD <<endl;
//}
system("pause");
    return 0;
}
