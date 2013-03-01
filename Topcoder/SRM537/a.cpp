/*
 * Author:  Troy
 * Created Time:  2012/3/18 0:04:24
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
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;


class KingXNewBaby
{
    public:
    string isValid(string name)
    {
        int cnt = 0;
        bool ans = true;
        char ch = '#';
        if (name.length() != 8) ans = false;
        else
        {
            REP(i, name.length())
            {
                if (name[i] < 'a' || name[i] > 'z')
                {
                    ans = false;
                    break;
                }
                else
                {
                    if (name[i] == 'a' || name[i] == 'e' || name[i] == 'i' || name[i] == 'e' || name[i] == 'o')
                    {
                        cnt++;
                        if (ch == '#') ch = name[i];
                        else if (ch != name[i]) {ans = false; break;}
                    }
                }
            }
        }
        if (cnt != 2) ans = false;
        return (ans ? "YES" : "NO");
    }
    
};
 

int main() 
{
    return 0;
}

