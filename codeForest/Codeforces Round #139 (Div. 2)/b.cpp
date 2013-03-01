/*
 * Author:  Troy
 * Created Time:  2012/9/20 0:03:56
 * File Name: b.cpp
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

long long s, k;
long long f[100], sum[100];
int main() {
    cin >>s >>k;
    sum[0] = 0;
    sum[1] = sum[2] = 1;
    //for (int i = 3; i <= 80; i++) f[i] = f[i-1] + f[i-2];   
    
    for (int i = 2; i <= 80; i++) {
        //if (f[i] > 1000000000LL) break;
        sum[i] = 0;
        for (int j = i, t = 1; j - t >= 1 && t <= k; t++) {
            sum[i] += sum[j-t];
            if (sum[i] > 1000000000) break;
        }
    }
    //for (int i = 1; i <= 10; i++) cout <<sum[i] <<" ";
    //cout <<endl;
    //cout <<f[80] <<endl;
    vector<long long> ans;
    int i;
    while (s) {
        for (i = 1; i <= 80; i++) {
            if (sum[i] > s) break;            
        }
        s -= sum[i-1];
        ans.pb(sum[i-1]);
    }
    if (ans.size() == 1) ans.pb(0);
    cout <<ans.size() <<endl;
    REP(i, ans.size()) {
        cout <<ans[i];
        if (i == ans.size() - 1) cout <<endl;
        else cout <<" ";
    }
    
    return 0;
}

