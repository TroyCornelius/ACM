/*
 * Author:  Troy
 * Created Time:  2012/12/9 18:41:02
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

string s, t;
int c1[300], c2[300];
set<int> p[30];
int main() {
    cin >>s;
    cin >>t;
    REP(i, s.size()) c1[s[i]]++;
    REP(i, t.size()) c2[t[i]]++;
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        if (c1[ch] > c2[ch]) {
            int tmp = c1[ch] - c2[ch];
            REP(i, s.size()) {
                if (c1[s[i]] < c2[s[i]] && )
            }
        }
    }
    cout <<s <<endl;
    return 0;
}

