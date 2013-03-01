/*
 * Author:  Troy
 * Created Time:  2012/3/25 23:16:46
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
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

string a, s;
int cnt[10];
int main() 
{
    cin >>a;
    cin >>s;
    memset(cnt, 0, sizeof(cnt));
    REP(i, s.length()) cnt[s[i]-'0']++;
    int num = 9, loc = 0;
    while (num > 0 && loc < a.length())
    {
        while (num > 0 && cnt[num] == 0) num--;
        while (loc<a.length() && a[loc] - '0' >= num) loc++;
        if (num > 0 && loc < a.length())
        {
            a[loc] = char('0' + num);
            cnt[num]--;
        }
    }
    cout <<a <<endl;
    return 0;
}

