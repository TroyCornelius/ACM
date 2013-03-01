/*
 * Author:  Troy
 * Created Time:  2012/12/27 23:36:16
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
#define Maxn 100110
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, x;
ll a[Maxn], b[Maxn];
void output() {
    FOR(i, 1, n+1) pf("%I64d%c", a[i], i == n ? '\n' : ' ');
}
bool check(int p) {
    //FOR(t, 1, n+1) pf("%I64d%c", a[t], t == n ? '\n' : ' ');
    FOR(i, 1, n+1)
        if (a[i] == 0) return false;
    /*
    ll sum = a[p];
    a[p] = 0;
    p++;
    if (p > n) p = 1;
    if (a[p] == 0) return false;
    while (sum) {
        a[p]++;
        sum--;
        p++;
        if (p > n) p = 1;
    }
    //FOR(t, 1, n+1) pf("%I64d%c", a[t], t == n ? '\n' : ' ');
    //puts("damn");
    FOR(i, 1, n+1)
        if (a[i] != b[i]) return false;
        */
    return true;
}

int main() {
    //srand(time(NULL));
    while (~sf("%d%d", &n, &x)) {
    
    FOR(i, 1, n+1) sf("%I64d", &a[i]);
    //n = 4;
    //x = rand()%n + 1;
    //FOR(i, 1, n+1) a[i] = rand()%20;
    
    //memset(b, 0, sizeof(b));
    //memcpy(b, a, sizeof(a));
    ll mi = *min_element(a+1, a+n+1);
    int p = x;
    while (a[p] != mi) {
        p--;
        if (p <= 0) p = n;
    }
    //cout <<p <<endl;
    if (p <= x) {
        ll t = a[p];
        FOR(j, 1, n+1)
            if (p != j) a[j] -= t;
        a[p] = 1LL * t * n;
        a[p] += x - p;
        FOR(j, p+1, x+1) a[j]--;
        output();
    }
    else if (p > x) {
        ll t = a[p];
        FOR(j, 1, n+1)
            if (p != j) a[j] -= t;
        a[p] = 1LL * t * n;
        FOR(j, p+1, n+1) a[j]--;
        FOR(j, 1, x+1) a[j]--; 
        a[p] += n - p + x;
        output();
        //puts("");
    }
    /*
    if (!check(p)) {
        cout <<n <<" "<<x <<"  :  "<<p <<endl;
        cout <<"b[] is :" <<endl;
        REP(i, n) cout <<b[i+1] <<" ";
        cout <<endl;
        cout <<"*-----------------*" <<endl;
        //getchar();
        for (;;);
    }*/
    }
    return 0;
}
/*
10 3
1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000
*/

