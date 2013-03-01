#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

long long n, pd, pg;
int T;

bool check()
{
     if(pg == 100 && pd != 100) return false;
     if(pg == 0 && pd != 0) return false;
     
     if (n > 100) n = 100;
     
     for (int i=1; i<=n; i++)
       for (int j=0; j<=i; j++)
         if (j * 100 == pd*i) return true;
     return false;  
     }
int main()
{
 //   freopen("A-large.in", "r", stdin);
 //   freopen("A-large.out", "w", stdout);
    cin >>T;
    for (int t=1; t<=T; t++)
    {
        cin >>n >>pd >>pg;
        if (check()) cout<<"Case #"<<t<<": "<<"Possible"<<endl;
        else cout <<"Case #"<<t<<": "<<"Broken" <<endl;
    }
    
    return 0;
    }
