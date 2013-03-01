//Sample solution for the Eco-driving problem in NCPC 2012 by Lukáš Poláček (lukasP)
#include <vector>
#include <iostream>
#include <cstdio>
#include <complex>
#include <queue>
using namespace std;

#define rep(i,a,b) for(__typeof(b) i=a; i<(b); ++i)
#define trav(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)

typedef pair<int, int> pii;
typedef pair<int, double> pid;
typedef pair<double, pii> pdp;
typedef complex<double> point;
const double pi = 3.14159265358979323;
double angle(point a, point b)
{
    if (abs(b) < 1e-9 || abs(a) < 1e-9)
        return 0;
    return abs(arg(a / b));
}
int main()
{
    freopen("ecodriving.in", "r", stdin);
    int n, m, d; 
    while (~scanf("%d %d %d", &n, &m, &d)) {
    vector<point> a(n);
    rep(i,0,n)
    {
        int x, y; scanf("%d %d", &x, &y);
        a[i] = point(x, y);
    }

    vector<vector<pid> > g(n);
    rep(i,0,m)
    {
        int x, y; scanf("%d %d", &x, &y);
        x--; y--;
        g[x].push_back(pid(y, abs(a[x] - a[y])));
    }

    double z = 0, k = 1.1 * M_PI;
    rep(iter,0,38)
    {
        double mid = (z + k) / 2;
        bool seen[n][n];
        double dist[n][n];
        rep(i,0,n) rep(j,0,n)
        {
            seen[i][j] = false;
            dist[i][j] = 1e10;
        }

        priority_queue<pdp> q;
        dist[0][0] = 0;

        bool saw = false;
        for (q.push(pdp(0., pii(0, 0))); !q.empty(); q.pop())
        {
            pii v = q.top().second;
            if (seen[v.first][v.second])
                continue;
            if (dist[v.first][v.second] > d)
                break;
            if (v.first == n - 1)
            {
                saw = true;
                break;
            }
            seen[v.first][v.second] = true;

            trav(it,g[v.first])
                if (!seen[it->first][v.first])
            {
                pii nev(it->first, v.first);
                if (angle(a[nev.first] - a[nev.second], a[v.first] - a[v.second]) <= mid &&
                    dist[nev.first][nev.second] > dist[v.first][v.second] + it->second)
                {
                    dist[nev.first][nev.second] = dist[v.first][v.second] + it->second;
                    q.push(pdp(-dist[nev.first][nev.second], nev));
                }
            }
        }

        if (saw)
            k = mid;
        else
            z = mid;
    }

    if (k > 1.05 * pi)
        printf("Impossible\n");
    else
        printf("%.3lf\n", k / pi * 180);
    }
    return 0;
}
