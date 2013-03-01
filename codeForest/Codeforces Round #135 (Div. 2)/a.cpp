/*
 * Author:  Troy
 * Created Time:  2012/8/27 23:47:23
 * File Name: b.cpp
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

int k;
string s;
int tot[50];
int main() {
    cin >>k;
    cin >> s;
    memset(tot, 0, sizeof(tot));
    for(int i = 0; i < s.length(); i++) {
        tot[s[i]-'a']++;
    }
    bool flag = true;
    for(int i = 0; i < 26; i++) {
        if(tot[i] % k != 0) flag = 0;
    }
    if(!flag) {
        cout <<-1 <<endl;
    } else {
        string ans = "";
        for(int i = 0; i < 26; i++) {
            char ch = 'a' + i;
            for(int j = 0; j < tot[i] / k; j++) {
                ans += ch;
            }
        }
        for(int i = 0; i < k; i++) cout << ans;
        cout << endl;
    }
    return 0;
}

