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
int next[Maxn];
bool check(int x1, int x2)
{
    return (s[x1]==t[0] && s[x2]==t[1]) || (s[x2]==t[0] && s[x1]==t[1]);
}
int main() 
{
    ios::sync_with_stdio(false);
    cin >>s;
    cin >>k;
    int len = s.length();
    REP(i, len+1) next[i] = i+1;
    ans = 0;
    while (k--)
    {
        cin >>t;        
        int s1 = 0, s2 = 0;
        int i = 0;
        while (i < len-1)
        {
            while (1){
            if ((s[i]==t[0] && s[next[i]] == t[1]) || (s[next[i]]==t[0] && s[i] == t[1]))
            {
                int p1 = next[i];
                int p2 = next[next[i]];
                if (p2 < len) 
                {
                    if (check(p1, p2)) 
                    {
                        next[i] = p2;
                        ans++;
                        continue;
                    }
                    else
                    {
                        next[i] = p2;
                        ans++;
                        break;
                    }
                }
                else
                {
                    next[i] = next[next[i]];
                    ans++;
                    break;
                }
            }
            else
            {
                i = next[i];
                break;
            }
            }
        }

    }
    cout << ans <<endl;
    return 0;
}

