/*
 * Author:  Troy
 * Created Time:  2012/3/18 14:32:42
 * File Name: e.cpp
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

stack<char> st;
string s;
int ans;
int main() 
{
    int ca = 0;
    while (cin >>s)
    {
        ans = 0;
        if (s[0] == '-') break;
        while (!st.empty()) st.pop();
        REP(i, s.length())
        {
            if (s[i] == '{') st.push('(');
            else
            {
                if (st.empty()) 
                {
                    st.push('{');
                    ans++;
                }
                else st.pop();
            }
        }
        int tmp = st.size();
        ans += tmp / 2;
        cout <<++ca <<". " <<ans <<endl;
        
    }
    return 0;
}

