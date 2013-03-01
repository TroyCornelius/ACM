//Sample solution for the Food Review problem in NCPC 2012 by Lukáš Poláček (lukasP)
#include <vector>
#include <cstdio>
#include <bitset>
#include <iostream>
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
int extract(int &w, vector<vi> &comp, int component)
{
    int res = comp[component][w % comp[component].size()];
    w /= comp[component].size();
    return res;
}
vector<pii> pruefer(vi &o, int n)
{
    vector<pii> res;
    if (n == 1)
        return res;

    o.push_back(o.size() + 1);
    vector<bool> seen(o.size() + 1, false);
    rep(i,0,o.size())
    {
        vector<bool> tmp = seen;
        rep(j,i,o.size()) tmp[o[j]] = true;
        rep(j,0,tmp.size()) if (!tmp[j])
        {
            res.push_back(pii(j, o[i]));
            seen[j] = true;
            break;
        }
    }
    return res;
}
int main()
{
    int n, r; scanf("%d %d", &n, &r);
    w.assign(n, -1);
    int a[n][n];
    rep(i,0,n) rep(j,0,n)
        a[i][j] = 123456789;

    int need = 0;
    bitset<20> deg;
    rep(i,0,r)
    {
        int x, y, c;
        scanf("%d %d %d", &x, &y, &c);
        x--; y--;
        a[x][y] = a[y][x] = c;
        need += c;
        deg[x] = !deg[x];
        deg[y] = !deg[y];
        spoj(x, y);
    }

    vi boss, icomp(n, -1);
    rep(i,0,n) if ((w[i] < 0 && i == 0) || w[i] <= -2)
    {
        icomp[i] = boss.size();
        boss.push_back(i);
    }

    vector<vi> comp(boss.size());
    rep(i,0,n)
        if ((w[i] < 0 && i == 0) || size(i) > 1)
            comp[icomp[sef(i)]].push_back(i);


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

    int trees = 1;
    rep(i,0,(int)boss.size() - 2)
        trees *= boss.size();

    int res = 123456789;
    //enumerate all k^(k-2) Pruefer sequences
    rep(j,0,trees)
    {
        vi o; int q = j;
        rep(i,0,(int)boss.size()-2)
        {
            o.push_back(q % boss.size());
            q /= boss.size();
        }

        vector<pii> edges = pruefer(o, boss.size());
        int choices = 1;
        rep(i,0,edges.size())
        {
            choices *= comp[edges[i].first].size();
            choices *= comp[edges[i].second].size();
        }

        rep(k,0,choices)
        {
            int w = k;
            int price = 0;
            bitset<20> ndeg = deg;
            for (int i = edges.size() - 1; i >= 0; i--)
            {
                int n1 = extract(w, comp, edges[i].second);
                int n2 = extract(w, comp, edges[i].first);
                price += a[n1][n2];
                ndeg[n1] = !ndeg[n1];
                ndeg[n2] = !ndeg[n2];
            }
            res = min(res, price + match[ndeg.to_ulong()]);
        }
    }

    printf("%d\n", res + need);
}
