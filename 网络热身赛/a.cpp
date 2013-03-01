#include <iostream>
#include <cmath>
using namespace std;

int n;
int main()
{
    cin >>n;
    int c = int(sqrt(double(n)));
    if (c * c == n) cout <<"Y" <<endl;
    else cout <<"N"<<endl;

    return 0;
    }
