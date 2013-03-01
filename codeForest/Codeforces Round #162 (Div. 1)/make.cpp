/*
 * Author:  Troy
 * Created Time:  2013/1/20 22:32:32
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

int main() {
    freopen("c.in", "w" , stdout);
    srand(time(NULL));
    int n = rand()%100000+1, q = 100;
    cout <<n <<" "<<q <<endl;
    int num;
    REP(i, n) {
        num = rand()%200000-100000;
        cout <<num <<" ";
    }
    cout <<endl;
    REP(i, n) {
        num = rand()%n+1;
        cout <<num <<" ";
    }
    cout <<endl;
    
    while (q--) {
        int a = rand()%200000-100000;
        int b = rand()%200000-100000;
        cout <<a <<" "<<b <<endl;
    }
    return 0;
}

