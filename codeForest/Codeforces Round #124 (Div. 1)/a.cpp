/*
 * Author:  Troy
 * Created Time:  2012/6/12 21:01:31
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
#define sf scanf
#define pf printf
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

string s;
string ans[30];
int main() 
{
    ios::sync_with_stdio(false);
    cin >>s;
    REP(i, 26) ans[i].clear();
    
    REP(i, s.length())
    {
        int id = s[i] - 'a';
        FORD(j, 25, id)
            if (ans[j] != "") 
            {
                id = j;
                break;
            }
        if (ans[id] == "") ans[id] = s[i];
        else
        {
            if (ans[id].length() >= 2 && ans[id][1] < s[i])
            {
                ans[id] = ans[0] + s[i];
            }
            else ans[id] = ans[id] + s[i];
        }
    }    
    
    FORD(i, 25, 0)
        if (ans[i] != "")
        {
            cout <<ans[i] <<endl;
            break;
        }
        
    return 0;
}

