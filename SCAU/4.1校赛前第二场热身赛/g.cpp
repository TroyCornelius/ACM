/*
 * Author:  Troy
 * Created Time:  2012/4/1 19:53:52
 * File Name: g.cpp
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

string s, up, down;
int main() 
{
    int T, tot;
    cin >>T;
    while (T--)
    {
        cin >>s;
        cin >>up;
        cin >>down;
        tot = 0;
        for (int i = 0; i < up.length() && tot < s.length(); i++)
            if (s[tot] == up[i] || s[tot] == down[i] || up[i] == '*' || down[i]=='*') tot++;
        if (tot == s.length()) cout <<"win" <<endl;
        else cout <<"lose" <<endl;
    }
    
    
    return 0;
}

