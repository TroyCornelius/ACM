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
#define Maxn 400400
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int sl[Maxn], sr[Maxn], sm[Maxn];
int le[Maxn], ri[Maxn], num[100100];
long long ss[100100];
int n;
bool ans[12];
int fuck[20];
inline int calc(long long x)
{
    while (x / 10 > 0)
    {
        long long  tmp = x, sum = 0;
        while (tmp)
        {
            sum += tmp%10;
            tmp /= 10;
        }
        x = sum;
    }
    return x;
}
void update(int p)
{
    int lson = (p<<1), rson = (p<<1|1);
    sl[p] = sl[lson];
    sr[p] = sr[rson];
    sm[p] = (sm[lson] | sm[rson]);
    long long yys = ss[ri[lson]] - ss[le[lson]-1];
    yys = calc(yys);
    REP(i, 10)
        if ((sl[rson] & (fuck[i])))
        {
            sl[p] |= (fuck[calc(yys+i)]);
        }
    yys = ss[ri[rson]] - ss[le[rson]-1];
    REP(i, 10)
        if ((sr[lson] & (fuck[i])))
        {
            sr[p] |= (fuck[calc(yys+i)]);
        }
    REP(i, 10)
    {
        if (sr[lson] & (fuck[i])){
            sm[p] |= (fuck[i]);
        REP(j, 10)
            if (sl[rson] & (1<<j)){
                sm[p] |= (1<<calc(i+j));
                sm[p] |= fuck[j];
        }
        }
    }
    return;
}
void build(int p, int l, int r)
{
    sl[p] = sr[p] = sm[p] = 0;
    le[p] = l; ri[p] = r;
    if (l == r)
    {
        int tmp = calc(num[l]);
        sl[p] = (1<<tmp);
        sr[p] = (1<<tmp);
        sm[p] = (1<<tmp);
        return;
    }
    int mid = (l + r) >>1;
    build(p<<1, l, mid);
    build(p<<1|1, mid+1, r);
    update(p);
}
struct Tnode
{
    int ssl, ssr, ssm;
    void clr()
    {
        ssl = ssr = ssm = 0;
    }
};
Tnode combine(Tnode tmp1, Tnode tmp2, int x1, int yy1, int x2, int yy2)
{
    Tnode ret;
    ret.clr();
    ret.ssl = tmp1.ssl;
    ret.ssr = tmp2.ssr;
    ret.ssm = (tmp1.ssm | tmp2.ssm);
    long long yys = ss[yy1] - ss[x1-1];
    yys = calc(yys);
    REP(i, 10)
        if ((tmp2.ssl & (fuck[i])))
        {
            ret.ssl |= (fuck[calc(yys+i)]);
        }
    yys = ss[yy2] - ss[x2-1];
    REP(i, 10)
        if ((tmp1.ssr & (fuck[i])))
        {
            ret.ssr |= (fuck[calc(yys+i)]);
        }
    REP(i, 10)
    {
        if ((tmp1.ssr & (fuck[i]))){
            ret.ssm |= (fuck[i]);
            REP(j, 10)
                if ((tmp2.ssl & (fuck[j]))){
                    ret.ssm |= (fuck[calc(i+j)]);
                    ret.ssm |= (fuck[j]);
                }
        }
    }
    return ret;
}
bool flag;
int shit;

Tnode search(int p, int l, int r)
{
    Tnode ret;
    if (flag) return ret;
    if (l <= le[p] && ri[p] <= r)
    {
        ret.ssl = sl[p];
        ret.ssr = sr[p];
        ret.ssm = sm[p];
        int tt = 0;
        REP(i, 10)
            if ((fuck[i] & ret.ssl) || (fuck[i] & ret.ssr) || (fuck[i] & ret.ssm)) tt |= fuck[i];
        if (tt >= 992)
        {
            shit = 992;
            flag = true;
        }
        return ret;
    }
    int mid = (le[p] + ri[p]) >>1;
    if (r <= mid) return search(p<<1, l, r);
    else if (l > mid) return search(p<<1|1, l, r);
    else
    {
        Tnode tmp1 = search(p<<1, l, r);
        if (flag) return ret;
        Tnode tmp2 = search(p<<1|1, l, r);
        if (flag) return ret;
        ret.clr();
        ret = combine(tmp1, tmp2, max(l, le[p<<1]), mid, mid+1, min(r, ri[p<<1|1]));
        int tt = 0;
        REP(i, 10)
            if ((fuck[i] & ret.ssl) || (fuck[i] & ret.ssr) || (fuck[i] & ret.ssm)) tt |= fuck[i];
        if (tt >= 992) flag = true, shit = 992;
        return ret;
    }
}
inline int getint()
{
    int t = 0;
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') 
    {
        t = t * 10 + c - '0';
        c = getchar();
    }
    return t;
}
int main() 
{
    int T, ca = 0;
    T = getint();
    REP(i, 11) fuck[i] = (1<<i);
    while (T--)
    {
        n = getint();
        FOR(i, 1, n+1) num[i] = getint();//sf("%d", &num[i]);
        ss[0] = 0;
        FOR(i, 1, n+1) ss[i] = ss[i-1] + num[i];
        build(1, 1, n);
        int q, a, b, cnt;
        q = getint();
        pf("Case #%d:\n", ++ca);
        while (q--)
        {
            a = getint();
            b = getint();
            flag = false;
            shit = -1;
            Tnode tmp = search(1, a, b);
            cnt = 0;
            if (shit >= 992)
            {
                pf("9 8 7 6 5\n");
            }
            else{
                for (int i = 9; cnt < 5 && i >= 0; i--)
                {
                    if (((fuck[i])&tmp.ssl) || ((fuck[i])&tmp.ssr) || ((fuck[i])&tmp.ssm)) { 
                        pf("%d", i);
                        cnt++;
                        if (cnt != 5) pf(" ");
                    }
                }
                while (cnt < 5)
                {
                    pf("-1");
                    cnt++;
                    if (cnt != 5) pf(" ");
                }
                pf("\n");
            }
        }
        if (T > 0) pf("\n");
    }
    return 0;
}

