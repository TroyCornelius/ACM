#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
using namespace std;
typedef __int64 ll;
ll gcd(ll a,ll b)
{
	return (b==0)?a:gcd(b,a%b);
}
ll Mulmod(ll a,ll b,ll n)
{
    ll  exp = a%n, res = 0;
    while(b)
    {
        if(b&1)
        {
            res += exp;
            if(res>n) res -= n;
        }
        exp <<= 1;
        if(exp>n)
            exp -= n;

        b>>=1;
    }
    return res;
}

ll exp_mod(ll a,ll b,ll c)
{
	ll k = 1;
	while(b)
	{
		if(b&1)
			k = Mulmod(k,a,c);
		a = Mulmod(a,a,c);
		b>>=1;
	}
	return k;
}
bool Miller_Rabbin(ll n, ll times)
{
    if(n==2)return 1;
    if(n<2||!(n&1))return 0;

    ll a, u=n-1, x, y;
    int t=0;
    while(u%2==0){
        t++;
        u/=2;
    }
    srand(100);
    for(int i=0;i<times;i++)
    {
        a = rand() % (n-1) + 1;
        x = exp_mod(a, u, n);
        for(int j=0;j<t;j++)
        {
            y = Mulmod(x, x, n);
            if ( y == 1 && x != 1 && x != n-1 )
                return false; //must not
            x = y;
        }
        if( y!=1) return false;
    }
    return true;
}

ll Pollard_Rho(ll n,ll c)
{
	ll x,y,d,i=1,k=2;
	y = x = rand() % (n-1) + 1;
	while(1)
	{
		i++;
		x = (Mulmod(x,x,n) + c)%n;
		d = gcd((x-y+n)%n,n);
		if(d>1&&d<n)
			return d;
		if(x==y)
			return n;
		if(i==k)
		{
			k<<=1;
			y = x;
		}
	}
}
ll factor[200],cnt;
void Find_factor(ll n,ll c)
{
	if(n==1)
		return;
	if(Miller_Rabbin(n,6))
	{
		factor[cnt++] = n;
		return;
	}
	ll p = n;
	ll k = c;
	while(p>=n)
		p = Pollard_Rho(p,c--);
	Find_factor(p,k);
	Find_factor(n/p,k);
}
ll a_b(ll a,ll b)
{
    ll ans = 1;
    for(ll i=0; i<b; i++)
    ans*=a;
    return ans;
}
int main()
{
	int t;
	scanf("%d",&t);
	ll n;
	while(t--)
	{
		scanf("%I64d",&n);
		cnt = 0;
		Find_factor(n,120);
		map<ll,int>m0;
		for(int i=0; i<cnt; i++)
		{
		    m0[factor[i]]++;
		}
		map<ll,int>::iterator iter;
		int size = m0.size();
		if(size==1)
		{
		    printf("%d %I64d\n",size,n/factor[0]);
		    continue;
		}
		ll sum = 0;
		for(iter=m0.begin(); iter!=m0.end(); iter++)
		sum+=a_b(iter->first,iter->second);
		printf("%d %I64d\n",size,sum);
	}

}
