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
const int MAXint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

const int mod = 1000000007;

int f[2];
int MAX(int a, int b)
{
    return a > b ? a : b;
}
class AkariDaisukiDiv1
{
    public:
    int countF(string Wa, string Ak, string Da, string S, string F, int k)
    {
        string st = Wa + S + Ak + S + Da;
        
        int tot = 0, lenf = F.length(), c = 0;
        cout <<tot <<endl;
        cout <<st <<" "<<lenf <<" "<<(int)st.size() - lenf + 1 <<endl;
        REP(i, (int)st.length() - lenf + 1)
        {
            if (i + lenf <= (int)st.length() && st.substr(i, lenf) == F) tot++;
        }
        cout <<tot <<endl;
        
        string tmp ;
        tmp = Wa + st;
        REP(i, (int)Wa.length())
        if (i + lenf <= (int)tmp.length())
        {
            if (tmp.substr(i, lenf) == F) c++;            
        }
        cout <<c <<endl;
        tmp = st + Ak;
        FOR(i, MAX((int)st.length() - lenf + 1, 0), MAX(0, (int)tmp.length() - lenf + 1))
            if (i + lenf <= (int)tmp.length() && tmp.substr(i, lenf) == F) c++;
        
        cout <<c <<endl;
        tmp = Ak + st;
        REP(i, (int)Ak.length())
            if (i + lenf <= (int)tmp.length() && tmp.substr(i, lenf) == F) c++;
        
        cout <<c <<endl;
        tmp = st + Da;
        for (int i = MAX(0, (int)st.length() - lenf + 1); i < MAX(0, (int)tmp.length() - lenf + 1); i++)
            if (i + lenf <= (int)tmp.length() && tmp.substr(i, lenf) == F) c++;
        
        cout <<c <<endl;
        int p = 1;
        f[0] = tot;
        FOR(i, 1, k)
        {
            f[p] = (f[p^1] * 2 % mod + c) % mod;
            p ^= 1;
        }
        return f[p^1];
    }
}t;
 

int main() 
{
    cout <<t.countF("a", "b", "c", "x", "abcdefghij", 1) <<endl;
    return 0;
}

