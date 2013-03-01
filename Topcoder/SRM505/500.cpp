#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

class PerfectSequences
{
      public :
      string fixIt(vector <int> seq)
      {
          long long sum=0, pro=1;
          long long t1, t2, t;
          for (int i=0; i<seq.size(); i++)
          {
              sum += seq[i];
              pro *= seq[i];  
          }
          if (seq.size() == 1) return "Yes";
          for (int i=0; i<seq.size(); i++)
          {
              t1 = (sum - seq[i])*seq[i];
              t2 = pro - seq[i];
              if (t2 == 0 && t1 == 0 && sum != seq[i])
              {
                 t = sum;
                 long long s1=t, p1=t;
                 for (int j=0; j<seq.size(); j++)
                 if (j != i)
                 {
                    s1 += seq[j]; p1 *= seq[j];     
                 }
                 if (s1 == p1) return "Yes";
                     
              }
              else
              if (t2 != 0 && t1 % t2 == 0 )
              {
                  bool f = true;
                  t = t1 / t2;
                  if (t < 0 || t == seq[i]) continue;
                  for (int j=0; j<seq.size(); j++)
                  if (j!= i && seq[j] < 0)
                  {
                     f = false;
                     break;       
                  }
                  if (f) return "Yes";                     
              }              
          }
          return "No";         
      }
      }d;
int n;
int main()
{
    scanf("%d", &n);
    vector<int> s;
    s.clear();
    int tmp;
    for (int i=0; i<n; i++)
    {
        scanf("%d", &tmp);
        s.push_back(tmp);
    }
    cout <<d.fixIt(s) <<endl;
    system("pause");
    
    
    return 0;
    }
