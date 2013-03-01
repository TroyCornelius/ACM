#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

double f[80100];
inline int MAX(int a, int b)
{
       return a>b?a:b;
       }
class FoxListeningToMusic
{
      
      public :
      vector <double> getProbabilities(vector <int> length, int T)
      {
         vector<double> ret;
         ret.clear();
         int n = length.size();
         double pro = 1.0 / double(n);
         memset(f, 0, sizeof(f));
         f[0] = 1.0;
         for (int i=0; i<n; i++)
           for (int j=length[i]; j<=T+1; j++)
           {
               f[j] += f[j-length[i]]*pro;               
           }
         double tmp;
         for (int i=0; i<n; i++)
         {
             tmp = 0.0;
             for (int j=T; j>=MAX(T-length[i]+1, 0); j--)
             {
                 tmp += f[j]*pro;       
             }
             ret.push_back(tmp);
         }
         for (int i=0; i<=T+1; i++) cout <<f[i] <<"  ";
         cout <<endl;
         return ret;
      }      
      }d;
vector<double> ans;
vector<int> inp;
int m, g;
int main()
{
    inp.clear();
    ans.clear();
    cin >>g;
    int tt;
    for (int i=0; i<g; i++)
    {
        cin >>tt;
        inp.push_back(tt);
    }
    cin >>m;
    ans = d.getProbabilities(inp, m);
    for (int i=0; i<ans.size(); i++) cout <<ans[i] <<"   ";
    system("pause");
    return 0;
    }
