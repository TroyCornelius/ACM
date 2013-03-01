#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

long long n,p,q,ans,now;

int main()
{
    cin >> n;
    ans=0; now=0;
    for (int i=1; i<=n; i++)
    {
        cin >>p >> q;
        now=now-p;
        if (now<0) now=0;
        now=now+q;
        if (now>ans) ans=now;
    }
    cout << ans <<endl;
    return 0;
}
