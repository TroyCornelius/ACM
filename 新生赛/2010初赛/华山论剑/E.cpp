#include <iostream>
#include <queue>
#include <map>
using namespace std;

int n, m, opt, M;
int wea[55], recover[55], c[2700];
bool used[2700], recpoi[2700];
queue <int> q;
void init()
{
     memset(used, false, sizeof(used));
     memset(recpoi, false, sizeof(recpoi));
     memset(c, 0, sizeof(c));
     scanf("%d%d%d%d", &n, &opt, &m, &M);
     for (int i=0; i<opt; i++) scanf("%d", &wea[i]);
     int tmp;
     for (int i=0; i<m; i++)
       {
          scanf("%d", &tmp);
          recpoi[tmp] = true;              
       }     
     }
void bfs()
{
     while (!q.empty()) q.pop();
     c[n]++;
     q.push(n);
     bool flag = true;
     while (!q.empty())
       {
          int now = q.front();
          q.pop();
          for (int i=0; i<opt; i++)
            {
               int t = now - wea[i];
               if (t <= 0) {used[0] = true;continue;}
               if (!recpoi[t] && c[t]<2)
                 {
                    c[t]++;
                    q.push(t);        
                 }
               else
               if (recpoi[t] && c[t+M]<2)
                 {
                    c[t]++;
                    c[t+M]++;;
                    q.push(t+M);                              
                 }     
               else
               if (c[t+M] >= 2) flag = false;    
            }           
       }
     if (!flag || !used[0]) cout <<"1" <<endl;
     else cout <<"0" <<endl;
     
     }
int main()
{
    init();
    bfs();
    system("pause");
    return 0;
    }
