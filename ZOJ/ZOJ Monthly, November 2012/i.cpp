/*
 * Author:  Troy
 * Created Time:  2012/11/25 14:17:20
 * File Name: i.cpp
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

int n, m;
struct Words{
    string w;
    vector<string> tips;
}d[110];
map<string, int> pos;
vector<string> ans;
vi loc;

bool check(string s) {
    for (int i = 1; i < loc.size(); i++) {
        bool flag = false;
        REP(j, d[loc[i]].tips.size())
            if (d[loc[i]].tips[j] == s) {
                flag = true;
                break;
            }
        if (!flag) return false;
    }
    return true;
}
void solve() {
    ans.clear();
    loc.clear();
    string str, line;
    getline(cin, line);
    istringstream stream(line);
    vector<string> q;
    while(stream >>str) q.pb(str);
    REP(i, q.size()) loc.pb(pos[q[i]]);
    
    //REP(i, q.size()) cout <<q[i] <<" ";
    //cout <<endl;
    
    int cur = loc[0];
    REP(i, d[cur].tips.size()) {
        str = d[cur].tips[i];
        if (check(str)) ans.pb(str);
    }
    //cout <<ans.size() <<"---------------" <<endl;
    if (ans.size() == 0) cout <<"NO" <<endl;
    else {
        sort(all(ans));
        REP(i, ans.size()) {
            cout <<ans[i];
            if (i == ans.size() - 1) cout <<endl;
            else cout <<" ";
        }
    }
}
int main() {
    while (cin >>n) {
        pos.clear();
        string str, line;
        REP(i, n) {
            d[i].tips.clear();
            cin >>d[i].w;
            pos[d[i].w] = i;
            getline(cin, str);
            getline(cin, line);
            istringstream stream(line);
            while (stream >>str) d[i].tips.pb(str);
        }
        cin >>m;
        getline(cin, str);
        while (m--) {
            solve();
        }
        
    }
    return 0;
}

