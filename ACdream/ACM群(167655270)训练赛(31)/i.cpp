/*
 * Author:  Troy
 * Created Time:  2012/5/4 19:33:28
 * File Name: i.cpp
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
int st[30], now[30];

bool check()
{
    FOR(i, 1, 25)
        if (st[i] != now[i]) return false;
    return true;
}
int main() 
{
    while (cin >>s)
    {
        for (int i=1; i<=24; i+=4)
        {
            REP(j, 4) st[i+j] = now[i+j] = i / 4;
        }
        int tmp, t1, t2;
        REP(i, s.size())
        {
            if (s[i] == 'U')
            {
                tmp = now[1];
                now[1] = now[3]; now[3] = now[4]; now[4] = now[2]; now[2] = tmp;
                t1 = now[9]; t2 = now[10];
                now[9] = now[17]; now[10] = now[18];
                now[17] = now[13]; now[18] = now[14];
                now[13] = now[21]; now[14] = now[22];
                now[21] = t1; now[22] = t2;
            }
            else
            if (s[i] == 'u')
            {
                tmp = now[1];
                now[1] = now[2]; now[2] = now[4]; now[4] = now[3]; now[3] = tmp;
                t1 = now[9]; t2 = now[10];
                now[9] = now[21]; now[10] = now[22];
                now[21] = now[13]; now[22] = now[14];
                now[13] = now[17]; now[14] = now[18];
                now[17] = t1; now[18] = t2; 
            }
            else
            if (s[i] == 'D')
            {
                tmp = now[5];
                now[5] = now[7]; now[7] = now[8]; now[8] = now[6]; now[6] = tmp;
                t1 = now[11]; t2 = now[12];
                now[11] = now[19]; now[12] = now[20];
                now[19] = now[15]; now[20] = now[16];
                now[15] = now[23]; now[16] = now[24];
                now[23] = t1; now[24] = t2;
            }
            else
            if (s[i] == 'd')
            {
                tmp = now[5];
                now[5] = now[6]; now[6] = now[8]; now[8] = now[7];now[7] = tmp;
                t1 = now[11]; t2 = now[12];
                now[11] = now[23]; now[12] = now[24];
                now[23] = now[15]; now[24] = now[16];
                now[15] = now[19]; now[16] = now[20];
                now[19] = t1; now[20] = t2;
            }
            else
            if (s[i] == 'L')
            {
                tmp = now[9];
                now[9] = now[11]; now[11] = now[12]; now[12] = now[10];now[10] = tmp;
                t1 = now[1]; t2 = now[3];
                now[1] = now[24]; now[3] = now[22];
                now[22] = now[5]; now[24] = now[7];
                now[5] = now[19]; now[7] = now[17];
                now[17] = t1; now[19] = t2;                
            }
            else
            if (s[i] == 'l')
            {
                tmp = now[9];
                now[9] = now[10]; now[10] = now[12]; now[12] = now[11];now[11] = tmp;
                t1 = now[1]; t2 = now[3];
                now[1] = now[17]; now[3] = now[19];
                now[17] = now[7]; now[19] = now[5];
                now[5] = now[22]; now[7] = now[24];
                now[24] = t1; now[22] = t2;                 
            }
            else
            if (s[i] == 'R')
            {
                tmp = now[13];
                now[13] = now[15]; now[15] = now[16]; now[16] = now[14];now[14] = tmp;
                t1 = now[2]; t2 = now[4];
                now[2] = now[18]; now[4] = now[20];
                now[18] = now[8]; now[20] = now[6];
                now[6] = now[21]; now[8] = now[23];
                now[23] = t1; now[21] = t2;  
            }
            else
            if (s[i] == 'r')
            {
                tmp = now[13];
                now[13] = now[14]; now[14] = now[16]; now[16] = now[15];now[15] = tmp;
                t1 = now[2]; t2 = now[4];
                now[2] = now[23]; now[4] = now[21];
                now[21] = now[6]; now[23] = now[8];
                now[6] = now[20]; now[8] = now[18];
                now[18] = t1; now[20] = t2;                 
            }
            else
            if (s[i] == 'F')
            {
                tmp = now[17];
                now[17] = now[19]; now[19] = now[20]; now[20] = now[18];now[18] = tmp;
                t1 = now[3]; t2 = now[4];
                now[3] = now[12]; now[4] = now[10];
                now[10] = now[7]; now[12] = now[8];
                now[7] = now[15]; now[8] = now[13];
                now[13] = t1; now[15] = t2; 
            }
            else
            if (s[i] == 'f')
            {
                tmp = now[17];
                now[17] = now[18]; now[18] = now[20]; now[20] = now[19];now[19] = tmp;
                t1 = now[3]; t2 = now[4];
                now[3] = now[13]; now[4] = now[15];
                now[13] = now[8]; now[15] = now[7];
                now[7] = now[10]; now[8] = now[12];
                now[12] = t1; now[10] = t2;                
            }
            else
            if (s[i] == 'B')
            {
                tmp = now[21];
                now[21] = now[23]; now[23] = now[24]; now[24] = now[22];now[22] = tmp;
                t1 = now[1]; t2 = now[2];
                now[1] = now[14]; now[2] = now[16];
                now[14] = now[6]; now[16] = now[5];
                now[5] = now[9]; now[6] = now[11];
                now[11] = t1; now[9] = t2; 
            }
            else
            if (s[i] == 'b')
            {
                tmp = now[21];
                now[21] = now[22]; now[22] = now[24]; now[24] = now[23];now[23] = tmp;
                t1 = now[1]; t2 = now[2];
                now[1] = now[11]; now[2] = now[9];
                now[9] = now[5]; now[11] = now[6];
                now[5] = now[16]; now[6] = now[14];
                now[14] = t1; now[16] = t2;                
            }
            //FOR(j, 1, 25) cout <<now[j];
            //cout <<endl<<"--------------------" <<endl;
        }
        if (check()) cout <<"yes" <<endl;
        else cout <<"no" <<endl;
        
    }
    return 0;
}

