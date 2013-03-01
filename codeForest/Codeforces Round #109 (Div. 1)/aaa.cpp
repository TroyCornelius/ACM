/*
 * Author:  Troy
 * Created Time:  2012/2/28 20:16:17
 * File Name: aaa.cpp
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
string s;
int k, ans;
int f[256];
int main() 
{
    memset(f, 0, sizeof(f));
    string st[15];
    cin >>s;
    cin >>k;
    REP(i, k)
    {
        cin >>st[i];
        f[st[i][0]] = i+1;
        f[st[i][1]] = i+1;
    }
    ans = 0;
    int len = s.length();
    int i = 0, j = 0;
    while (i < len - 1)
    {
        if (f[s[i]] == 0 || f[s[i]] != f[s[i+1]]) {i++; continue;}
        int c1 = 0, c2 = 0;
        if (s[i] == st[f[s[i+1]]-1][0]) c1++;
        else c2++;
        while (i < len-1 && f[s[i]] == f[s[i+1]])
        {
            if (s[i+1] == st[f[s[i+1]]-1][0]) c1++;
            else c2++;
            i++;
        }
        ans += min(c1, c2);
    }
    cout <<ans <<endl;
    return 0;
}

