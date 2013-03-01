/*
 * Author:  Troy
 * Created Time:  2012/3/21 0:07:34
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


bool check(string s, vi c, int B, int w)
{
    int h = s.length();
    REP(i, h) 
        if (isdigit(s[i])) c[s[i] - '0']--;
    int tot = 0;
    REP(i, 3)
        if (c[i] < 0) return false;
        else tot += c[i];
    
}

class SkewedPerspectives
{
    public:
    vector <string> areTheyPossible(vector <int> cubes, int B, int w, vector <string> views)
    {
        vector<string> ans;
        cout <<ans[2] <<endl;
        REP(i, views.size())
            if (check(views[i], cubes, B, w)) ans.pb("valid");
            else ans.pb("invalid");
        return ans;
    }
        
};
    
 



int main() 
{
    cout <<(-3)%2 <<endl;
    return 0;
}

