/*
 * Author:  Troy
 * Created Time:  2012/4/14 23:43:30
 * File Name: k.cpp
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


string s1, s2;
long long cnt[256][2];
long long ans, t1, t2;

void calc(string &s, int p)
{
    REP(i, s.length())
        if (s[i] != '?')
        {
            if (isupper(s[i])) cnt[s[i]-'A'][p]++;
            else cnt[s[i]-'a'+26][p]++;
        }
        else
        {
            if (p == 0) t1++;
            else t2++;
        }
}
int main() 
{
    ios::sync_with_stdio(false);
    int T, ca = 0;
    cin >>T;
    getline(cin, s1);
    while (T--)
    {
        getline(cin, s1);
        getline(cin, s2);
        if (s1.length() > s2.length()) swap(s1, s2);
        memset(cnt, 0, sizeof(cnt));
        t1 = t2 = 0;
        ans = 0;
        calc(s1, 0);
        calc(s2, 1);
        int len1 = s1.length(), len2 = s2.length();
        REP(i, 56)
            ans += cnt[i][0] * (len2 - cnt[i][1] - t2);
        
        //cerr <<ans <<endl;
        long long mi = 1LL << 60, tmp;
        REP(i, 56)
            REP(j, 56)
            {
                if (i == j)
                {
                    tmp = t1 * (len2 - cnt[i][1] - t2) + (len1 - cnt[j][0] - t1) * t2;
                }
                else
                {
                    tmp = t1 * (len2 - cnt[i][1]) + (len1 - cnt[j][0] - t1) * t2;
                }
                if (tmp < mi) mi = tmp;
                //cout <<i <<" "<<j <<" "<<tmp <<" "<<mi <<endl;
                //getchar();
            }
        ans += mi;
        cout <<"Case #" <<++ca <<": " <<ans <<endl;
    }
    return 0;
}

