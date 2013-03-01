/*
 * Author:  Troy
 * Created Time:  2012/11/25 12:19:34
 * File Name: g.cpp
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
#define number first
#define suit second
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
typedef pair<int, char> mj;
typedef vector<mj> vmj;

string s;
vector<mj> hands, ans;
map<mj, int> cnt;
void split() {
    for (int i = 0; i < s.size(); i += 2) {
        int num = s[i] - '0';
        char ch = s[i+1];
        hands.pb(mp(num, ch));
        cnt[mp(num, ch)] += 1;
    }
}

bool cmp(const mj &a, const mj &b) {
    if (a.suit != b.suit) return a.suit < b.suit;
    else return a.number < b.number;
}
bool vis[15];
inline int find(vmj &h, mj x) {
    REP(i, h.size())
        if (!vis[i]) {
            if (h[i] == x || x.fi == -1) return i;
        }
    return -1;
}
bool dfs(vmj &h, int tot, bool haseyes) {
    if (tot >= 14) return haseyes;
    if (!haseyes) {
        int i = find(h, mp(-1, 'a'));
        vis[i] = true;
        int j = find(h, h[i]);
        if (j != -1) {
            vis[j] = true;
            if (dfs(h, tot+2, true)) return true;
            vis[j] = false;
        }
        vis[i] = false;
    }    
    if (tot + 3 <= 14) {
        int i = find(h, mp(-1, 'a'));
        vis[i] = true;
        int j = find(h, h[i]);
        if (j != -1) {
            vis[j] = true;
            int k = find(h, h[i]);
            if (k != -1) {
                vis[k] = true;
                if (dfs(h, tot+3, haseyes)) return true;
                vis[k] = false;
            }
            vis[j] = false;
        }
        
        if (h[i].suit != 'z') {
            j = find(h, mp(h[i].number+1, h[i].suit));
            if (j != -1) {
                vis[j] = true;
                int k = find(h, mp(h[j].number+1, h[i].suit));
                if (k != -1) {
                    vis[k] = true;
                    if (dfs(h, tot+3, haseyes)) return true;
                    vis[k] = false;
                }
                vis[j] = false;
            }
        }
        vis[i] = false;
    }
    return false;
}
bool check(vmj h) {
    //REP(i, h.size()) cout <<h[i].number <<h[i].suit<<" "; 
    //cout <<endl;
    //cout <<dfs(h, 0, false) <<" ..." <<endl;
    memset(vis, false, sizeof(vis));
    return dfs(h, 0, false);
}
void solve() {
    hands.clear();
    ans.clear();
    cnt.clear();
    split();
    //for p
    for (int i = 1; i <= 9; i++) {
        vmj tmp = hands;
        if (cnt[mp(i, 'p')] >= 4) continue;
        tmp.pb(mp(i, 'p'));
        sort(all(tmp), cmp);
        if (check(tmp)) ans.pb(mp(i, 'p'));
    }
    //for s
    for (int i = 1; i <= 9; i++) {
        vmj tmp = hands;
        if (cnt[mp(i, 's')] >= 4) continue;
        tmp.pb(mp(i, 's'));
        sort(all(tmp), cmp);
        if (check(tmp)) ans.pb(mp(i, 's'));
    }
    //for m
    for (int i = 1; i <= 9; i++) {
        vmj tmp = hands;
        if (cnt[mp(i, 'm')] >= 4) continue;
        tmp.pb(mp(i, 'm'));
        sort(all(tmp), cmp);
        if (check(tmp)) ans.pb(mp(i, 'm'));
    }
    // for z
    for (int i = 1; i <= 7; i++) {
        vmj tmp = hands;
        if (cnt[mp(i, 'z')] >= 4) continue;
        tmp.pb(mp(i, 'z'));
        sort(all(tmp), cmp);
        if (check(tmp)) ans.pb(mp(i, 'z'));
    }
}
void print() {
    sort(all(ans), cmp);
    cout <<ans.size();
    if (ans.size() != 0) cout <<" ";
    REP(i, ans.size()) cout <<ans[i].number<<ans[i].suit;
    cout <<endl;
}
int main() {
    while (cin >>s) {
        solve();
        print();
    }
    return 0;
}

