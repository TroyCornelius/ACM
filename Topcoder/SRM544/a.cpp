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
        int sum = 0;
        int n = percentages.size();
        REP(i, n)
        {
            sum += percentages[i];
        }
        if (sum == 100) return "NO";
        else
        if (sum > 100)
        {
            sum *= 2;
            REP(i, n)
                if (percentages[i] != 0) sum -= 1;
            if (sum <= 200) return "NO";
            else return "YES";
        }
        else
        {
            sum *= 2;
            REP(i, n)
                if (percentages[i] != 100) sum += 1;
            if (sum > 200) return "NO";
            else return "YES";
                
        }
    }
};

 








