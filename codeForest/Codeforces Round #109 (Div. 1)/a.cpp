/*
 * Author:  Troy
 * Created Time:  2012/2/24 22:53:21
 * File Name: a.cpp
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
#define Maxn 100010
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
string s, t;
int k, ans;
bool v[Maxn];
int main() 
{
    ios::sync_with_stdio(false);
    cin >>s;
    cin >>k;
    int len = s.length();
    while (k--)
    {
        cin >>t;        
        int s1 = 0, s2 = 0;
        ans = 0;
        REP(i, len - 1)
        {
            if ((s[i]==t[0] && s[i+1]==t[1]) || (s[i]==t[1] && s[i+1]==t[0]))
            {
                if (!v[i])
                {
                    v[i] = true;
                    if (s[i] == t[0]) s1++;
                    else s2++;
                }
                if (!v[i+1])
                {
                    v[i+1] = true;
                    if (s[i+1] == t[0]) s1++;
                    else s2++;
                }
            }
        }
        cout <<s1 <<" "<<s2 <<" " <<t <<endl;
        if (t[0] == t[1]) ans += max(s1, s2);
        else  ans += min(s1, s2);
    }
    cout << ans <<endl;
    return 0;
}

