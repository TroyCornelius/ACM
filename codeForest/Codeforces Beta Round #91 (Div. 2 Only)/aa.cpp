#include <iostream>
#include <cstdio>

using namespace std;

int n;

bool lucky(int k)
{
     while (k > 0)
     {
        if (k % 10 == 4 || k%10 == 7) 
        {
           k/=10;      
        }    
        else return false; 
     }
     return true;
     }
int main()
{
    cin >>n;
    for (int i=4; i<=n; i++)
      if (n % i == 0 && lucky(i)) {cout <<"YES"<<endl;return 0;}
    cout <<"NO" <<endl;
    return 0;
    }
