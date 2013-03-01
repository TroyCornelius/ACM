#include <iostream>
#include <cstdio>
using namespace std;

int x, y;
int main()
{
    cin >>x >>y;
    int ans = 0;
    bool flag = true;
    while (flag)
    {
       flag = false;
       if (x>=2 && y>=2)
       {
          x -= 2; y-=2;
          flag = true;
       }
       else
       if (x >= 1 && y >=12)
       {
          x -= 1; y-=12;
          flag = true;     
       }
       else
       if (y >= 22)
       { 
          y -= 22;
          flag = true;     
       }
       
       if (!flag) break;
       ans = 1 - ans;
       flag = false;
       if (y >= 22)
       {
          y -= 22;
          flag = true;     
       }
       else
       if (x >= 1 && y>=12)
       {
          x-=1;y-=12;
          flag = true;      
       }
       else
       if (x >=2 && y>=2)
       {
          x-=1;y-=2;
          flag = true;             
       }
       if (!flag) break;
       ans = 1 - ans;
    }
    if (ans == 1) cout <<"Ciel"<<endl;
    else cout <<"Hanako" <<endl;

    return 0;
    }
