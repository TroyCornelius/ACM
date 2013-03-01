/*
 * Author:  Troy
 * Created Time:  2013/1/18 23:11:51
 * File Name: make.cpp
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
#define ll long long
#define sf scanf
#define pf printf
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, m;
int main() 
{
    freopen("b.in", "w", stdout);
    srand(time(NULL));
    int T = 5;
    cout <<T <<endl;
    while (T--) {
        n = rand()%10+1;
        m = rand()%10+1;
        cout <<n <<" "<<m <<endl;
        REP(i, n) {
            int x = rand()%20+1;
            cout <<x <<" ";
        }
        cout <<endl;
        while (m--) {
            int op = rand()%2;
            cout <<op <<" ";
            if (op == 0) {
                int x = rand()%n+1;   
                int y = rand()%20+1;
                cout <<x <<" "<<y <<endl;
            }
            else {
                int x = rand()%n+1;   
                int y = rand()%n+1;   
                cout <<x <<" "<<y <<endl;
            }
        }
        cout <<endl;
    }
    return 0;
}

