#include <iostream>
#include <cmath>
using namespace std;

int x1, y, z1;
int x2, y2, z2;
int d[5];
int gcd(int a, int b)
{
    if (a%b==0) return b;
    else return gcd(b, a%b);
    }
int main()
{
    cin >>x1 >>y >>z1;
    cin >>x2 >>y2 >>z2;
    d[0] = abs(x1 - x2);
    d[1] = abs(y - y2);
    d[2] = abs(z1 - z2);
    if (d[0]==0 || d[1]==0 || d[2]==0) {cout<<"0"<<endl; return 0;}
    sort(d, d+3, greater<int>());
    int ans = d[0] + d[1] + d[2] - gcd(d[0], d[1]) - gcd(d[0], d[2]) - gcd(d[1], d[2]);
    int t = gcd(d[0], d[1]);
    if (t < d[3]) swap(t, d[2]);
    ans += gcd(t, d[2]);
    cout <<ans <<endl;
      
    return 0;
    }
