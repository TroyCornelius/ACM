/*
 * Author:  Troy
 * Created Time:  2012/9/29 12:41:55
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
#define sf scanf
#define pf printf
#define ll int
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int a[250][250], b[250][250];
ll solve(int n) { //n½×ÐÐÁÐÊ½£¬mod = m{
    bool flag = 0;
	ll ret = 1;
	REP(i, n)
		REP(j, n)
		b[i][j] = a[i][j];
	REP(i, n)
	{
        ll mx = b[i][i];
        int pp = i;
        FOR(j, i+1, n)            
           if (b[j][i] > mx) mx = b[j][i], pp = j;
        if (pp != i) {
            FOR(k, i, n) 
                swap(b[i][k], b[pp][k]);
            flag ^= 1;
        }
        //ret = (ret * b[i][i] % m + m) % m;
        ret *= b[i][i];
        //ll tmp = get_ni(b[i][i], m);
        int tmp = b[i][i];
        if (tmp == 0) return 0;
        FOR(k, i+1, n) b[i][k] = b[i][k] / tmp;
        FOR(j, i+1, n)
            FOR(k, i+1, n)
            {
                b[j][k] -= b[j][i] * b[i][k] ;
                //b[j][k] = (b[j][k] % m + m) % m;
            }
    }
    //if (flag) ret = -ret;
    return ret;
}
int n;
char board[250][250];
int main() {
     while(~scanf("%d", &n)) {
        for(int i = 0; i < n; i++) scanf("%s", board[i]);
        //memset(row, 0, sizeof(row));
        //memset(column, 0, sizeof(column));
        memset(a, 0, sizeof(a));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                //if(board[i][j] == 'U') row[i] = column[j] = 1;
                if (board[i][j] == 'U') a[i][j] = 1;
            }
        }
        //int rowSum = 0, columnSum = 0;
        //for(int i = 0; i < n; i++) {
            //rowSum += row[i];
            //columnSum += column[i];
        //}
        int ans = solve(n);
        //cout <<ans <<endl;
        if(ans) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
//}
    return 0;
}

