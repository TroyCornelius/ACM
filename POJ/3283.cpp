#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <stack>
#include <cstring>
#define pb push_back
#define Maxn 100001
using namespace std;

map<string, int> m;
int n, k;
struct Tnode
{
       int next[52];
       void init(){memset(next, 0, sizeof(next));}
       }t[Maxn];
void init()
{
 m["AC"] = 0; m["2C"] = 1; m["3C"] = 2; m["4C"] = 3;
 m["5C"] = 4; m["6C"] = 5; m["7C"] = 6; m["8C"] = 7;
 m["9C"] = 8; m["10C"] = 9; m["JC"] = 10; m["QC"] = 11;
 m["KC"] = 12; m["AD"] = 13; m["2D"] = 14; m["3D"] = 15; 
 m["4D"] = 16; m["5D"] = 17; m["6D"] = 18; m["7D"] = 19;
 m["8D"] = 20; m["9D"] = 21; m["10D"] = 22; m["JD"] = 23;
 m["QD"] = 24; m["KD"] = 25; m["AH"] = 26; m["2H"] = 27;
 m["3H"] = 28; m["4H"] = 29; m["5H"] = 30; m["6H"] = 31;
 m["7H"] = 32; m["8H"] = 33; m["9H"] = 34; m["10H"] = 35; 
 m["JH"] = 36; m["QH"] = 37; m["KH"] = 38; m["AS"] = 39;
 m["2S"] = 40; m["3S"] = 41; m["4S"] = 42; m["5S"] = 43;
 m["6S"] = 44; m["7S"] = 45; m["8S"] = 46; m["9S"] = 47;
 m["10S"] = 48; m["JS"] = 49; m["QS"] = 50; m["KS"] = 51;     
}
stack<int> word;
int tot;
string s;
void insert()
{
     int p = 0;
     while (!word.empty())
     {
         int tmp = word.top();
         word.pop();
         if (t[p].next[tmp] == 0)
         {
            t[++tot].init();
            t[p].next[tmp] = tot;                                                               
         }
         p = t[p].next[tmp];           
     }     
     }
int main()
{
    ios::sync_with_stdio(false);
    init();
    while (cin >>n)
    {
       if (n == 0) break;
           tot = 0;
           t[0].init();
       for (int i=0; i<n; i++)
       {
           cin >>k; 

           for (int j=0; j<k; j++)
           {
               cin >>s;
               word.push(m[s]);               
           }
           insert();                     
       }
       cout <<tot <<endl;
    }
    system("pause");
    return 0;
    }
