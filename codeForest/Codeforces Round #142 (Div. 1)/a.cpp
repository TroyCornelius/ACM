/*
 * Author:  Troy
 * Created Time:  2012/10/1 23:32:59
 * File Name: a.cpp
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
using namespace std;
const int inf = 1<<25;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, m;
char s[110][10100];
int cnt_move[110][11024];
int main() {
    sf("%d%d", &n, &m);
    REP(i, n) sf("%s", s[i]);
    REP(i, n+1)
        REP(j, m+1)
            cnt_move[i][j] = inf;
    
    int p = -1;
    REP(i, n) {
        p = -1;
        int tmp = 0;
        for (int j = m-1; j >= 0 && s[i][j] == '0'; j--) tmp++;
        if (tmp == m) tmp = inf;
        REP(j, m) {
            if (s[i][j] == '1') p = j;
            if (p == -1 && tmp != inf) cnt_move[i][j] = tmp + j + 1;
            else if (p != -1) cnt_move[i][j] = j - p;
        }
        //REP(j, m) cout <<cnt_move[i][j] <<" ";
        //cout <<endl;
        tmp = 0;
        p = -1;
        for (int j = 0; j < m && s[i][j] == '0'; j++) tmp++;
        if (tmp == m) tmp = inf;
        for (int j = m-1; j >= 0; j--) {
            if (s[i][j] == '1') p = j;
            if (p == -1 && tmp != inf) cnt_move[i][j] = min(cnt_move[i][j], tmp + m - j);
            else if (p != -1) cnt_move[i][j] = min(cnt_move[i][j], p - j);
        }
        //REP(j, m) cout <<cnt_move[i][j] <<" ";
        //cout <<endl;
    }
    int ans = inf;
    REP(i, m) {
        int sum = 0;
        REP(j, n) 
            if (cnt_move[j][i] != inf) sum += cnt_move[j][i];
            else {
                sum = inf;
                break;
            }
        if (sum < ans) ans = sum;
    }
    if (ans >= inf) puts("-1");
    else pf("%d\n", ans);
    return 0;
}

