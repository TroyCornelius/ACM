/*
 * Author:  Troy
 * Created Time:  2012/2/17 22:58:58
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

int q;

int sg[1000000];
void init()
{
    sg[1] = 0;
    FOR(i, 2, 100)
    {
        sg[i] = 0;
        vi sum;
        sum.clear();
        for (int j=2; j*j<=i; j++)
        if (i % j == 0)
        {
            sum.pb(sg[j]);
            sum.pb(sg[i/j]);
        }
        sort(all(sum));
        sum.erase(unique(all(sum)), sum.end());
        if (sum.empty() || sum[0] != 0) sg[i] = 0;
        else
        {
            int c = 0;
            for (int j=1; j<sum.size(); j++, c++)
                if (sum[j-1] + 1 != sum[j]) break;
            sg[i] = ++c;         
        }
    }
    for (int i=1; i<=100; i++) cout <<i<<"'s sg is :" <<sg[i] <<endl;
    cout <<endl;
    
}
int main() 
{
    cin >>q;
    init();
    
    return 0;
}

