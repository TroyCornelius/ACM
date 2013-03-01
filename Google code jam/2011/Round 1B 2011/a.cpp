#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;


int T, n;
double wp[110], owp[110], oowp[110];
char map[110][110];

double get_wp(int x, int y)
{
       double s=0, st=0;
       for (int j=1; j<=n; j++)
       if (j!=x && map[y][j] != '.')
       {
          if (map[y][j] == '1') {s++; st++;}
          else
          if (map[y][j] == '0') st++;                
       }
       return s / st;
       
}
int main()
{
   // freopen("A-large.in", "r", stdin);
  //  freopen("A-large.out", "w", stdout);
    cin >>T;
    for (int t=1; t<=T; t++)
    {
        cin >>n;
        for (int i=1; i<=n; i++)
          for (int j=1; j<=n; j++) 
            cin >>map[i][j];
        
        double sumw, sumt, sum;
        
        memset(wp, 0, sizeof(wp));
        memset(owp, 0, sizeof(owp));
        memset(oowp, 0, sizeof(oowp));

        for (int i=1; i<=n; i++)
        {
           sumw = sumt = 0.0;
           for (int j=1; j<=n; j++)
             if (map[i][j]=='1') {sumw++; sumt++;}
             else 
             if (map[i][j]=='0') sumt++;
           wp[i] = sumw / sumt;       
        }
        
        for (int i=1; i<=n; i++)
        {
            sumt = sum = 0.0;
            for (int j=1; j<=n; j++)
            if (map[i][j]!='.')            
            {
                sum += get_wp(i, j);
                sumt++;                
            }
            owp[i] = sum / sumt;            
        }
        
        for (int i=1; i<=n; i++)
        {
            sumt = sum = 0.0;
            for (int j=1; j<=n; j++)
            if (map[i][j] != '.')
            {
               sum += owp[j];
               sumt++;             
            }
            oowp[i] = sum / sumt; 
        }
        cout <<"Case #"<<t<<":"<<endl;
        for (int i=1; i<=n; i++) printf("%.7lf\n", 0.25*wp[i]+0.50*owp[i]+0.25*oowp[i]);
    }

    return 0;
    }

