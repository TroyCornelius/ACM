#include <iostream>
#include <cmath>
using namespace std;

void move(int n,char a,char b,char c)
{
 if(n==1)
  cout<<a<<"-->"<<c<<endl;
 else
 {
  move(n-1,a,c,b);
  cout<<a<<"-->"<<c<<endl;
  move(n-1,b,a,c);
 }
} 
int main()
{
    move(4,'a','b','c');
    system("pause");
    
    
    return 0;
    }
