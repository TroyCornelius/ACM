#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

#define rep(i,a,b) for(__typeof(b) i=a; i<(b); ++i)

typedef vector<int> vi;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> names(n);
    vi x(n), y(n);
    map<string, int> id;
    rep(i,0,n)
    {
        cin >> names[i] >> x[i] >> y[i];
        id[names[i]] = i;
    }

    double d[n][n];
    rep(i,0,n) rep(j,0,n)
        d[i][j] = 1e20 * (i != j);

    vector<bool> seen(n, false);
    rep(i,0,m)
    {
        string s, a, b, c;
        cin >> a >> s >> b >> s >> s >> c;
        int u = id[a], v = id[b], w = id[c];
        double dif = hypot(x[u] - x[w], y[u] - y[w]) - hypot(x[u] - x[v], y[u] - y[v]);
        seen[v] = seen[w] = true;
        d[v][w] = min(d[v][w], dif);
    }

    rep(k,0,n) if (seen[k])
        rep(i,0,n) rep(j,0,n)
            d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    rep(i,0,n) if (d[i][i] < 0)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    int cnt = count(seen.begin(), seen.end(), true);
    vector<string> res;
    rep(k,0,cnt)
    {
        vi cand;
        rep(i,0,n) if (seen[i])
        {
            bool ok = true;
            rep(j,0,n) if (seen[j])
                if (d[i][j] > 0)
                    ok = false;
            if (ok) cand.push_back(i);
        }

        if (cand.size() == 1)
        {
            res.push_back(names[cand[0]]);
            seen[cand[0]] = false;
        }
    }
    if (res.size() < cnt)
        cout << "UNKNOWN" << endl;
    else
        rep(k,0,cnt)
        {
            cout << res[k];
            if (k + 1 < cnt) cout << " ";
            else cout << endl;
        }
}
int main()
{
    int tests; scanf("%d", &tests);
    while (tests--)
        solve();
}
