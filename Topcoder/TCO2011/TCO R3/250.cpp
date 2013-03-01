#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

#include <cctype>


using namespace std;

int gcd(int a, int b)
{
    if (a % b == 0) return b;
    else return gcd(b, a%b);
    }
int mmax(int a, int b)
{
    return a>b?a:b;
    }
int mmin(int a, int b)
{
    return a<b?a:b;
    }
class AllButOneDivisor
{
      public :
      int getMinimum(vector <int> divisors)
      {
          int tmp = 1, ans=-1;
          for (int i=0; i<divisors.size(); i++)
          {
              tmp = 1;
              for (int j=0; j<divisors.size(); j++)
              if (j != i)
              {
                 int t = gcd(mmax(divisors[j],tmp), mmin(divisors[j],tmp));
                 tmp = (tmp * divisors[j]) / t;           
              }
              if (divisors[i]!=tmp && (tmp % divisors[i]) != 0) 
              {
                 if (ans == -1) ans = tmp;
                 else ans = mmin(ans, tmp);
              }              
          }
          return ans;
      }
      };

int main()
{
    vector<int> d;
    d.clear();
    int n;
    cin >>n;
    int tt;
    for (int i=0; i<n; i++) 
    {
        cin >>tt;
        d.push_back(tt);        
    }
    cout <<c.getMinimum(d) <<endl;
    system("pause");
    return 0;   
}
