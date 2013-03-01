#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#define N 100000000
using namespace std;
int main()
{
  /* int i;
    float a=1, b=0;
    for(i=0; i<N; i++) b=a+b;
    printf("%d\n", clock());
    printf("%f\n", 1000.0*N/clock());*/
    unsigned long long a=1;
    for (unsigned long long t=14; t<=25; t++) a*=t;
    for (unsigned long long t=12; t>1; t--) a/=t;
    cout <<a <<endl;
    
    system("pause");
    return 0;
}
