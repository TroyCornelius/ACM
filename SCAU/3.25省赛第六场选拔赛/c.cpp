/*
 * Author:  Troy
 * Created Time:  2012/3/25 14:13:13
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
#include <cctype>

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

int x[10], cnt;
string s;
string trans(int k)
{
    string ret = "";
    while (k)
    {
        char ch = '0' + (k%10);
        ret = ch + ret;
        k /= 10;
    }
    return ret;
}
bool check(int loc)
{
    FORD(i, loc-1, 0)
        if (x[i] != 0) return false;
    return true;
}
int main() 
{
    while (~scanf("%d", &x[0]))
    {
        cnt = 0;
        FOR(i, 1, 9) scanf("%d", &x[i]);
        s.clear();
        FORD(i, 8, 0)
        {
        if (x[i] != 0)
        {
            string num = trans(abs(x[i]));
            string st = "x";
            if (i == 8) st = "";
            else
            {
               st = st + "^" + trans(cnt);
               if (cnt == 1) st = "x";
            }  
            if (num == "1" && i != 8) num = "";
            string sign = "";
            if (x[i] > 0) sign = " + ";
            else sign = " - ";
            if (check(i))
            {
                if (x[i] > 0) sign = "";
                else if (x[i] < 0) sign = "-";
            }
            s = sign + num + st + s;
        }
        cnt ++;
        }
        if (check(9)) s = "0";
        cout <<s <<endl;
    }
    return 0;
}

