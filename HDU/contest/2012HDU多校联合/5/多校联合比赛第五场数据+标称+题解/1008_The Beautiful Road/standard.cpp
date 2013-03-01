#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;
typedef __int64 LL;
const int M = 1000000007;

char s[805];

int main()
{
 //   freopen("data.in","r",stdin);
 //   freopen("data.out.txt","w",stdout);
    int cas;
    cin >> cas;
    while(cas--)
    {
        cin >> s;
        int n = strlen(s);
       // fprintf(stdout,"n=%d\n",n);
        int i,j,k,icount=0;

        for(i=0; i<n; i++)
            if(s[i] == 'R')
              ++icount;
        LL res = (icount == 0); // ????G??
        for(i=0; i<n; i++)
          if(s[i]=='?' || s[i]=='R')
          {
              int x = (s[i] == 'R');
              if(x == icount)
                 res = (res + 1) % M;
              for(j=1; j+i<n; j+=2)
              {
                  int y = x;
                  for(k=i+j; k<n; k+=j)
                  {
                      y += (s[k]=='R');
                      if(s[k] == 'G') break;
                      res = (res+(y==icount)) % M;
                  }
              }
          }
        LL p = 1;
        for(i=0; i<n; i++)
        {
            if(s[i] == '?')
              p = p * 2 % M;
        }
        res = ((p-res)%M+M)%M;

        cout << res << endl;
    }
    return 0;
}
