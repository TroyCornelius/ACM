#include <iostream>
#include <string>
#include <ctype.h>
#include <cstring>
using namespace std;

class SentenceCapitalizerInator
{
      
      public :
      string fixCaps(string paragraph)
      {
             bool p = true;
             string s = paragraph;
             for (int i=0; i<s.length; i++)
             {
                if (s[i] != ' ' && p ) 
                {
                   s[i] = toupper(s[i]);
                   p = false;
                }
                else
                if (!p && s[i]=='.') p = true;                 
             }
             return s;
      }
      
      };
