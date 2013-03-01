/*
 * Author:  Troy
 * Created Time:  2012/11/21 0:35:54
 * File Name: LASTDIG.cpp
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

int D(int x) {
    int ret = 0;
    while (x) {
        int dig = x % 10;
        if (dig & 1) ret += dig;
        else ret += 2 * dig;
        x /= 10;
    }
    return ret % 10;
}
int main() {
    int a, b;
    while (cin >>a >>b) {
        int sum = 0;
        for (int i = a; i <= b; i++) {
            cout <<i <<" : "<<D(i) <<endl;
            sum += D(i);
        }
        cout <<sum <<endl;
    }
    return 0;
}

