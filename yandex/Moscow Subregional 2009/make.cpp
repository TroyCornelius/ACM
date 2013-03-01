/*
 * Author:  Troy
 * Created Time:  2012/10/3 22:55:21
 * File Name: make.cpp
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

int n, m, b, c, d;
int main() {
    freopen("d.in", "w", stdout);
    srand(time(NULL));
    int T = 10;
    while (T--) {
        n = rand()%10 + 1; m = rand()%10 + 1;
        b = rand()%m + 1; c = rand()%n + 1;
        d = rand()%m + 1;
        if (b == d && c == 1) continue;
        cout <<n <<" "<<m <<" "<<b <<" "<<c <<" "<<d <<endl;
        int num = rand()%5;
        if (num == 0) cout <<"T" <<endl;
        else if (num == 1) cout <<"F" <<endl;
        else if (num == 2) cout <<"B" <<endl;
        else if (num == 3) cout <<"L" <<endl;
        else if (num == 4) cout <<"R" <<endl;
    }
    return 0;
}

