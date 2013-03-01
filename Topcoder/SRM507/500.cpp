#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <functional>
#include <algorithm>
#include <set>
#include <stack>
#include <cctype>
using namespace std;

map<string, int> c;
vector<string> s;
      bool cmp(string a, string b)
      {
           return c[a] > c[b];
           }
class CubeStickers
{
      public :

      string isPossible(vector <string> sticker)
      {
         c.clear();
         s.clear();
         sort(sticker.begin(), sticker.end());
         int tot = 0;
         for (int i=0; i<sticker.size(); i++)
         {
             if (c[sticker[i]]==0){tot++; c[sticker[i]]++;s.push_back(sticker[i]);}
             else
               c[sticker[i]]++;
         }
         if (tot < 3) return "NO";
         else
         if (tot >= 6) return "YES";
         
         sort(s.begin(), s.end(), cmp);   
         if (s.size()==3 && (c[s[0]]<2 || c[s[1]] < 2 || c[s[2]]<2)) return "NO";
         else
         if (s.size()==4 && (c[s[2]]<2 || c[s[3]]<2)) return "NO";
         else
         if (s.size()==5 && c[s[4]] < 2) return "NO";
         else return "YES";      
      }
      };
