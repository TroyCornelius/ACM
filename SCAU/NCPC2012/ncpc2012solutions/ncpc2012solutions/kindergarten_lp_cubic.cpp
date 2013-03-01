//Sample solution for the Kindergarten problem in NCPC 2012 by Lukáš Poláček (lukasP)
#include <vector>
#include <cstdio>
#include <stack>
#include <iostream>
using namespace std;

#define rep(i,a,b) for(__typeof(b) i=a; i<(b); ++i)
#define trav(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)

vector<bool> seen;
int no_vertices, no_components;
stack<int> z;
template<class G> void dfs(int j, G &g) {
    seen[j] = true;
    trav(it,g[j])
        if (!seen[*it])
            dfs(*it, g);
}
template<class G> bool go(G &g) {
    int n = g.size();
    rep(i,0,n / 2)
    {
        seen.assign(n, false);
        dfs(2 * i, g);
        if (seen[2 * i + 1])
        {
            seen.assign(n, false);
            dfs(2 * i + 1, g);
            if (seen[2 * i])
                return false;
        }
    }
    return true;
}
typedef vector<int> vi;
void push(vector<vi> &g, int a, int b)
{
    g[a ^ 1].push_back(b);
    g[b ^ 1].push_back(a);
}
int main()
{
    int n; scanf("%d", &n);
    vector<vi> inp(n);
    rep(i,0,n)
    {
        inp[i] = vi(n);
        rep(j,0,n)
        {
            scanf("%d", &inp[i][j]);
            if (j > 0)
                inp[i][j]--;
        }
    }

    int z = -1, k = n - 1;
    while (z + 1 < k)
    {
        int m = (z + k) / 2;

        vector<vi> g(6 * n);
        rep(i,0,n)
        {
            int i6 = 6 * i;
            g[i6 + 2 * inp[i][0] + 1].push_back(i6 + 2 * inp[i][0]);
            rep(k,0,3) if (k != inp[i][0])
                rep(l,0,3) if (k != l && l != inp[i][0])
                {
                    push(g, i6 + 2 * k + 1, i6 + 2 * l + 1);
                    push(g, i6 + 2 * k, i6 + 2 * l);
                }

            rep(k,0,3) if (k != inp[i][0])
                rep(j,m+1,n)
                    push(g, i6 + 2 * k, inp[i][j] * 6 + 2 * k);
        }

        if (go(g))
            k = m;
        else
            z = m;
    }

    printf("%d\n", k);
}
