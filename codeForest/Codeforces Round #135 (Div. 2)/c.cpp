/*
 * Author:  Troy
 * Created Time:  2012/8/27 23:27:34
 * File Name: c.cpp
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

int n, k;
string s;
int main() 
{
    ios::sync_with_stdio(false);
    cin >>n >>k;
    cin >>s;
    int ans = 0;
    if (n == 1) {
        cout <<0 <<endl;
        cout <<s <<endl;
    }
    else
    if (k == 2) {
        int ct1 = 0, ct2 = 0;
        REP(i, s.size()) 
            if (s[i] != ('A' + (i&1))) ct1++;
        REP(i, s.size()) 
            if (s[i] != ('A' + ((i+1)&1))) ct2++;
        if (ct1 < ct2) {
            cout <<ct1 <<endl;
            REP(i, s.size())
                if (i&1) cout <<'B';
                else cout <<'A';
            cout <<endl;
        }
        else {
            cout <<ct2 <<endl;
            REP(i, s.size())
                if (i&1) cout <<'A';
                else cout <<'B';
            cout <<endl;
        }
    }
    else {
        FOR(i, 1, s.size()) 
            if (s[i] == s[i-1]) {
                char pre = s[i-1], next = (i + 1 >= s.size()) ? '#' : s[i+1];
                for (char ch = 'A'; ch <= 'A'+k-1; ch++)
                    if (ch != pre && ch != next) {
                        ans++;
                        s[i] = ch;
                        break;
                    }
            }
        cout <<ans <<endl;
        cout <<s <<endl;
    }
    return 0;
}

