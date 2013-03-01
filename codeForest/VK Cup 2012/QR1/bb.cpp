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
#define Maxn 100010
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int data[Maxn];
int n;
int cnt[10];

void work() 
{
    int ans = 0;
    ans += cnt[4], cnt[4] = 0;
    if(cnt[3] > 0)
    {
        if(cnt[3] >= cnt[1]) 
        {
            ans += cnt[3];
            cnt[1] = cnt[3] = 0;
        }
        else 
        {
            ans += cnt[3];
            cnt[1] -= cnt[3];
            cnt[3] = 0;
        }
    }
    if(cnt[2] > 0) 
    {
        if(cnt[2] & 1) 
        {
            ans += cnt[2] / 2;
            cnt[2] = 1;
        }
        else 
        {
            ans += cnt[2] / 2;
            cnt[2] = 0;
        }
        if(cnt[2] > 0) 
        {
            if(cnt[1] <= 2) 
            {
                ans++;
                cnt[1] = 0;
            }
            else ans++, cnt[1] -= 2;
        }
    }
    if(cnt[1] > 0) ans += (cnt[1] + 3) / 4, cnt[1] = 0;
    cout << ans << endl;
}

int main() 
{
    int s;
    cin >>n;
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < n; i++) 
    {
        cin >> s;
        cnt[s]++;
    }
    work();
    
    return 0;
}
