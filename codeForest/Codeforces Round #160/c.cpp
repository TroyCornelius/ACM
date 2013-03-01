/*
 * Author:  Troy
 * Created Time:  2013/1/14 0:16:22
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

int n, m;
int a[150][150];
vi vec;
void init() {
    cout <<m <<" ******************* " <<endl;
    for (int j = 1; j <= m; j++) a[1][j] = 0;
    a[1][m+1] = 1;
    for (int i = 2; i <= m+1; i++) {
        int ss = 0;
        for (int j = 1; j <= m+1; j++) {
            if (j == 1) a[i][j] = a[i-1][j+1];
            else {
                if (j == m+1) a[i][j] = a[i-1][j-1];
                else a[i][j] = a[i-1][j-1]^a[i-1][j+1];
            }
            ss += a[i][j];
        }
        cout <<i <<" "<<ss <<endl;
    }
    int sum = 0;
    for (int j = 1; j <= m+1; j++)  {
        sum += a[m+1][j];
    }
    //cout <<" : " <<sum <<endl;
    vec.pb(sum);
}
int main() 
{
    while (cin >>n) {
        for (m = 1; m <= n; m++)
            init();
        REP(i, vec.size()) cout <<i+1 <<" = " <<vec[i] <<endl;
        puts("");
        REP(i, n+1) {
            REP(j, n+1) cout <<a[i][j] <<" ";
            cout <<endl;
        }
    }
    return 0;
}

