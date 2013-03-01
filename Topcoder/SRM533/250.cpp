/*
 * Author:  Troy
 * Created Time:  2012/2/19 0:42:48
 * File Name: 250.cpp
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


class PikachuEasy
{
    public:
    string check(string word)
    {
        int i = 0;
        while (i < word.length())
        {
            if (word[i] == 'p')
            {
                if (i+1<word.length() && word[i+1] == 'i') i+=2;
                else return "NO";
            }
            else
                if (word[i] == 'k')
                {
                if (i+1<word.length() && word[i+1] == 'a') i+=2;
                else return "NO";                    
                }
                else
                    if (word[i] == 'c')
                    {
                        if (i+2<word.length() && word[i+1] == 'h' && word[i+2]=='u') i+=3;
                        else return "NO";                    
                    }
                    else return "NO";
        }
        return "YES";
    }
};
int main() 
{
    return 0;
}

