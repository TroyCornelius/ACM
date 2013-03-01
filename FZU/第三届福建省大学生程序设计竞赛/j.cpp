/*
 * Author:  Troy
 * Created Time:  2012/12/2 19:22:56
 * File Name: j.cpp
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

string s;
int m;
int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >>T;
    while (T--) {
        cin >>s >>m;  
        if (m == 0) cout <<s <<endl;
        else {
            int p = -1;
            char mi = s[0];
            if (s[0] != '1') {
                for (int i = 1; i < s.size(); i++)
                    if (s[i] != '0' && s[i] <= mi) {
                        p = i;
                        mi = s[i];
                    } 
                if (p != -1) swap(s[0], s[p]), m--;
            }
            //cout <<s << " "<<m <<endl;
            int st = 1;
            if (m > 0) {
                while (m) {
                    p = -1;
                    mi = s[st];
                    for (int i = st + 1; i < s.size(); i++)
                        if (s[i] != 0 && s[i] <= mi) {
                            p = i;
                            mi = s[i];
                        } 
                    if (p != -1) swap(s[st], s[p]), m--;
                    st++;
                    //cout <<m <<" "<<st <<" "<<s <<endl;
                    if (st >= s.size()) break;
                }
            }

            if (m % 2 == 0) cout <<s <<endl;
            else {
                if (s.size() == 1) cout <<s <<endl;
                else {
                    swap(s[s.size()-1], s[s.size()-2]);
                    cout <<s <<endl;
                }
            }
        }
    }
    return 0;
}

