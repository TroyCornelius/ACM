/*
 * Author:  Troy
 * Created Time:  2012/9/20 1:16:40
 * File Name: e.cpp
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
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
const int mod = 1000000007;

long long t;

bool check(long long n) {
    //for (int x = 1; x < n; x++) 
        //for (int y = x; x*y<n; y++)
            //if (x/2+y+x*y == n) return false;    
    //return true;
    n-=2;
    long long lo = 1, hi = n, mid;
    long long x, y;
    while (lo <= hi) {
        mid = (lo + hi) >>1;
        x = 2 * mid;
        if ()
    }
}
int main() {
    
    int cnt = 0;
    //for (t = 16; t <= 1000000; t++) {
    for (int i = 19; i <= 63; i++){
        t = (1LL<<i)-1;
        //cout <<t <<endl;
        if (check(t)) {
            cnt++;
            cout <<cnt <<" :"<<t%mod <<" "<<i <<endl;
        }
    }
    cout <<"fuck" <<endl;
    
    
    return 0;
}

