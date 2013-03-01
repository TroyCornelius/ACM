#include "iostream"
#include "cstdio"
#include "cstring"
#include "algorithm"
#include "vector"
#include "queue"
#include "stack"
#include "cmath"
#include "string"
#include "cctype"
#include "map"
#include "iomanip"
#include "set"
#include "utility"
using namespace std;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lc(x) (x << 1)
#define rc(x) (x << 1 | 1)
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,b) FOR(i,0,b)
#define lowbit(x) (x & (-x))
#define ll long long
#define ull unsigned long long
const int inf = 1 << 29;
const double dinf = 1e30;
const ll linf = 1LL << 55;
const int M = 1000;
const int N = 111111;
int a[N], b[N], c[N << 1];
ll fac[N<<1];
vector<int> vec;
bool pri[N];
int pn[N], cnt_p;
void get_prime() {
    cnt_p = 0;
    memset(pri, true, sizeof(pri));
    for (ll i = 2; i * i <= 1000000000+7; i++)
        if (pri[i]) {
            pn[cnt_p++] = i;
            for (ll j = i*i; j * j<= 1000000000+7; j += i) pri[j] = false;
        }
}
int subpri[110], len; //subpri保存模数
void calc(ll num)
{
    len = 0;
    for (int i = 0; i < cnt_p; i++) {
        if (num % pn[i] == 0) subpri[len++] = pn[i];
        while (num % pn[i] == 0) num /= pn[i];
    }
    if (num > 1 || len == 0) subpri[len++] = num;
    
    //cout <<len <<endl;
    //REP(i, len) cout <<subpri[i] <<" ";
    //cout <<endl;
}
int rem[110]; //保存余数
void exgcd(ll a, ll b,ll &x, ll &y)
{
    if (b==0) {
        x=1, y=0;
    }
    else {
        exgcd(b,a%b,x,y);
        int k=a/b;
        k=x-k*y;
        x=y, y=k;
    }
    return;
}
ll china_remainder(int n)
{
    ll ret, m = 1, mid, x, y;
    REP(i, n) m *= subpri[i];
    ret = 0;
    REP(i, n) {
        mid = m / subpri[i];
        exgcd(mid, subpri[i], x, y);
        ret = (ret + mid * x * rem[i]) % m;
    }
    if (ret < 0) ret += m;
    return ret;
}
ll get_ni(ll num, int m) //费马小定理求num相对于m的逆元
{
    ll ret = 1, tmp = num;
    int tt = m - 2;
    while (tt) {
        if (tt & 1) ret = ret * num % m;
        num = num * num % m;
        tt >>=1;
    }
    return ret;
}

//calc(mod);
//REP(i, len) rem[i] = solve(n, subpri[i]);
//pf("%I64d\n", china_remainder(len));

ll solve(ll x, ll mod) {
    cout <<mod <<" "<<get_ni(2, mod) <<endl;
    return x * get_ni(2, mod) % mod;
}
int main() {

int n;
get_prime();
    while (cin >> n) {
        vec.clear();
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            vec.pb(a[i]);
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            vec.pb(b[i]);
        }
        ll m;
        cin >> m;
        fac[0] = 1;
        for (int i = 1; i < (N << 1); i++) {
            fac[i] = (fac[i-1] * i) % m;
        }
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
        memset(c, 0, sizeof(c));
        for (int i = 0; i < n; i++) {
            c[lower_bound(vec.begin(), vec.end(), a[i]) - vec.begin()]++;
            c[lower_bound(vec.begin(), vec.end(), b[i]) - vec.begin()]++;
        }
        ll ans = 1;
        calc(m);
        for (int i = 0; i < vec.size(); i++) {
            ans = (ans * fac[c[i]]) % m;
        }
        //cout <<ans <<"---- " <<endl;
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i]) {
                //ans = (ans / 2) % m;
                cout <<"ca "<<" "<<len <<endl;
                REP(k, len) {
                    rem[k] = solve(ans, subpri[k]);
                    //cout <<rem[k] <<" "<<k <<endl;
                }
                ans = china_remainder(len);
            }
        }
        cout <<ans <<endl;
    }
    return 0;
}
