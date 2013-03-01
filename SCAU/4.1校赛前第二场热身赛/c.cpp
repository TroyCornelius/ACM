/*
 * Author:  Troy
 * Created Time:  2012/4/1 18:31:04
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

#include <cctype>
#include <functional>

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

string s, ans;
int main() 
{
    string s1, s2;
    int T;
    cin >>T;
    while (T--)
    {
        cin >>s;
        ans.clear();
        int st = (s[0] == '-'?1:0);
        for (int i=s.length()-1; i>=0; i--)
        if (s[i] != '0')
        {
            s1 = s.substr(st, i - st+1);
            if (i + 1 < s.length()) s2 = s.substr(i+1);
            else s2 = "";
            break;
        }
        reverse(all(s1));
        ans = (s[0] == '-' ? "-" : "") + s1 + s2;
        if (s == "0" || s == "-0") ans = s;
        cout <<ans <<endl;
    }
    return 0;
}

