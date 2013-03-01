/*
 * Author:  Troy
 * Created Time:  2012/12/12 19:45:56
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


class FauxPalindromes {

    public:
    bool is_pal(string s) {
        int i = 0, j = s.size() - 1;
        while (i <= j) {
            if (s[i] != s[j]) return false;
            i++;j--;
        }
        return true;
    }
    bool is_faux(string s) {
        int len = unique(all(s)) - s.begin();
        s.resize(len);
        return is_pal(s);
    }
    string classifyIt(string word) {
        if (is_pal(word)) return "PALINDROME";
        else if (is_faux(word)) return "FAUX";
        else return "NOT EVEN FAUX";
    }
};
 



int main() 
{
    return 0;
}

