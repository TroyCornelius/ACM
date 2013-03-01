#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <time.h>
#include <cctype>
#include <functional>
#include <deque>
#include <iomanip>
#include <bitset>
#include <assert.h>
#include <numeric>
#include <sstream>
#include <utility>

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,b) FOR(i,0,b)
#define Maxn 5000
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, k, f[Maxn], e[Maxn];
int t[Maxn], d[Maxn];
void work() 
{ 
    memset(f, 0, sizeof(f)); 
    if (n == k)
    { 
        cout <<86400 <<endl; 
        return;
    }
    else
    {
        int cnt = n - k;
        REP(i, cnt) 
        {
            FORD(j, n-1, i)
            {
                if (!j)
                {
                    f[j] = t[j] - 1;
                    e[j] = t[j] + d[j];
                }
                else
                if (t[j] > e[j-1])
                {
                    f[j] = max(f[j-1], t[j] - e[j-1]);
                    e[j] = t[j] + d[j];
                }
                else
                {
                    f[j] = f[j-1];
                    e[j] = e[j-1] + d[j];
                }
            }
            FOR(j, i, n-1)
                e[j+1] = min(e[j], e[j+1]);
        } 
        int ans = 0;
        FOR(j, cnt-1, n)
            ans = max(ans, max(f[j], 86400-e[j]-1));
        cout <<ans <<endl;
    } 
    
}
int main()
{
    cin >>n >>k; 
    REP(i, n)
    {
        cin >>t[i] >>d[i];
        e[i] = 1;
    } 
    work(); 
    return 0; 
} 

