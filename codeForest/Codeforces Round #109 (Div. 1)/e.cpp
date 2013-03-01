/*
 * Author:  Troy
 * Created Time:  2012/2/29 20:17:25
 * File Name: e.cpp
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
long long x1, x2, a, b;
int main() 
{
    cin >>x1 >>x2 >>a >>b;
    
    if (x2 >= x1 + a && x2 <= x1 + b)
    {
        cout <<"FIRST" <<endl;
        cout <<x2 <<endl;
        return 0;
    }
    if (a <= 0 && b >= 0)
    {
        cout <<"DRAW" <<endl;
        return 0;
    }
    else
    {
        if (x1 < x2)
        {
            if (b < 0) cout <<"DRAW" <<endl;
            else
            {
                long long d = x2 - x1;
                long long tmp = d % (a + b);
                if (tmp == 0) cout <<"SECOND" <<endl;
                else
                {
                    if (tmp >= a && tmp <= b)
                    {
                        cout <<"FIRST" <<endl;
                        cout <<tmp + x1 <<endl;
                    }
                    else cout <<"DRAW" <<endl;
                    
                }
            }
        }
        else
        {
            if (a > 0) cout <<"DRAW" <<endl;
            else
            {
                long long d = x1 - x2;
                a = -a; b = -b;
                long long s = (a + b);
                long long tmp = d % s;
                swap(a, b);
                if (tmp == 0) cout <<"SECOND" <<endl;
                else
                {
                    if (tmp >= a && tmp <= b)
                    {
                        cout <<"FIRST" <<endl;
                        cout << -tmp + x1 <<endl;
                    }
                    else cout <<"DRAW" <<endl;
                }
                
            }
            
        }
        
    }
        
    return 0;
}

