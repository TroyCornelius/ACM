/*
 * Author:  Troy
 * Created Time:  2013/2/20 23:46:47
 * File Name: d.cpp
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
#define Maxn 110100
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, m;
vi d[Maxn];
bool ans;
//int p[Maxn];
struct Tnode {
    int idx;
}p[Maxn];
bool cmp(const Tnode x, const Tnode y) {
    int ret = 0;
    int a = x.idx, b = y.idx;
    REP(i, n) {
        if (d[i][a] != -1 && d[i][b] != -1) {
            if (ret == 0) {
                ret = d[i][a] > d[i][b] ? -1 : 1;
            }
            else {
                if (d[i][a] > d[i][b] && ret == 1) {
                    ans = false;
                }
                else if (d[i][a] < d[i][b] && ret == -1) {
                    ans = false;
                }
            }
        }
    }
    //cout <<" ----------- " <<ret <<" "<<ans <<endl;
    if (!ans) {
        cout <<"-1" <<endl;
        exit(0);
    }
    if (ret <= 0) return false;
    else return true;
}
int main() {
    //freopen("d.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin >>n >>m;
    int num;
    REP(i, n) {
        d[i].clear();
        REP(j, m) {
           cin >>num; 
           d[i].pb(num);
        }
    }
    REP(i, m) p[i].idx = i;
    ans = true;
    sort(p, p+m, cmp);
    if (!ans) cout <<"-1" <<endl;
    else {
        REP(i, m) {
            cout <<p[i].idx+1;
            if (i == m-1) cout <<endl;
            else cout <<" ";
        }
    }
    return 0;
}

