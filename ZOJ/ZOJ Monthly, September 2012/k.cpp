/*
 * Author:  Troy
 * Created Time:  2012/9/29 12:19:17
 * File Name: k.cpp
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

string s;
long long A, B;
int next;
inline long long get_num(int idx) {
    long long ret = 0 ;
    while (idx < s.size() && isdigit(s[idx])) {
        ret = ret * 10 + s[idx] - '0';
        idx++;
    }
    next = idx;
    return ret;
}
long long calc() {
    long long ret = 0;
    ret = get_num(0);
    int i = next;
    bool flag = true;
    while (i < s.size()) {
        if (s[i] == '+') flag = true;
        else flag = false;
        long long tmp = get_num(i+1);
        if (flag) ret += tmp;
        else ret -= tmp;
        //cout <<ret <<" "<<flag <<" "<<tmp <<endl;
        i = next;
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    while (cin>>s) {
        cin >>A >>B;
        if (A == 9) cout <<"A" <<endl;
        else if (B == 9) cout <<"B" <<endl;
        else {
            long long sum = calc();
            //cout <<sum <<endl;
            if (sum == A) cout <<"B" <<endl;
            else cout <<"A" <<endl;
        }
    }
    return 0;
}

