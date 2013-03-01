/*
 * Author:  Troy
 * Created Time:  2012/2/17 14:28:31
 * File Name: 3461.cpp
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

int ans;
void sunday(string &s1, string &s2) //s1 在 s2中出现的次数和位置
{
    int shift[256];
    int len1 = s1.length(), len2 = s2.length();
    REP(i, 256) shift[i] = len1 + 1;
    REP(i, len1) shift[s1[i]] = len1 - i;
    int lim = len2 - len1 + 1;
    for (int i = 0; i < lim; i += shift[s2[i+len1]])
    if (s2[i] == s1[0])
    {
        int j = i + 1, match_len = 1;
        do
        {
            if (match_len == len1) {ans++;break;} // cout <<"the match loction is "<<i <<endl;
        }while (s2[j++] == s1[match_len++]);        
    }
}
int main() 
{
    string s1, s2;
    ios::sync_with_stdio(false);
    int T;
    cin >>T;
    while (T--)
    {
        cin >>s1;
        cin >>s2;
        ans = 0;
        sunday(s1, s2);
        cout <<ans << endl;
    }
    return 0;
}

