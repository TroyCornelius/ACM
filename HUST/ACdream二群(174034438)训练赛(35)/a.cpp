/*
 * Author:  Troy
 * Created Time:  2012/6/1 20:24:00
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

int n;
map<string, set<string> > member;
map<string, set<string> > ans;
string fuck;

set<string> find(string gName)
{
	if (ans.find(gName) != ans.end())return ans[gName];
	
	set<string> ret, tmp;
	for (set<string>::iterator it = member[gName].begin(); it != member[gName].end(); ++it)
	{
		if (member.find(*it) != member.end())
		{
			tmp = find(*it);
			for (set<string>::iterator itt = tmp.begin(); itt != tmp.end(); ++itt)
			{
				ret.insert(*itt);
			}
		} else
		{
			ret.insert(*it);
		}
	}
	ans[gName] = ret;
	return ret;
}

void solve()
{
	member.clear();
	ans.clear();
	
	char c;
	for (int i = 0; i < n; i++)
	{
		getchar();
		string gName;
		while ((c = getchar()) && islower(c))
		{
			gName.push_back(c);
		}
		if (!i) fuck = gName;
		do
		{
			string name;
			while ((c = getchar()) && islower(c))
			{
				name.push_back(c);
			}
			member[gName].insert(name);
		} while (c == ',');
	}
	printf("%d\n", find(fuck).size());
}

int main() 
{
    while (~sf("%d", &n), n)
    {
        solve();
    }
    
    return 0;
}

