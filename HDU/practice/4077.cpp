#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<cstdlib>
#include<algorithm>
#include <cmath>
#define Maxn 1024
#define mp make_pair
#define fi first
#define se second
using namespace std;

const double inf = 1e300;
const double eps = 1e-11;
int n;

struct Tnode
{
    double x[2], y;
} gate[Maxn];
struct Line
{
       pair<double,double>p1, p2;
       };
double dp[Maxn][3];

/*inline bool check(double x1, double y1, double x2, double y2, int st, int en)
{
    double a = y2 - y1;
    double b = x1 - x2;
    double c = x2*y1 - x1*y2;
    double tx;
    for (int i=st+1; i<=en-1; i++)
    {
        tx = (b*gate[i].y + c) / (-a);
        if (tx >= gate[i].x[0] && tx <= gate[i].x[1]) continue;
        else return false; 
    }
    return true;   
}*/
inline double calc(double x1, double y1, double x2, double y2)
{
    double tx = x1 - x2, ty = y1 - y2;
    return sqrt(tx*tx + ty*ty);
}
inline double get_x(Line t, double yt)
{
       return (yt - t.p1.se) * (t.p2.fi - t.p1.fi) / (t.p2.se - t.p1.se) + t.p1.fi;
       }

int main()
{
    while (~scanf("%d", &n), n)
    {
        scanf("%lf%lf", &gate[0].x[0], &gate[0].y);
        gate[0].x[1] = gate[0].x[0];
        for (int i = 1; i <= n; i++) scanf("%lf%lf%lf", &gate[i].y, &gate[i].x[0], &gate[i].x[1]);

        for (int i = 0; i <= n; i++)
            for (int j = 0; j < 3; j++)
                dp[i][j] = inf;
        dp[0][0] = dp[0][1] = dp[0][2] = 0.0;

        bool flag;
        double lx, rx;
        for (int i = 0; i < n; i++)
        {
            for (int t = 0; t < 2; t++)
            {         
                Line le, ri;
                le.p1 = ri.p1 = mp(gate[i].x[t], gate[i].y);     
                le.p2 = mp(gate[i+1].x[0], gate[i+1].y);
                ri.p2 = mp(gate[i+1].x[1], gate[i+1].y);  
                for (int j = i + 1; j <= n; j++)
                {
                    lx = get_x(le, gate[j].y); rx = get_x(ri, gate[j].y);
                    if (fabs(lx - rx) < eps) break;
                    if (gate[j].x[0] >= lx && gate[j].x[0] <= rx)
                    {
                        le.p2 = mp(gate[j].x[0], gate[j].y);
                        dp[j][0] = min(dp[j][0], dp[i][t] + calc(gate[i].x[t], gate[i].y, gate[j].x[0], gate[j].y));                   
                    }
                    if (gate[j].x[1] >= lx && gate[j].x[1] <= rx)
                    {
                        ri.p2 = mp(gate[j].x[1], gate[j].y);
                        dp[j][1] = min(dp[j][1], dp[i][t] + calc(gate[i].x[t], gate[i].y, gate[j].x[1], gate[j].y));                       
                    }                   
                }
                flag = true;
                for (int j=i+1; j<=n; j++)
                    if (gate[j].x[0] > gate[i].x[t] || gate[j].x[1] < gate[i].x[t])
                    {
                        flag = false;
                        break;
                    }
                if (flag) dp[n][2] = min(dp[n][2], dp[i][t] + gate[i].y - gate[n].y);
            }
        }
        printf("%.8f\n", min(dp[n][0], min(dp[n][1], dp[n][2])));

    }
//system("pause");

    return 0;
}


