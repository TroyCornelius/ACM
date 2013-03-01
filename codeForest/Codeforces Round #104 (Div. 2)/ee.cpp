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
const long long MOD = 1000000007LL;
typedef pair<int,int> pii;
typedef vector<int>::iterator vit;

inline bool islucky(int t)
{
    while (t)
    {
        if (t % 10 != 4 && t%10 != 7) return false;
        t /= 10;
    }
    return true;
}

int n, k, num[Maxn], m;
int b[1100], tot;
long long f[Maxn], p[Maxn];
map<int, int> sum;
void egcd(long long a, long long b, long long &x, long long &y)
{
    if (b == 0)
    {
        x = 1; y = 0;
    }
    else
    {
        egcd(b, a%b, x, y);
        long long k = a/b;
        k = x - k * y;
        x = y; y = k;
    }
}
long long r(long long dig)
{
    long long x, y;
    egcd(dig, MOD, x, y);
    x %= MOD;
    if (x < 0) x += MOD;
    return x;
}
long long C(int a, int b)
{
    if (a==0 || b==0) return 1;
    long long tmp = p[a] * r(p[b]);
    tmp = ((tmp%MOD) * r(p[a-b])) % MOD;
    return tmp;   
}
int main()
{
    cout <<(1<<3|1) <<endl;
    //while (1){
    m = 0;
    sum.clear();
    scanf("%d%d", &n, &k);
    REP(i, n)
    {
        scanf("%d", &num[i]);
        if (islucky(num[i])) sum[num[i]]++;
        else m++;    
    }
    
    memset(b, 0, sizeof(b));
    tot = 0;
    for (map<int,int>::iterator it = sum.begin(); it!=sum.end(); it++) b[tot++] = it->second;
    
    memset(f, 0, sizeof(f));
    
    f[0] = 1;
    REP(i, tot)
        for (int j=k; j>0; j--)
            f[j] = (f[j] + f[j-1]*(long long)b[i]) % MOD;

    long long ans = 0;
    p[0] = 1;
    FOR(i,1,n+1) p[i] = (p[i-1] * i) % MOD;
    
    for (int i=0; i<=k && i<=m; i++)
        ans = (ans + f[k-i] * C(m, i)) %MOD;  
    cout <<ans <<endl;
  //  }
    return 0;    
}
