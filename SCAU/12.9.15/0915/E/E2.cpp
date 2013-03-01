/*
 * Author:  Teletubbies
 * Created Time:  2012年09月15日 星期六 16时55分23秒
 * File Name: 1005.cpp
 */
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
#define sf scanf
#define pf printf
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
const int inf = 1 << 29;
#define ll long long
ll funny[110][25005];
ll ti[110][25005];
ll dp[25005];
int cnt[110];
int n, a[110], b[110], t[110];
int bsearch(int a, int b) {
    int l = 1, r = 25000;
    int res = -1;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(a >= (mid - 1) * (mid - 1) * b) res = mid, l = mid + 1;
        else r = mid - 1;
    }
    return res;
}

int main() 
{
    freopen("E.in", "r", stdin);
    freopen("E2.out", "w", stdout);
    
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; i++) {
            scanf("%d%d%d", &a[i], &b[i], &t[i]);
        }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < 25005; j++)
                funny[i][j] = 0, ti[i][j] = inf;
        for(int i = 0; i < n; i++) {
            int maxCnt = 25000 / t[i];
            maxCnt = min(maxCnt, bsearch(a[i], b[i]));
            cnt[i] = maxCnt;
            funny[i][0] = ti[i][0] = 0;
            for(int j = 1; j <= maxCnt; j++) {
                funny[i][j] = funny[i][j-1] + a[i] - (j - 1) * (j - 1) * b[i];
                ti[i][j] = j * t[i];
            }
        }
        /*
        getchar();
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 25005; j++) {
                if(ti[i][j] == inf) break;
                cout << funny[i][j] << " " << ti[i][j] << "**";
            }
            cout << endl;
        }
        */
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < n; i++) {
            for(int cap = 25000; cap; cap--) {
                for(int j = 0; j <= cnt[i]; j++) {
                    if(ti[i][j] > cap) break;
                    dp[cap] = max(dp[cap], dp[cap-ti[i][j]] + funny[i][j]);
                }
            }
        }
        int Q;
        scanf("%d", &Q);
        while(Q--) {
            int x;
            scanf("%d", &x);
            printf("%I64d\n", dp[x]);
            //cout << dp[x] << endl;
        }
    }
    
    //while(1);
    
    return 0;
}


