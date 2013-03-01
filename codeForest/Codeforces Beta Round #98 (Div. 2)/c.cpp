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
#define Maxn 101000
using namespace std;
int n;
typedef pair<int,int> pii;
pair<int, int> d[Maxn];
bool cmp(pii a, pii b)
{
    return (a.fi < b.fi || (a.fi==b.fi && a.se > b.se));
}
int main()
{
    int a, b;
    scanf("%d", &n);
    for (int i =0; i<n; i++)
    {
        scanf("%d%d", &a, &b);
        d[i] = mp(a, b); 
    }

    sort(d, d+n, cmp);
    int ans = 0;
    int p = 0;
    for (int i=1; i<n; i++)
    {
        if (d[i].fi> d[p].fi && d[i].se < d[p].se)
        {
            ans++;        
        }
        else
            if (d[i].se > d[p].se) p = i;    
    }
    cout <<ans <<endl;

    return 0;
}


