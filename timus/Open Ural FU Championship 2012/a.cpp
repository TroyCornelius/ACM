/*
 * Author:  Troy
 * Created Time:  2012/11/10 15:43:33
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

int n;
int main() {
    int val;
    while (~sf("%d", &n)) {
        int ans = 0, cnt = 0, cur, id = 1, ans_id = 1;
        sf("%d", &cur);
        for (int i = 2; i <= n; i++) {
            sf("%d", &val);
            cnt++;
            if (val > cur) {
                if (ans < cnt) ans = cnt, ans_id = id; 
            }
            else {
                cnt = 0;
                id = i;
            }
        }
        pf("%d\n", ans_id);
    }
    return 0;
}

