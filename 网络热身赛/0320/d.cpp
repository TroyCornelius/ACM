#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;


int n, m;
//char s[100], tmp[100];
string s, tmp;
int pos[100];
bool b[100];
vector<int> d;

int gcd(int a, int b)
{
    if (a%b==0) return b;
    else return gcd(b, a%b);
    }
int get_times()
{
    memset(b, false, sizeof(b));
    d.clear();
    for (int i=0; i<n; i++)
    {
        if (!b[i]) 
        {
           int tot = 1, t = pos[i];
           b[i] = true;
           while (!b[t])
           {
              tot++;
              b[t] = true;
              t = pos[t];                 
           }
           if (tot != 1) d.push_back(tot);                              
        }        
    }
    sort(d.begin(), d.end(), greater<int>());
    if (d.size() == 0) return 0;
    else
    if (d.size() == 1) return d[0];
    else
    {
        int ret = d[0];
        for (int i=1; i<d.size(); i++)
        {
            ret = d[i] / gcd(ret, d[i]) * ret;            
        }
        return ret;
    }
    }
int main()
{
    while (scanf("%d%d", &n, &m))
    {
        if (n==0 && m==0) break;
        for (int i=0; i<n; i++)
        {
            scanf("%d", &pos[i]);
            pos[i]--;            
        }
      //  getchar();
     //   gets(s);
        getchar();
        getline(cin, s);
     //   cout <<s <<endl;
        int ti = get_times();
       // cout <<"ti is : " <<ti <<endl;
        //ti = m % ti;
        m %= ti;
        m = ti - m;
        for (int i=1; i<=m; i++)
        {            
            tmp.clear();   
            for (int j=0; j<n; j++) tmp = tmp + s[pos[j]];
            s = tmp;
        }
      //  puts(s);
       // printf("\n");
       cout <<s <<endl;
          
    }
    
    
    return 0;
    }
