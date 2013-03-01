#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;


int T, n;
struct Tnode
{
       int num;
       string rom;
       }d[10010];		
string g[4][10];	
void init()
{
     g[0][0]="";g[0][1] = "I"; g[0][2]="II";g[0][3]="III";g[0][4]="IV";g[0][5]="V";g[0][6]="VI";g[0][7]="VII";g[0][8]="VIII";g[0][9]="IX";
     g[1][0]="";g[1][1] = "X"; g[1][2]="XX";g[1][3]="XXX";g[1][4]="XL";g[1][5]="L";g[1][6]="LX";g[1][7]="LXX";g[1][8]="LXXX";g[1][9]="XC";								
	 g[2][0]="";g[2][1] = "C"; g[2][2]="CC";g[2][3]="CCC";g[2][4]="CD";g[2][5]="D";g[2][6]="DC";g[2][7]="DCC";g[2][8]="DCCC";g[2][9]="CM";
     g[3][0]="";g[3][1] = "M"; g[3][2]="MM";g[3][3] = "MMM";		
     }		
string get_r(int k)
{
       int p=0;
       string ret="";
       while (k > 0)
       {
          ret = g[p][k%10] + ret;
          k/=10;             
          p++;
       }
       return ret;       
       }
bool cmp(const Tnode &a, const Tnode &b)
{
     return a.rom < b.rom;
     }
int main()
{
    init();
    scanf("%d", &T);
    for (;T>0;T--)
    {
        scanf("%d", &n);
        for (int i=0; i<n; i++) 
        {
            scanf("%d", &d[i].num);
            d[i].rom = get_r(d[i].num);
        }
        sort(d, d+n, cmp);
        for (int i=0; i<n-1; i++) printf("%d ", d[i].num);
        printf("%d\n", d[n-1].num);        
    }

    return 0;
    }
