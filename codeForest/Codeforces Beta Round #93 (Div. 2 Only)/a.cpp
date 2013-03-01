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
using namespace std;

struct Tnode
{
       double x, y;
       }d[110];
int n;
double k;
inline double dis(Tnode &a, Tnode &b)
{
       double tx = a.x - b.x;
       double ty = a.y - b.y;
       return sqrt(tx*tx + ty*ty);
       }
int main()
{
    scanf("%d%lf", &n, &k);
    double ans = 0;
    for (int i=0; i<n; i++)
    {
        scanf("%lf%lf", &d[i].x, &d[i].y);
        if (i>0) ans += dis(d[i], d[i-1]);
    }
    ans /= 50.0;
    ans *= k;
    printf("%.7f\n", ans);

    return 0;
    }
