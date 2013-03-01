/*
 * Author:  Troy
 * Created Time:  2012/11/19 23:56:07
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
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
/*
int n, a[110];
int ans;
inline int find() {
    int ret = -1;
    int mx = 0;
    for (int i = 1; 2 * i + 1 <= n; i++) {
        if (a[i] + a[i+i] + a[i+i+1] > mx) {
            mx = a[i] + a[i+i] + a[i+i+1];
            ret = i;
        }
    }
    return ret;
}
inline bool check() {
    for (int i = 1; i <= n; i++)
        if (a[i] > 0) return false;
    return true;
}
int main() {
    while (cin >>n) {
        for(int i = 1; i <= n; i++) cin >>a[i];
        if (n < 3) cout <<-1 <<endl;
        else {
            ans = 0;
            while (true) {
                int p = find();
                if (p == -1) break;
                ans++;
                if (a[p]) a[p]--;
                if (a[p+p]) a[p+p]--;
                if (a[p+p+1]) a[p+p+1]--;
            }
            if (!check()) cout <<-1 <<endl;
            else cout <<ans <<endl;
        }
    }
    return 0;
}
*/
const int N = 111;
int n;
int a[N];
int main() {
    while(cin >> n) {
        for(int i = 1; i <= n; i++) cin >> a[i];
        if(n < 3 || n % 2 == 0) {
            cout << -1 << endl;
        } else {
            int ans = 0;
            for(int i = n; i >= 3; i -= 2) {
                int tmp = 0;
                tmp = max(a[i], a[i-1]);
                if(tmp == 0) continue;
                ans += tmp;
                a[i/2] = max(0, a[i/2] - tmp);
            } 
            ans += a[1];
            cout << ans << endl;
        }
    }
    return 0;
}

