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
#define Maxn 20050
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int t[Maxn], n, ans;
int main() 
{
    cin >>n;
    ans = 0;
    REP(i, n)
    {
        cin >>t[i];
        ans += t[i];
    }
    
    FOR(i, 3, n)
    if (n % i == 0)
    {
        int tmp = n / i;
        REP(j, tmp)
        {
            int cnt = 0;
            for (int k = j; k < n; k += tmp)
                cnt += t[k];
            ans = max(ans, cnt);
        }
    }
    cout <<ans <<endl;
    return 0;
}

