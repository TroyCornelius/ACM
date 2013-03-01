/*
 * Author:  Troy
 * Created Time:  2012/12/7 20:45:35
 * File Name: 
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

int main() {
    freopen("d.in", "w", stdout);
    srand(time(NULL));
    int len = 10;
    REP(i, 10) {
        int ch = rand() % 10;
        cout <<char('a'+ch);
    }
    cout <<endl;
    int Q = 10;
    cout <<Q <<endl;
    while (Q--) {
        int op = rand()%2;
        if (op) {
            int idx = rand()%len+1;
            char c = 'a' + rand()%10;
            cout <<"C " <<idx <<" " <<c <<endl; 
        }
        else {
            int x = rand()%10+1, y = rand()%10+1;
            if (x > y) swap(x, y);
            cout <<"Q " <<x <<" "<<y <<endl;
        }
    }
    return 0;
}

