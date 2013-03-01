#include <iostream>
#include <cmath>
using namespace std;
typedef __int64 LL;
int main()
{
 //   freopen("data.in", "r", stdin);
 //   freopen("data.out", "w", stdout);
    LL n,m,ans,total;
    cin>>total;
    while (total--)
    {
        cin>>n;
        n+=sqrt(n)+0.5;
        m=sqrt(n)-1;
        ans=(m*(m+1)*(2*m+1))/3 +(m+1)*m/2+ (m+1)*(n-(m+1)*(m+1)+1);
        cout<<n<<" "<<ans<<endl;
    }
    return 0;
}