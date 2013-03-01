/*
 * Author:  Troy
 * Created Time:  2012/11/21 23:30:19
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
int n, k, a[55];
vector<vi> ans;
map<int,int> vis;
vi sch;
void dfs(int sum, int s) {
    if (ans.size() >= k) return;
    if (vis.find(sum) != vis.end()) return;
    if (sch.size() != 0 && vis.find(sum) == vis.end()) {
        ans.pb(sch);
        vis[sum] = 1;
    }
    if (s >= n ) return;
    sch.pb(a[s]);
    dfs(sum + a[s], s+1);
    sch.pop_back();
    dfs(sum, s+1);
    return;
}
int main() {
    cin >>n >>k;
    REP(i, n) cin >>a[i];
    //vis.clear();
    //sch.clear();
    //sort(a, a+n);
    //dfs(0, 0);
       REP(i, n+1)
       REP(j, n+1)
       REP(x, n+1)
       REP(y, n+1) {
       int sum = a[i] + a[j] + a[x] + a[y];
       if (vis.find(sum) == vis.end()) {
                        vis[sum] = 1;
                        vi tmp;
                        if (i != n) tmp.pb(a[i]);
                        if (j != n) tmp.pb(a[j]);
                        if (x != n) tmp.pb(a[x]);
                        if (y != n) tmp.pb(a[y]);
                        ans.pb(tmp);
                    }
                    
                }
    REP(i, n)
        for (int j = i+1; j < n; j++) {
            int sum = a[i] + a[j];
            if (vis[sum] == vis.end()) {
                vis[sum] = 1;
                vi tmp;
                tmp.pb(a[i]);
                tmp.pb(a[j]);
                ans.pb(tmp);
            }
        }
    REP(i, k) {
        cout <<ans[i].size();
        REP(j, ans[i].size()) cout <<" " <<ans[i][j];
        cout <<endl;
    }
    
    return 0;
}
*/
int a[55];
int n, k;
int main() {
    while(cin >> n >> k) {
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        int index = n - 1;
        vector<int> vec;
        while(1) {
            for(int i = index; i >= 0; i--) {
                cout << vec.size() + 1 << " ";
                for(int j = 0; j < vec.size(); j++) cout << vec[j] << " ";
                cout << a[i] << endl;
                if(--k == 0) break;
            }
            if(k == 0) break;
            vec.pb(a[index]);
            index--;
        }
    }
    return 0;
}

