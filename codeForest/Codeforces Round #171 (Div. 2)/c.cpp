/*
 * Author:  Troy
 * Created Time:  2013/3/4 23:50:52
 * File Name: c.cpp
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
#define ll long long
#define sf scanf
#define pf printf
#define Maxn 100010
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, m, a[Maxn];
int Min[Maxn][30], Max[Maxn][30]; //第2维是log(n)个数，小心开大了爆了内存
void initRMQ() {
    for(int i = 1; i <= n; i++) Max[i][0] = Min[i][0] = i;
    for(int k = 1; (1<<k) <= n; k++) {
        for(int i = 1; i + (1<<k) - 1 <= n; i++) {
            if (a[Max[i][k-1]] > a[Max[i+(1<<(k-1))][k-1]])
                Max[i][k] = Max[i][k-1];
            else 
                Max[i][k] = Max[i+(1<<(k-1))][k-1];
            
            if (a[Min[i][k-1]] < a[Min[i+(1<<(k-1))][k-1]])
                Min[i][k] = Min[i][k-1];
            else 
                Min[i][k] = Min[i+(1<<(k-1))][k-1];
        }
    }
}
//有时查询次数过多，取log很慢，可以先预处理所有log
int MinRMQ(int x, int y) {
    int k = int(log(0.0 + y - x + 1.0) / log(2.0));
    return a[Min[x][k]] < a[Min[y-(1<<k)+1][k]] ? Min[x][k] : Min[y-(1<<k)+1][k];
}
int MaxRMQ(int x, int y) {
    int k = int(log(0.0 + y - x + 1.0) / log(2.0));
    return a[Max[x][k]] > a[Max[y-(1<<k)+1][k]] ? Max[x][k] : Max[y-(1<<k)+1][k];
}
int main() {
    ios::sync_with_stdio(false);
    cin >>n >>m;
    FOR(i, 1, n+1) cin >>a[i];
    initRMQ();
    int l, r;
    while (m--) {
        cin >>l >>r;
        int mid = MaxRMQ(l, r);
        int lm = MinRMQ(l, mid);
        int rm = MinRMQ(mid, r);
        cout <<mid << " "<<lm <<" "<<rm <<endl;
        if (a[lm] == a[l] && a[rm] == a[r]) cout <<"Yes" <<endl;
        else cout <<"No" <<endl;
    }
    
    return 0;
  
}

