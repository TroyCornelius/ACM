/*
 * Author:  Troy
 * Created Time:  2012/4/13 1:23:49
 * File Name: 日期功能.cpp
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

const int Day[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
struct Date
{
    int year, month, days;
    Date(){}
    Date(int _year, int _month, int _days) // Month/Day/Year
    :year(_year), month(_month), days(_days){}
};
bool isleap(int year)
{
    return (year % 4 == 0 || year % 400 == 0) && (year % 100 != 0);
}
int compare(const Date &a, const Date &b) //判断两日期大小，若a > b， 返回 1, 否则-1，相等为0
{
    if (a.year != b.year) return a.year > b.year ? 1 : -1;
    else
    {
        if (a.month != b.month) return a.month > b.month ? 1 : -1;
        else
        {
            if (a.days == b.days) return 0;
            else return a.days > b.days ? 1 : -1;
        }
    }
}
int Daysofmonth(Date a)
{
    if (a.month == 2) return Day[a.month] + (isleap(a.year) ? 1 : 0 );
    else return Day[a.month];
}
int DayinYear(const Date &a)  //判断日期在当年是第几天
{
    int ret = a.days;
    FOR(i, 1, a.month) ret += Daysofmonth(Date(a.year, i, a.days));
    return ret;
}
int Daysbewteentow(Date a, Date b) //判断两日期之间相差多少天
{
    if (compare(a, b) == 1) swap(a, b);
    if (a.year == b.year) return DayinYear(b) - DayinYear(a);
    else
    {
        int ret = 365 + isleap(a.year) - DayinYear(a);
        ret += DayinYear(b);
        for (int i = a.year+1; i < b.year; i++) ret += 365 + isleap(i);
        return ret;
    }
}
int n;
Date now, pre;
int main() 
{
    while (~sf("%d", &n), n)
    {
        int ans = 0, tot = 0;
        pre.year = pre.days = pre.month = 1;
        int c, prec;
        prec = 0;
        while (n--)
        {
            sf("%d%d%d%d", &now.days, &now.month, &now.year, &c);
            if (Daysbewteentow(pre, now) == 1)
            {
                ans++;
                tot += c - prec;
            }
            pre = now;
            prec = c;
        }
        pf("%d %d\n", ans, tot);
    }
    return 0;
}


