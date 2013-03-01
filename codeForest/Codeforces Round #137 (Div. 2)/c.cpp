/*
 * Author:  Troy
 * Created Time:  2012/9/10 23:44:14
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
#include <cctype>
#include <functional>

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
#define Maxn 10000000
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, m;

int tot, pri[665579];
int cnt[Maxn+10], lim;
int ans1[100010], ans2[100010], n1, m1;
bool b[Maxn+10];

void get_pri() {
    memset(b, true, sizeof(b));
    tot = 0;
    for (int i = 2; i <= 3200; ++i) {
        if (b[i]) {
            pri[tot++] = i;
            for (int j = i + i; j <= 3200; j += i) b[j] = false;
        }
    }
}
void calc(int x, int val) {
    int sum;
    REP(i, tot)
        if (x % pri[i] == 0) {
            sum = 0;
            while (x % pri[i] == 0) {
                x /= pri[i];
                sum++;
            }
            cnt[pri[i]] += val * sum;
            //if (pri[i] > lim) lim = pri[i];
            //cout <<x <<" "<<val <<" "<<cnt[pri[i]] <<" "<<sum <<endl;
            if (x == 1) break;
        }
    cout <<x <<endl;
    if (x != 1) cnt[x] += val;
    //if (x > lim) lim = x;
    return;
}
int main() 
{
    memset(cnt, 0, sizeof(cnt));
    get_pri();
    cout <<tot <<endl;
    sf("%d%d", &n, &m);
    int x;
    //lim = 2;
    REP(i, n) {
        sf("%d", &x);
        calc(x, 1);
    }
    REP(i, m) {
        sf("%d", &x);
        calc(x, -1);
    }
    n1 = m1 = 0;
    int s1 = 1, s2 = 1;
    
    //for (int i = 1; i <= 20; ++i) cout <<cnt[i] <<" ";
    //cout <<endl;
    
    //lim = Maxn;
    for (int i = Maxn; i >= 2; i--) {
        if (cnt[i] > 0) {
            while (cnt[i] > 0) {
                if (1LL* s1 * i <= Maxn) {
                    s1 *= i;
                    cnt[i]--;
                }
                else {
                    ans1[n1++] = s1;
                    s1 = 1;
                }
            }
        }
        else if (cnt[i] < 0) {
            while (cnt[i] < 0) {
                if (1LL* s2 * i <= Maxn) {
                    s2 *= i;
                    cnt[i]++;
                }
                else {
                    ans2[m1++] = s2;
                    s2 = 1;
                }
            }
        }
    }
    
    if (n1 < 100000) ans1[n1++] = s1;
    if (m1 < 100000) ans2[m1++] = s2;
    
    pf("%d %d\n", n1, m1);
    for (int i = 0; i < n1; ++i) pf("%d%c", ans1[i], i == n1-1 ? '\n' : ' ');
    for (int i = 0; i < m1; ++i) pf("%d%c", ans2[i], i == m1-1 ? '\n' : ' ');
    
    return 0;
}
/*
5 3
9933881 9933881 9933881 49919 49919
2 2 2
*/
