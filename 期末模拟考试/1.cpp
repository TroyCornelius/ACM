#include <iostream>
#include <ctype.h>
using namespace std;

double a, b, c, r;
int main()
{
    cin >>a >>b >>c;
    cin >>r;
    if (r > a || r > b || r > c || 4 * r*r*r * 3.1415/4 >= a*b*c) cout <<"N" <<endl;
    else cout <<"Y" <<endl;
    system("pause");
    return 0;
    }
