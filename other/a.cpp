#include <iostream>
using namespace std;

int n;

int main()
{
    cin >>n;
    
    if (n < 4) cout <<0 <<endl;
    else
    cout << n*(n-1)*(n-2)*(n-3)/24 <<endl;
    return 0;
    }
