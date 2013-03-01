/*
 * Author:  Troy
 * Created Time:  2012/2/19 1:11:14
 * File Name: 500.cpp
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
void dfs(vi d, int sum)
{
    if (d.size() <= 2)
    {
        ans = max(ans, sum);
        return;
    }
    for(int i = 1; i<d.size()-1; i++)
    {
        vi tmp = d;
        tmp.erase(tmp.begin()+i);
        dfs(tmp, sum + d[i-1] * d[i+1]);
    }
    return ;
}
class CasketOfStarEasy
{
    public:
    int maxEnergy(vector <int> w)
    {
        ans = 0;
        vi t = w;
        dfs(w, 0);
        return ans;       
    }
    
};


int main() 
{
    return 0;
}

