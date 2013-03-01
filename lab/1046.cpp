#include <iostream>
#include <string>
using namespace std;

struct bignum
{
       int d[100], len;
       };
string s1, s2;
bignum d1, d2;
void tra(string &s, bignum &a)
{
     a.len = int(s.size());
     for (int i=a.len-1, j=0; i>=0; i--,j++) a.d[i] = int(s[j]-'0');     
     }
bignum pp(bignum &a1, bignum &a2)
{
       bignum t;
       t.len = max(a1.len, a2.len);
       int c = 0;
       for (int i=0; i<t.len; i++)
         {
            c += a1.d[i] + a2.d[i];
            t.d[i] = c % 10;
            c /= 10;                
         }
       while (c != 0) {t.d[t.len++] = c % 10; c/=10;}
       return t;
       }
int main()
{
    cin >>s1;
    cin >>s2;
    tra(s1, d1);
    tra(s2, d2);
    bignum ans = pp(d1, d2);
    for (int i=ans.len-1; i>=0; i--) cout<<ans.d[i];
    cout<<endl;
    system("pause");     
    return 0;
    }
