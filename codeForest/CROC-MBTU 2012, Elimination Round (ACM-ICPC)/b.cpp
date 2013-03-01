/*
 * Author:  Troy
 * Created Time:  2012/11/19 23:42:28
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
string s;
int main() {
    string ans;
    while (cin >>s) {
       ans.clear();
       if (s[0] == 'h') {
            ans = s.substr(0, 4);
            s.erase(0, 4);
       } 
       else if (s[0] == 'f') {
            ans = s.substr(0, 3);
            s.erase(0, 3);
       }
       ans = ans + "://";
       int loc = s.find("ru", 0);
       if (loc == 0) loc = s.find("ru", 1);
       
       ans = ans + s.substr(0, loc);
       s.erase(0, loc+2);
       ans = ans + ".ru";
       if (s != "") ans += "/" + s;
       cout <<ans <<endl;
       
    }
    return 0;
}

