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
#define FOR(i,a,b) for(int i(a); i<(b); i++)
#define REP(i, n) FOR(i, 0, n)
#define Maxn 1100
using namespace std;

int n, a[Maxn];

int main()
{
    cin >>n;
    for (int i=0; i<n; i++) cin >>a[i];
    sort(a, a+n);
    
    int ans=0, pent=0, now = -6*60+10;
    
    REP(i, n)
    {
        now += a[i];
        if (now > 360) break;
        ans++;
        if (now > 0) pent += now;  
    }
    cout <<ans <<" "<<pent <<endl;
    return 0;
}
