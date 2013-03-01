#include <iostream>
#include <cmath>

using namespace std;



double p1, p2, t1, t2;
int main()
{
    double p0 = 1.0150*100000;
    
    while (cin >>p1 >>p2)
    {
          cout <<p1/20.0*1000.0 <<" :  "<<p2/20.0*1000.0 <<endl;
          t1 = p1/20.0*1000.0 + p0;
          t2 = p2/20*1000.0 + p0;
          cout <<"PI is : " <<t1 <<endl;
          cout <<"PIII is : " <<t2 <<endl;
          
          cout <<"r is "<<(log10(p0) - log10(t1)) / (log10(t2) - log10(t1)) <<endl<<endl;           
          
    }
    
    
    return 0;
    }
