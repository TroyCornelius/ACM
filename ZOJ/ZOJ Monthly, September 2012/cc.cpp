/*
 * Author:  Troy
 * Created Time:  2012/9/29 13:08:36
 * File Name: cc.cpp
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
#define maxn 350

using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
int n;
char board[maxn][maxn];
int row[maxn], column[maxn];
int main() {
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; i++) scanf("%s", board[i]);
        memset(row, 0, sizeof(row));
        memset(column, 0, sizeof(column));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'U') row[i] = column[j] = 1;
            }
        }
        int rowSum = 0, columnSum = 0;
        for(int i = 0; i < n; i++) {
            rowSum += row[i];
            columnSum += column[i];
        }
        if(rowSum == n && columnSum == n) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}

