/*
 * Author:  Teletubbies
 * Created Time:  2012年09月15日 星期六 12时10分40秒
 * File Name: 
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
#define Maxn 100050
using namespace std;
const long long inf = 1LL<<60;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, L;
int w[Maxn], h[Maxn];
int rmq[Maxn][21];
int que[Maxn];
long long dp[Maxn], sum[Maxn];
void init_rmq() {
    REP(i, n) rmq[i][0] = h[i+1];
    for (int j = 1, k = 2; k <= n; ++j, k<<=1)
        for (int i = 0; i + k - 1 < n; ++i)
            rmq[i][j] = rmq[i][j-1] > rmq[i+(k>>1)][j-1] ? rmq[i][k-1] : rmq[i+(k>>1)][j-1];
}
int query(int a, int b) {
    a--;b--;
    int d = b - a + 1;
    int k , t;
    for (k = 0, t = 1; (t<<1)<d; t<<=1, k++);
    return max(rmq[a][k], rmq[b-t+1][k]);
}
int main() {
    
    freopen("H.in", "r", stdin);
    
    while (~sf("%d%d", &n, &L)) {
        sum[0] = 0;
        FOR(i, 1, n+1) {
            sf("%d%d", &h[i], &w[i]);
            sum[i] = sum[i-1] + w[i];
        }
        init_rmq();
        REP(i, n+1) dp[i] = inf;
        dp[0] = 0;
        int head = 0, tail = 0;
        que[tail++] = 0;
        for (int i = 1; i <= n; ++i) {
            while (head < tail && sum[i] - sum[que[head]] > L) head++;
            
            for (int j = head, ct = 0; j < tail && ct <= 100; ++j, ++ct) {
                dp[i] = min(dp[i], dp[que[j]] + query(que[j]+1, i));
            }
            for (int j = tail-1, ct = 0; j >= head && ct <= 100; --j, ++ct) {
                dp[i] = min(dp[i], dp[que[j]] + query(que[j]+1, i));
            }
            for (int j = (head + tail-1)/2, ct = 0; j < tail && ct <= 100; ++j, ++ct) {
                dp[i] = min(dp[i], dp[que[j]] + query(que[j]+1, i));
            }
            for (int j = (head+tail-1)/2, ct = 0; j >= head && ct <= 100; --j, ++ct) {
                dp[i] = min(dp[i], dp[que[j]] + query(que[j]+1, i));
            }
            //cout <<i <<" :" <<que[head] <<" "<<endl;
            while (head < tail && dp[i] < dp[que[tail-1]]) tail--;
            que[tail++] = i;
        }
        //for (int i = 1; i <= n; ++i) cout <<dp[i] <<" ";
        //cout <<endl;
        //cout <<dp[n] <<endl;
        pf("%I64d\n", dp[n]);
    }
    
    while(1);
    
    return 0;
}


