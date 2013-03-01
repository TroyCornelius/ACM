/*
 * Author:  Troy
 * Created Time:  2013/2/11 23:34:25
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
bool check(int y) {
    bool visit[10];
    memset(visit, false, sizeof(visit));
    while (y) {
        visit[y % 10] = true;
        y /= 10;
    }
    int cnt = 0;
    for (int i = 0; i < 10; i++) {
        if (visit[i]) cnt++;
    }
    return cnt == 4;
}
int main() {
    int y;
    cin >>y;
    while (1) {
        y++;
        if (check(y)) {
            cout << y << endl;
            break;
        }
    }
    return 0;
}

