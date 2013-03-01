#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int T, n, ans;
struct Tnode
{
       int lo, pro;
       Tnode(int a=0,int b=99999)
       {
          lo=a; pro=b;         
       }
       };
vector <Tnode> ora, blu;

void work()
{
     ans = 0;
     int p1=0, p2=0, loco=1, locb=1;
     while (true)
     {
        if (ora[p1].pro == 99999 && blu[p2].pro==99999) break;
        if (ora[p1].pro < blu[p2].pro)
        {
           int t1 = abs(ora[p1].lo-loco)+1;
           int t2 = abs(blu[p2].lo-locb);         
           ans += t1;
           loco = ora[p1++].lo;           
           if (t2 <= t1) locb = blu[p2].lo;  
           else 
           {
              if (locb < blu[p2].lo) locb += t1;
              else locb -= t1;
                
           }                      
        }
        else
        {
            int t2 = abs(blu[p2].lo-locb)+1;
            ans += t2;
            locb = blu[p2++].lo;
            
            int t1 = abs(ora[p1].lo - loco);
            if (t1 <= t2) loco = ora[p1].lo;
            else 
            {
               if (loco < ora[p1].lo) loco += t2;
               else loco -= t2;                 
            }            
        }           
     }     
     
     }
int main()
{
    freopen("A-large1.in", "r", stdin);
    freopen("A-large1.out", "w", stdout);
    scanf("%d", &T);
    for (int t=1; t<=T; t++)
    {
        char ch; int loc;
        ora.clear();
        blu.clear();

        scanf("%d", &n);
        getchar();
        for (int i=0; i<n; i++)
        {
           scanf("%c %d", &ch, &loc);
           getchar();
           if (ch == 'O') ora.push_back(Tnode(loc,i));
           else blu.push_back(Tnode(loc,i));   
        }
        
        ora.push_back(Tnode(0, 99999));
        blu.push_back(Tnode(0, 99999));
        work();
        printf("Case #%d: %d\n", t, ans);
    }

    
    return 0;
    }
