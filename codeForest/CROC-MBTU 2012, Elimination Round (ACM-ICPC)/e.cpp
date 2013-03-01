/*
 * Author:  Troy
 * Created Time:  2012/11/20 0:35:27
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
/*
string s;
int main() {
    int cnt, ans;
    while (cin >>s) {
        cnt = 0, ans = 0;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (j < s.size() && s[j] == s[i]) j++;
            ans = max(ans, j - i);
            i = j;
        }
        cout <<ans <<endl;
    }
    return 0;
}
*/
string s;
int main() {
    while(cin >> s) {
        int ans = 0;
        int in = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '+') {
                if(ans - in == 0) ans++, in++;
                else in++;
            } else {
                if(in == 0) ans++;
                else in--;
            }
        }
        cout << ans << endl;
    }
    return 0;
}


