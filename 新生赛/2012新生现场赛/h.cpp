
#include <stdio.h>
#include <stdlib.h>


#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,b) FOR(i,0,b)
using namespace std;

long long x, y;
int main() 
{
    int T, ca = 0;
    scanf("%d", &T);
    while (T--)
    {
      //  scanf("%lld%lld", &x, &y);
      //  printf("Case %d: %lld\n", ++ca, y + x * x);
        cin >>x >> y;
        cout <<"Case "<<++ca <<": "<< x + y * x <<endl;
    }
    return 0;
}

