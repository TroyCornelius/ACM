/*
 * Author:  Troy
 * Created Time:  2012/3/27 23:01:08
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
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n;
double d, a;
double ans;
struct Tnode
{
    double mv, path;
}meet;
inline double calc(double v)
{
    if (v*v > (2.0*a) * d)
    {
        return sqrt(d * 2.0 / a);
    }
    else
    {
        double s = v * v / (2.0 * a);
        double ret = sqrt(s * 2.0 / a);
        ret += (d - s) / v;
        return ret;
    }
}

void print(double ti, double vi)
{
            ans = ti + calc(vi);
            cout <<fixed <<setprecision(10) <<ans <<endl;
            if (vi * vi > 2.0*a*d)
            {
                ans = -1.0;
               // meet = mp(d, sqrt(d*2/a));
            }
            else
            {
                double s = vi*vi/(2.0*a);
                meet.path = s;
                meet.mv = vi;
            }   
}
int main() 
{
    ios::sync_with_stdio(false);
    cin >>n >>a >>d;
    double ti, vi, tmp;
    ans = -1.0;
    REP(i, n)
    {
        cin >>ti >>vi;
        if (ans == -1)
        {
            print(ti, vi);         
        }
        else
        {
         //   cout <<meet.mv <<" : "<<meet.path <<endl;
            if (vi <= meet.mv)
            {
                print(ti, vi);
            }
            else
            {
                double s = vi * vi / (2.0 * a);
                double tmp = meet.mv / a;
                double et = (d - meet.path) / meet.mv;
              //  cout <<tmp <<" +  "<<et <<endl;
                if (tmp >= et)
                {
                    print(ti, vi);
                }
                else
                {
                    double t1 = vi / a;
                    if (t1 < et )
                    {
                        double pt = meet.path / (-0.5*pow(meet.mv, 2.0) + 0.5*vi*vi - meet.mv * vi);
                      //  cout <<t1 <<" "<<pt <<" "<<et <<" "<<ans <<endl;
                        if (pt > et) print(ti, vi);
                        else
                        {
                            cout <<ans <<endl;
                            meet.path += meet.mv * pt;
                        }
                        
                    }
                    else print(ti, vi);
                }
                
            }           
        }
    }
    return 0;
}

