#include <iostream>
#include <string>
#include <map>
using namespace std;

int T, p;
map<string, int> w2;
map<string, int> w80;
string num2[10]={"-----",".----","..---","...--","....-",".....","-....","--...","---..","----."};
string num80[10]={"-----","-- ---.","-- ---..","-- ---...","-- ---....","-- ---.....","-....","--...","---..","----."};
void init()
{
     w2["-----"]=0;  w2[".----"]=1; 
     w2["..---"]=2;  w2["...--"]=3;
     w2["....-"]=4;  w2["....."]=5;
     w2["-...."]=6;  w2["--..."]=7;
     w2["---.."]=8;  w2["----."]=9;
     
     w80["-----"]=0;  w80["-- ---."]=1;
     w80["-- ---.."]=2;  w80["-- ---..."]=3;
     w80["-- ---...."]=4;  w80["-- ---....."]=5;
     w80["-...."]=6;  w80["--..."]=7;
     w80["---.."]=8;  w80["----."]=9;
     }
string s1, s2;
void tran2(unsigned long long k)
{
     if (k==0) return;
     else
        {
           tran2(k/10);
           cout <<num2[k%10];               
        }     
     }
void work1()
{
     getline(cin, s1);
     getline(cin, s2);
     unsigned long long ta=0, tb=0;
     string t="";
     for (int i=0; i<s1.size(); i+=5)
       {
          t = s1.substr(i,5);
          ta = ta*10 + w2[t];              
       }
     for (int i=0; i<s2.size(); i+=5)
       {
          t = s2.substr(i,5);
          tb = tb*10 + w2[t];              
       }     
     if (ta + tb==0) cout <<num2[0];
     else
     tran2(ta+tb);
     }
unsigned long long conv(string s)
{
     int i=0, j;
     unsigned long long ret = 0;
     string st;
     while (i < s.size())
       {
          st = s.substr(i,5);
          if (st==num80[0]) {ret = ret*10 + 0; i+=5; continue;}
          else
          if (st==num80[6]) {ret = ret*10 + 6; i+=5; continue;}
          else
          if (st==num80[7]) {ret = ret*10 + 7; i+=5; continue;}
          else
          if (st==num80[8]) {ret = ret*10 + 8; i+=5; continue;}
          else
          if (st==num80[9]) {ret = ret*10 + 9; i+=5; continue;}
          else
            {
               st=s.substr(i,6);
               i+=6;
               while (s[i]=='.' && i < s.size()) 
                 {
                     st = st + s[i];
                     i++;
                 }
               ret = ret*10 + w80[st];                                       
            }
       }
     return ret;
     }
void tran80(unsigned long long k)
{
     if (k==0) return;
     else
        {
           tran80(k/10);
           cout <<num80[k%10];               
        }     
     }
void work2()
{
     getline(cin, s1);
     getline(cin, s2);
     unsigned long long ta = conv(s1);
     unsigned long long tb = conv(s2);
     if (ta+tb==0) cout<<num80[0] ;
     else
     tran80(ta+tb);    
     }
int main()
{
    cin >>T;
    init();
    for (;T>0; T--)
      {
         cin >>p;
         getchar();
         if (p == 2) work1();
         else work2();
         cout <<endl;               
      }

    return 0;
    }
