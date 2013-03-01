#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int T, n, m, k;
string s,ans;
char conv[30][30];
bool opp[30][30];
char st[500];
void init()
{
     for (int i=0; i<=27; i++)
       for (int j=0; j<=27; j++)
         conv[i][j] = '-';
     memset(opp, false, sizeof(opp));
     }
int main()
{
   // freopen("B-large.in", "r", stdin);
  //  freopen("B-large.out", "w", stdout);
    cin >>T;
    for (int t=1; t<=T; t++)
    {
       cin >>n;
       init();
       for (int i=0; i<n; i++)
       {
          cin >>s;
          conv[s[0]-'A'][s[1]-'A'] = s[2];
          conv[s[1]-'A'][s[0]-'A'] = s[2];   
       }
       cin >>m;
       for (int i=0; i<m; i++)
       {
           cin >>s;
           opp[s[0]-'A'][s[1]-'A'] = true;
           opp[s[1]-'A'][s[0]-'A'] = true;           
       }
       cin >>k;
       cin >>s;
       int hi=0, lo=0;
       bool flag = true;
       for (int i=0; i<k; i++)
       {
           st[hi++] = s[i];
           flag = true; 
           while (flag)
           {
              flag = false;
              if (hi-2>=lo && conv[st[hi-1]-'A'][st[hi-2]-'A']!='-')
              {
                 st[hi-2] = conv[st[hi-1]-'A'][st[hi-2]-'A'];
                 hi--;
                 flag = true;  
                 continue;
              } 
              for (int j=hi-2; j>=lo; j--)
              if (opp[st[hi-1]-'A'][st[j]-'A'])
              {
           
                 hi = lo;                     
                 break;                             
              }
           }
       
       }  
       ans.clear();
       for (int i=lo; i<hi; i++) ans = ans + st[i] + ", ";
       if (ans!="") ans.erase(ans.length()-2, 2);
       cout <<"Case #"<<t<<": ["<<ans<<"]"<<endl;
    }
    return 0;
    }
