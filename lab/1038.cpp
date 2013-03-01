#include <iostream>
using namespace std;

int n;
int main()
{
    cin >>n;
    int sp=n-1, st=1;
    for (int i=0; i<n; i++)
      {
         for (int j=0; j<sp; j++) cout<<" ";
         for (int j=1; j<=st; j++) cout<<j;
         for (int j=st-1; j>0; j--) cout<<j;
         cout <<endl;
         sp--;st++;             
      }
    sp = 1; st = n-1;
    for (int i=0; i<n-1; i++)
      {
         for (int j=0; j<sp; j++) cout<<" ";
         for (int j=1; j<=st; j++) cout<<j;
         for (int j=st-1; j>0; j--) cout<<j;
         cout<<endl;
         sp++;st--;
      }
    return 0;
    }
