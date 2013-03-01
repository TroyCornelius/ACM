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
const long long inf = 1LL<<30;
int n, m;
struct Room
{
        long long wid, len, hei;
}r[800];
struct Tnode
{
    long long p;
    long long len, wid; 
}pa[800];
int main()
{

    cin >>n;
    for (int i=0; i<n; i++) cin >>r[i].len >>r[i].wid >>r[i].hei;
    cin >>m;
    for (int i=0; i<m; i++) cin >>pa[i].len >>pa[i].wid >>pa[i].p;
    
    long long ans = 0, tmp;
    long long area;
    for (int i=0; i<n; i++)
    {
        area = 2 * (r[i].len + r[i].wid);
        tmp = inf;
        for (int j=0; j<m; j++)
        {
            long long t = pa[j].len / r[i].hei;
            if (t == 0) continue;
            long long cnt = area / (t * pa[j].wid);
            if ((area % (t * pa[j].wid)) != 0) cnt++;
            cnt *= pa[j].p;
            if (cnt < tmp) tmp = cnt;        
        }
        ans += tmp;         
    }
    cout <<ans <<endl;

    return 0;
}
