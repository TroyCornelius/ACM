#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <stack>
#include <cctype>
using namespace std;

vector<int> q;
class TheJackpotDivTwo
{
      
      public :
      vector <int> find(vector <int> money, int jackpot)
      {
             vector<int> ret;
             ret.clear();
             q.clear();
             make_heap(q.begin(), q.end(), greater<int>());
             for (int i=0; i<money.size(); i++)
             {
                 q.push_back(money[i]);
                 push_heap(q.begin(), q.end(), greater<int>());                 
             }
             int tmp;
             while (jackpot > 0)
             {
                   tmp = q[0];
                   pop_heap(q.begin(), q.end(), greater<int>());
                   q.pop_back();
                   tmp++;
                   q.push_back(tmp);
                   push_heap(q.begin(), q.end(), greater<int>());
                   jackpot--;
             }
             ret = q;
             sort(ret.begin(), ret.end());
             return ret;
             
      }
      
      };
