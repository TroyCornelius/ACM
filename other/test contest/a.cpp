/*
 * Author:  Troy
 * Created Time:  2012/3/8 20:10:58
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

int main() 
{
    string s1, s2;
    int T, ca = 0;
    cin >>T;
    while (T--)
    {
        cin >>s1 >>s2;
        int loc = s1.find(s2, 0);
        if (loc != string::npos)
        {
            int cnt = 1, p = loc+1, tmp;
            while (((tmp = s1.find(s2, p)) != string::npos))
            {
                cnt++; p = tmp + 1;
            }
            cout <<"Case " <<++ca <<": "<<cnt <<" " <<loc+1 <<endl;
        }
        else
        {
            cout <<"Case " <<++ca <<": "<<0 <<" " <<-1 <<endl;
        }
            
    }
    
    return 0;
}

