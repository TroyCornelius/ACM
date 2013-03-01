#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Tnode
{
       int step, sta;
       Tnode (int a, int b)
         {step = a; sta = b;}     
       };
int T, d[5][5];
const int obj = (1<<16)-1;
bool f[(1<<16)+5];

void bfs()
{
     queue <Tnode> q; 
     while (!q.empty()) q.pop();
     int t=0, tot=15;
     for (int i=0; i<4; i++)
       for (int j=0; j<4; j++)
         if (d[i][j]) {t+=(1<<tot); tot--;}
         else tot--;
     q.push(Tnode(0,t));
     f[t] = true;
     if (t == obj) {cout <<"0" <<endl; return;}
     while (!q.empty())
       {
           Tnode now = q.front();
           for (int i=0; i<16; i++)
             {
                int tmp = now.sta;
                for (int x=4*(i/4); x<4*(i/4+1); x++) tmp^=(1<<x);
                for (int y=(i%4); y<16; y+=4) tmp^= (1<<y);
                tmp^=(1<<i);
                if (tmp == obj) {cout <<now.step + 1 <<endl; return ;}
                if (!f[tmp])
                  {
                     f[tmp] = true;
                     q.push(Tnode(now.step+1, tmp));                            
                  }          
                          
             }
           q.pop(); 
       }
     }
int main()
{
    cin >>T;
    char c;
    for (;T>0; T--)
      {
         for (int i=0; i<4; i++)
           for (int j=0; j<4; j++)
             {
                cin >>c;
                d[i][j] = int(c-'0');                    
             }
         memset(f, false, sizeof(f));
         bfs();               
      }
 
    return 0;
    }
