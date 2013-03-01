#include <vector>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

class MathContest
{
      string s;
      int ans;
      public :
      int countBlack(string ballSequence, int repetitions)
      {
          s.clear();
          for (int i=0; i<repetitions; i++) s = s + ballSequence;
          int p1=0, p2=s.length()-1, op=0;
          ans = 0;
          while  (p1 <= p2)
          {
             if (op == 0)
             {
               if (s[p1] == 'B')
               {
                  ans++; p1++;
                  for (int j=p1; j<=p2; j++) s[j]=(s[j]=='B')?'W':'B';                         
               }        
               else
               {
                   p1++; op = 1;                   
               }            
             }
             else
             {
                 if (s[p2]=='B')
                 {
                    ans++;
                    p2--;
                    for (int j=p2; j>=p1; j--) s[j]=(s[j]=='B')?'W':'B';
                 }
                 else
                 {
                    p2--; op=0;   
                 }                 
             }
          }       
          return ans;
      }
      
      }; 
