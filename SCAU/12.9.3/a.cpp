/*
 * Author:  Troy
 * Created Time:  2012/9/3 19:26:47
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
#define sf scanf
#define pf printf
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

map<char, char> ans;
char a[21000];
void init() {
    ans['R'] = 'P';
    ans['S'] = 'R';
    ans['P'] = 'S';
    a[1] = 'R';
    a[2] = 'P';
    a[3] = 'S';
    int now = 4;
    for (int i = 1; now <= 1012; i *= 3) {
        for (int j = i + 1; j <= 3 * i; j++) {
            a[now++] = a[j];
            if (now > 1012) break;
        }
        if (now > 1012) break;
        for (int j = 1; j <= i; j++) {
            a[now++] = a[j];
            if (now > 1012) break;
        }
        if (now > 1012) break;
        for (int j = 2 * i + 1; j <= i * 3; j++) {
            a[now++] = a[j];
            if (now > 1012) break;
        }
        if (now > 1012) break;
        for (int j = 1; j <= 2 * i; j++) {
            a[now++] = a[j];
            if (now > 1012) break;
        }
    }

    //for (int i = 1; i <= 100; i++) {
        //cout <<a[i];
        //if (i % 3 == 0) cout <<" ";
    //}
}

char dfs(long long x) {
    //cout <<x <<endl;
    if (x <= 3) {
        if (x == 1) return 'P';
        else if (x == 2) return 'S';
        else return 'R';
    }
    long long t = 3;
    while (t * 3 < x) t *= 3LL;
    //cout <<t <<" !!" <<endl;
    
    int part = 1;
    long long sum = t;
    while (sum < x) sum += t, part++;
    long long res = 1LL * (part - 1) * t;
    t /= 3;
    int np = 1;
    while (res + t < x) res += t, np++;
    
    //cout <<t <<" "<<part <<" "<<np <<" "<<res <<endl;
    if (part == 1) {
        long long tmp = t * (np - 1);
        return dfs(tmp + x - res);
    }
    else if (part == 2) {
        if (np == 1) {
            long long tmp = t;
            return dfs(tmp + x - res);
        }
        else if (np == 2) {
            long long tmp = t * 2;
            return dfs(tmp + x - res);
        }
        else {
            return dfs(x - res);
        }
    }
    else {
        if (np == 1) {
            long long tmp = t * 2;
            //cout <<tmp <<"--" <<endl;
            return dfs(tmp + x - res);
        }
        else if (np == 2) {
            return dfs(x - res);
        }
        else {
            long long tmp = t;
            return dfs(tmp + x - res);
        }
    }
}

int main() 
{
    long long n;
    init();
    while (cin >>n, n) {
        cout <<dfs(n) <<endl;
    }
    return 0;
}

