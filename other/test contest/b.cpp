#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int T, ca = 0;
    double n;
    cin >>T;
    while (T--)
    {
        cin >>n;
        printf("Case %d: %.4f\n", ++ca, 2 - 1.0/n);
    }
    return 0;
}
