//Sample solution for the Food Review problem in NCPC 2012 by Lukáš Poláček (lukasP), complexity
//(2.82)^N but probably less
#include <vector>
#include <cstdio>
#include <bitset>
#include <iostream>
#include <map>
using namespace std;

#define rep(i,a,b) for(__typeof(b) i=a; i<(b); ++i)
#define trav(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)

typedef vector<int> vi;
typedef pair<int, int> pii;
void improvMin(int &a, int b)
{
    a = min(a, b);
}
vector<int> w;
int sef(int a) {
    if (w[a]<0) return a;
    return w[a]=sef(w[a]);
}
bool spoj(int a, int b) {
    int x=sef(a), y=sef(b);
    if (x==y) return false;
    if (w[x]>w[y]) swap(x, y);
    w[x]+=w[y]; w[y]=x;
    return true;
}
int size(int a) {
    return -w[sef(a)];
}

int main()
{
    int n, r; scanf("%d %d", &n, &r);
    w.assign(n, -1);
    int a[n][n];
    rep(i,0,n) rep(j,0,n)
        a[i][j] = 123456789;

    int included = 0;
    bitset<20> deg;
    rep(i,0,r)
    {
        int x, y, c;
        scanf("%d %d %d", &x, &y, &c);
        x--; y--;
        a[x][y] = a[y][x] = c;
        included += c;
        deg[x] = !deg[x];
        deg[y] = !deg[y];
        spoj(x, y);
    }

    vi icomp(n, -1);
    int compon = 0;
    rep(i,0,n) if ((w[i] < 0 && i == 0) || w[i] <= -2)
        icomp[i] = compon++;

    vector<bitset<20> > comp(compon);
    bitset<20> need;
    rep(i,0,n) if (i == 0 || size(i) >= 2)
    {
        need[i] = true;
        comp[icomp[sef(i)]][i] = true;
    }

    int f; scanf("%d", &f);
    rep(k,0,f)
    {
        int x, y, c;
        scanf("%d %d %d", &x, &y, &c);
        x--; y--;
        improvMin(a[x][y], c);
        a[y][x] = a[x][y];
    }

    rep(k,0,n)
        rep(i,0,n) rep(j,0,n)
            improvMin(a[i][j], a[i][k] + a[k][j]);

    int s = 1 << n;
    vi match(s, 123456789);
    match[0] = 0;
    rep(k,0,s)
    {
        bitset<20> b(k);
        rep(i,0,n) if (!b[i])
            rep(j,i+1,n) if (!b[j])
                improvMin(match[k | (1 << i) | (1 << j)], match[k] + a[i][j]);
    }

    vector<map<int, int> > best(s);
    vi beg(n); int stockh = icomp[sef(0)];
    best[comp[stockh].to_ulong()][(comp[stockh] & deg).to_ulong()] = 0;

    int res = 123456789;
    rep(k,0,s) trav(jt,best[k])
    {
        bitset<20> pari(jt->first), state(k);
        rep(i,0,n) if (state[i])
            rep(j,0,n) if (need[j] && !state[j] && a[i][j] < 123456789)
            {
                bitset<20> npari = pari | (comp[icomp[sef(j)]] & deg);
                bitset<20> conn = state | comp[icomp[sef(j)]];
                npari[i] = !npari[i];
                npari[j] = !npari[j];
                if (!best[conn.to_ulong()].count(npari.to_ulong()))
                    best[conn.to_ulong()][npari.to_ulong()] = jt->second + a[i][j];
                else
                    improvMin(best[conn.to_ulong()][npari.to_ulong()], jt->second + a[i][j]);
            }

        if (need == state)
            res = min(res, match[pari.to_ulong()] + jt->second);
    }

    printf("%d\n", res + included);
}
