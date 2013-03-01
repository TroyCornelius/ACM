#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define pb push_back
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define REP(i,b) FOR(i,0,b)
using namespace std;
const int MOD = 1000007;
typedef vector<int> vi;
int n;


void test()
{
    vi v;
    for (int i=1; i<=100; i++)
        for (int j=i; j<=100; j++)
        {
            if ((i*j)%(i+j) == 0) v.pb((i*j)/(i+j));
        }
    sort(all(v));
   // v.erase(unique(all(v)), v.end());
    REP(i, v.size()) cout <<v[i]<<" ";
    cout <<endl;
}
int main()
{
    test();
    while (cin >>n)
    {
        
    }
    return 0;
}
