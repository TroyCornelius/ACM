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
void split() {
    for (int i = 0; i < s.size(); i += 2) {
        int num = s[i] - '0';
        char ch = s[i+1];
        hands.pb(mp(num, ch));
    }
}

bool cmp(const mj &a, const mj &b) {
    if (a.suit != b.suit) return a.suit < b.suit;
    else return a.number < b.number;
}
map<pair<mj,mj>, int> vis;
bool seven_pairs_chk() {
    vis.clear();
    for (int i = 0; i < hands.size(); i += 2) {
        if (hands[i] == hands[i+1]) {
            pair<mj, mj> tmp = mp(hands[i], hands[i+1]);
            if (vis.find(tmp) == vis.end()) {
                vis[tmp] = 1;
            }
            else return false;
        }
        else return false;
    }
    return true;
}
bool used[15];
inline int find( mj x) {
    REP(i, hands.size())
        if (!used[i] && hands[i] == x) return i;
    return -1;
}
bool thirteen_orphans_chk() {
    memset(used, false, sizeof(used));
    int pos = find(mp(1, 'm'));
    if (pos == -1) return false;
    used[pos] = true;
    pos = find(mp(1, 's'));
    if (pos == -1) return false;
    used[pos] = true;
    pos = find(mp(1, 'p'));
    if (pos == -1) return false;
    used[pos] = true;
    pos = find(mp(9, 's'));
    if (pos == -1) return false;
    used[pos] = true;
    pos = find(mp(9, 'm'));
    if (pos == -1) return false;
    used[pos] = true;
    pos = find(mp(9, 'p'));
    if (pos == -1) return false;
    used[pos] = true;
    
    for (int i = 1; i <= 7; i++) {
        pos = find(mp(i, 'z'));
        if (pos == -1) return false;
        used[pos] = true;
    }
    REP(i, hands.size())
        if (!used[i]) {
            for (int j = 0; j < hands.size(); j++)
                if (used[j] && hands[i] == hands[j]) return true;
        }
    return false;
}
void solve() {
    hands.clear();
    split();
    sort(all(hands), cmp);
    if (seven_pairs_chk()) {
        cout <<"Seven Pairs" <<endl;
    }
    else if (thirteen_orphans_chk()) {
        cout <<"Thirteen Orphans" <<endl;
    }
    else cout <<"Neither!" <<endl;
}
int main() {
    while (cin >>s) {
        solve();
    }
    return 0;
}


