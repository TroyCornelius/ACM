#include <iostream>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <cstring>
#define Maxn 1500
#define oo 1<<30
#define pb push_back
using namespace std;

int n, m, cnt, st;
int dis[Maxn];
const string boss = "Kevin, Bacon";
bool hash[Maxn];
struct Query
{
       string name;
       int ans;
       Query(){}
       Query(string _a, int _b)
       :name(_a),ans(_b){}
       };
struct edge
{
       int id, cap;
       edge() {}
       edge(int _a, int _b)
       :id(_a), cap(_b){}
       };
vector<Query> q;
vector<int> total;
vector<edge> g[Maxn];
map<string,int> mem;
void init()
{
     mem.clear();
     for (int i=0; i<=1100; i++) g[i].clear();   
     cnt = 0;
     }
void spfa()
{
     fill(dis, dis+cnt+5, oo);
     st = mem[boss];
 //    cout <<st <<endl;
     dis[st] = 0;
     queue<int> que;
     memset(hash, false, sizeof(hash));
     while (!que.empty()) que.pop();
     que.push(st);
     while (!que.empty())
     {
           int now = que.front();
           que.pop();
           hash[now] = false;
           for (int i=0; i<g[now].size(); i++)
           {
               int tid = g[now][i].id;
               int len = g[now][i].cap;
               if (dis[now] + len < dis[tid])
               {
                  dis[tid] = dis[now] + len;
                  if (!hash[tid])
                  {
                     hash[tid] = true;
                     que.push(tid);                                 
                  }                            
               }               
           }           
     }
     }
int main()
{
    ios::sync_with_stdio(false);
    int bac, ca = 0;
    string s1, s2, sname;
    vector<int> group;
    while (cin >>n >>m)
    {
          if (n == m && n==0) break;
          init();
          for (int i=0; i<n; i++)
          {
              cin >>bac;
              group.clear();
              while (cin >>s1 >>s2)
              {
                  //  cout <<s1 <<" "<<s2<<endl;                    
                    sname = s1+" "+s2;
                    sname.erase(sname.length() - 1);
                    
                    if (mem.find(sname) == mem.end())
                    {
                       mem[sname] = ++cnt;
                       group.pb(cnt);
                    }
                    else group.pb(mem[sname]);     
                //    cout <<sname <<"  "<<mem[sname] <<endl;
               //     cout <<"---------------------"<<endl; 
                    if (s2[s2.length()-1] == ':') break;              
              }
              getline(cin, s1);
          //    for (int j=0; j<group.size(); j++) cout <<group[j] <<" ";
              for (int x=0; x<group.size()-1; x++)
                for (int j=x+1; j<group.size(); j++)
                {
                    g[group[x]].pb(edge(group[j], bac));
                    g[group[j]].pb(edge(group[x], bac));     
                   // cout <<group[x]<<"  "<<group[j]<<"  "<<bac <<endl;               
                }
          }
         // cout <<cnt <<endl<<endl;
          spfa();
          for (int i=0; i<m; i++)
          {
              getline(cin, s1);
              int tid = mem[s1];
              q.pb(Query(s1, dis[tid]));   
            //  cout <<s1 <<"  "<<tid <<" "<<dis[tid] <<endl;
          }
          total.pb(m);
    }
   
    int j = 0;
    for (int i=0; i<total.size(); i++)
    {
        cout <<"Database "<<++ca<<endl;
        for (int k=0; k<total[i]; k++)
        {
             cout <<q[j].name<<": ";
             if (q[j].ans == oo) cout <<"infinity"<<endl;
             else cout <<q[j].ans <<endl;
             j++;
        }
        cout <<endl;
    }
    system("pause");
    return 0;
    }
