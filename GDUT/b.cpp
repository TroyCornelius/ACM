/*
 * Author:  Troy
 * Created Time:  2012/3/18 12:48:34
 * File Name: 
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

stack<char> ans;
string s;
int main() 
{
    char ch;
    while ((ch = getchar()) != EOF)
    {
        if (ch == '\n') continue;
        else
        if (ch == 'E') ans.push('\n');
        else
        if (ch == 'B') {if (!ans.empty()) ans.pop();}
        else ans.push(ch);
    }
    s.clear();
    while (!ans.empty())
    {
        s = ans.top() + s;
        ans.pop();
    }
    cout <<s;
    return 0;
}

