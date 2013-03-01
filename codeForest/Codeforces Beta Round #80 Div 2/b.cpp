#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;

long long a[1000];

int main()
{
    long long T,summ,temp;
    cin >> T;
    summ=0;
    temp=0;
    for (int i=1; i<=T; i++)
    {
        cin >> a[i];
    }
    for (int i=1; i<=T; i++)
    {
       summ+=a[i]+(a[i]-1)*(i-1);

    }
    cout << summ << endl;
    return 0;
}

