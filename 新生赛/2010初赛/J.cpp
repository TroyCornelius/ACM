#include <iostream>
using namespace std;

int x, y, z, ans;
int main()
{
    cin >>x >>y >>z;
    ans = 0;
    while (x-2 >= 0 && z-1>=0)    //20+20+32=72
      {
         x-=2;
         z-=1;
         ans++;          
      }    
    while (x-2>=0 && y-1>=0)     //20+20+28=68
      {
          x-=2; y-=1;
          ans++;         
      }
    while (z-2>=0)       //32+32 = 64
      {
         z-=2;
         ans++;          
      }  
    while (y-1>=0 && z-1>=0)  //28+32 = 60
      {
         y--; z--;
         ans++;          
      }
    while (x-3>=0)    //20+20+20=60
      {
          x-=3;
          ans++;          
      }
    while (y-2>=0)   //28+28 = 56
      {
          y-=2;
          ans++;          
      }
    int tmp = 0;
    if (z!=0) tmp+=32;
    if (y!=0) tmp+=28;
    while (x>0)
      {
          if (tmp+20 > 75) {tmp=0;ans++;}
          tmp+=20;
          x--;          
      }
    if (tmp!=0) ans++;  
    cout <<ans <<endl;

    return 0;
    }
