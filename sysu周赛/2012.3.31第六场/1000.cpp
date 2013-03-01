/*
 * Author:  Troy
 * Created Time:  2012/3/31 19:00:17
 * File Name: 1000.cpp
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

int n;
string s;
stack<char> st;
bool check()
{
    REP(i, s.length())
        if (s[i] == '>') st.push(s[i]);
        else
        {
            if (!st.empty()) st.pop();
            else return false;
        }
    return st.size() == 0;
}
int main() 
{
    ios::sync_with_stdio(false);
    int T;
    cin >>T;
    while (T--)
    {
        cin >>n;
        cin >>s;
        while (!st.empty()) st.pop();
        if (check()) cout <<"legal" <<endl;
        else cout <<"illegal" <<endl;
    }
    return 0;
}

