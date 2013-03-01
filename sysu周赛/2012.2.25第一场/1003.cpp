/*
 * Author:  Troy
 * Created Time:  2012/2/25 19:07:08
 * File Name: 1003.cpp
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
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
const int num[]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
string s;
int a[100];
bool check(int len)
{
    int le = 0, ri = len - 1;
    while (le <= ri)
    {
        if (a[le] != a[ri]) return false;
        le++; ri--;
    }
    return true;
}
int main() 
{
    ios::sync_with_stdio(false);
    int T;
    cin >>T;
    while (T--)
    {
        cin >>s;
        REP(i, s.length())
            a[i] = num[tolower(s[i])-'a'];
        if (check(s.length())) cout <<"YES" <<endl;
        else cout <<"NO" <<endl;
        
    }
    
    return 0;
}
