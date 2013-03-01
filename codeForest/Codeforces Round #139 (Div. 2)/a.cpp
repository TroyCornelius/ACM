/*
 * Author:  Troy
 * Created Time:  2012/9/19 23:45:10
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
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int x, a, b, n;
bool num[8];
int main() {
    cin >>n;
    cin >>x;
    cin >>a >>b;
    bool ans = true;
    x = 7 - x;
    REP(i, n-1) {
        cin >>a >>b;
        memset(num, false, sizeof(num));
        num[a] = num[7-a] = num[b] = num[7-b] = true;
        int t = -1;
        for (int i = 1; i <= 6; i++)
            if (i != x && !num[i]) {
                if (t != -1) ans = false;
                t = i;
                //break;
            }
        if (t == -1) ans = false;
        x = 7 - t;
    }
    if (ans) puts("YES");
    else puts("NO");
    return 0;
}

