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



class ElectionFraudDiv2
{
    public:
    string IsFraudulent(vector <int> percentages)
    {
        int sum = 0, tot = 0, k1 = 0, k2 = 0;
        int n = percentages.size();
        REP(i, percentages.size())
        {
            if (percentages[i] != 100) k1++;
            if (percentages[i] != 0) k2 ++;
            sum += percentages[i];
            tot += percentages[i] * 100;
        }
        if (sum == 100) return (tot == 10000 ? "NO" : "YES");
        else
            if (sum < 100)
            {
                if (k1 * 50 + tot >= 10000) return "NO";
                else return "YES";
            }
            else
            {
                if (tot - k2 * 50 <= 10000) return "NO";
                else return "YES";
            }
        
    }
};

 







