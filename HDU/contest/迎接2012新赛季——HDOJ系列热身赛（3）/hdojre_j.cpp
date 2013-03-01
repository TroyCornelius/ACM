#include <iostream>
#include <cstdio>
                   
using namespace std;
                   
#define eps 1e-8
#define pi acos(-1.0)
#define inf 1<<30
#define linf 1LL<<60
#define pb push_back
#define lc(x) (x << 1)
#define rc(x) (x << 1 | 1)
#define lowbit(x) (x & (-x))
#define ll long long
#define mod 1000000007

bool is[10000010];
int prm[2000010];
int cnt,num,n;
ll sum[10000010];
inline ll power_mod(ll a,ll b,ll c){
     ll ans=1;
     while (b){
        if (b%2==1) ans = (ans*a)%c;
        b/=2;
        a=(a*a)%c;
     } 
    return ans;
}

int get_prime(int m)
{
	/*ll i,j,k=0;
	ll s,e=(ll)(sqrt(1.0*n)+1);
	memset(is,1,sizeof(is));
	prm[k++]=2;
	is[0]=is[1]=0;
	for (i=4; i<n; i+=2) is[i]=0;
	for (i=3; i<e; i+=2) 
	   if (is[i])
	   {
	      prm[k++]=i;
	      for (s=i*2, j=i*i; j<n; j+=s)
	          is[j]=0; 
	   }
	for (; i<n; i+=2) if (is[i]) prm[k++]=i;
	return k;                            //返回素数的个数 */
    int k = 0;
    sum[0] = 1; sum[1] = 1;
    //memset(is, true, sizeof(is));
    for (int i=2; i<m; i++)
        if (!is[i])
        {
            sum[i] = sum[i-1];
            prm[k++] = i;
            for (long long j = 1LL * i * i; j<m; j+=i) is[j] = true;
        }
        else sum[i] = (sum[i-1] * i) % mod;
    return k;
}

int main() {
    num=get_prime(10000001);
    //cout << prm[num-1] << endl;
   // ios::sync_with_stdio(false);
    while (cin >>n){
        if (!n) break;
        ll ans = sum[n];
        for (int i=0; i<num && prm[i]<=n; ++i){
            int tmp = n;
            int cnt=0;
            while (tmp){
                cnt+=tmp/prm[i];
                tmp/=prm[i];
            }
          //  cout << prm[i] << " " << cnt << endl;
            if (cnt % 2 == 0) ans = (ans * prm[i]) % mod;
           // ans = (ans*power_mod(prm[i],cnt,mod) )%mod;
        }
        cout << ans << endl;
    }
    return 0;
}
