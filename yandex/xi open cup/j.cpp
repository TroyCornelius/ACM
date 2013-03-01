/*
 * Author:  Troy
 * Created Time:  2012/9/13 10:06:37
 * File Name: j.cpp
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
#define Maxn 300100
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, a[Maxn], b[Maxn];
long long sum, owe;
vi ans;
struct Tnode{
    int id;
    Tnode(){}
    Tnode(int _id)
    :id(_id) {}
    bool operator<(const Tnode c) const {
        return b[id] < b[c.id];
    }
};
priority_queue<Tnode> h;

int main() { 
    while (~sf("%d", &n)) {
        FOR(i, 1, n+1) sf("%d", &a[i]);
        FOR(i, 1, n+1) sf("%d", &b[i]);
        while (!h.empty()) h.pop();
        owe = sum = 0;
        FOR(i, 1, n+1) {
            sum += a[i];
            if (owe + b[i] <= sum) {
                h.push(Tnode(i));
                owe += b[i];
            }
            else {
                if (h.empty()) continue;
                int tmp = b[h.top().id];
                //cout <<tmp <<" "<<h.size() <<endl;
                if (tmp <= b[i]) continue;
                else {
                    h.pop();
                    owe -= tmp;
                    h.push(Tnode(i));
                    owe += b[i];
                }
            }
        }
        pf("%d\n", h.size());
        ans.clear();
        while (!h.empty()) {
            ans.pb(h.top().id);
            h.pop();
        }
        sort(all(ans));
        REP(i, ans.size()) pf("%d%c", ans[i], i == ans.size()-1?'\n':' ');
        //puts("");
    }
    return 0;
}

