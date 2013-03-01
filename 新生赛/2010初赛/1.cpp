#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#define Maxn 305
using namespace std;

int n, m, k, ti;
string op, res;
string na;
char p;
struct team
{
       string name;
       int AC_tot, pun_time;
       int pro[15][3];
       team()
         {
             name.clear();
             AC_tot = pun_time = 0;
             for (int i=0; i<13; i++)
               {
                  pro[i][0] = 0;        // submit times
                  pro[i][1] = -1;       //AC or not
                  pro[i][2] = 0;        //punish_time for a program             
               }
         }
       }d[Maxn];
void init()
{
     scanf("%d%d%d", &n, &m, &k);
     getchar();  
     for (int i=0; i<n; i++) cin >>d[i].name;  
     }
void work()
{
     for (int i=0; i<n; i++)
       if (d[i].name == na)
         {
            int tmp = int(p - 'A');

            if (res == "AC")
              {
                 if (d[i].pro[tmp][1] == -1) 
                  {
                     d[i].pro[tmp][1] = ti;
                     d[i].pro[tmp][0]++;
                     d[i].AC_tot++;
                     d[i].pun_time += ti + d[i].pro[tmp][2];                                         
                  }
              }
            else
              {
                 if (d[i].pro[tmp][1] == -1)
                   {
                      d[i].pro[tmp][2]+=20;
                      d[i].pro[tmp][0]++;                                 
                   }                 
              }
          break;                                
         }
     
     
     }
bool cmp(const team &a, const team &b)
{
     if (a.AC_tot != b.AC_tot) return a.AC_tot > b.AC_tot;
     else
       {
          if (a.pun_time != b.pun_time) return a.pun_time < b.pun_time;
          else return a.name < b.name;                  
       }     
     }
void print()
{
     printf("rank name prosolved totaltime ");
     for (char c='A'; c<'A'+m; c++) printf("%c ", c);
     cout <<endl;
     sort(d, d+n, cmp);
     for (int i=0; i<n; i++)
       {
          cout <<i+1 <<" " <<d[i].name <<" " <<d[i].AC_tot <<" " <<d[i].pun_time <<" "; 
          for (int j=0; j<m; j++)
            {
              printf("%d", d[i].pro[j][0]);
              if (d[i].pro[j][1] == -1) printf("/- ");
              else printf("/%d ", d[i].pro[j][1]);                   
            }
          printf("\n");              
       }
     }
     
int main()
{
    
    init();
    sort(d, d+n, cmp);
    for (int i=0; i<k; i++)
      {
         cin >>op;
         if (op=="show") print();
         else
           {
              cin >>na >>ti >>p >>res;
              work();                         
           }
            
      }
    return 0;
    }

