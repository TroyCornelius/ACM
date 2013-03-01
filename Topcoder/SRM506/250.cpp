#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class SlimeXSlimeRancher2
{
      
      public :
      int train(vector <int> attributes)
      {
          sort(attributes.begin(), attributes.end());
          int c = attributes[attributes.size()-1];
          int ans = 0;
          for (int i=0; i<attributes.size()-1; i++) ans += c - attributes[i];
          return ans;          
      }
      };
