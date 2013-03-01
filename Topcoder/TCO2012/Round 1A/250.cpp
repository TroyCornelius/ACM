
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

#include <cctype>
#include <functional>
#include <deque>


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

map<string,int> mst;
class EllysJuice
{
    public:
    vector <string> getWinners(vector <string> players)
    {
        vector<string> ans;
        mst.clear();
        REP(i, players.size()) mst[players[i]]++;
        for (map<string,int>::iterator it = mst.begin(); it != mst.end(); it++)
            if (it->se >= 2) ans.pb(it->fi);
        sort(all(ans));
        if (players.size() == 1) ans = players;
        return ans;
    }

};

int main() 
{
    return 0;
}

