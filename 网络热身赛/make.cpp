#include <iostream>
#include <cmath>
using namespace std;


int T,n;
int main()
{
    freopen("std.in", "w", stdout);
    srand(time(NULL));
    T = rand()%20+1;
    cout <<T <<endl;
    for (int i=1; i<=T; i++)
    {
        n = rand()%100 + 1;
        cout<<n <<endl;        
    }
    
    return 0;
    }
