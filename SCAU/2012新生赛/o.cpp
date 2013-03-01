/*
 * Author:  Troy
 * Created Time:  2012/11/30 17:11:47
 * File Name: o.cpp
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

int T, n;
long long z;
long long calc(long long x) {
    if (n == 1) return z - x;
    else {
        long long tmp = 1LL*z*z - x*x;
        long long ret = (long long)sqrt(1.0*tmp);
        if (ret * ret == tmp) return ret;
        else return -1;
    }
}
int main() 
{
    cin >>T;
    while (T--) {
        cin >>z >>n;
        if (n > 2) cout <<"No Solution" <<endl;
        else {
            int tot = 0;
            for (int i = 1; i < z; i++) {
                long long y = calc(i);
                if (y != -1) {
                    cout <<i <<" "<<y <<endl;
                    tot++;
                    if (tot >= 10) break;
                }
            }
            if (tot == 0) cout <<"No Solution" <<endl;
        }
        if (T) cout <<endl;
    }
    return 0;
}

