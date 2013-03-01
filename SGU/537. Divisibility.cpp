#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<iostream>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<cstdlib>
#include<algorithm>
#include<ctime>
#define Maxn 20000010
#define Maxnum 10000010
#define lim 130706
#define upp 10000000
using namespace std;

string s;
map<char, int> gid;
int p[20], ans, tot, cnt, np;
long long d[Maxn], num;
long long pa[1000010], ti[1000010], c[1000010];
int nc;
bool vis[12], pri[Maxnum];


//int vis;
long long  gcd(long long a, long long b)
{
    if (a%b == 0) return b;
    else return gcd(b, a%b);
}
inline long long calc()
{
    long long ret = 0;
    for (int i=0; i<s.length(); i++)
        ret = ret*10 + p[gid[s[i]]-1];
    return ret;
}

void dfs(int dep)
{
    if (num == 1 || cnt > lim) return;
    if (dep >= tot)
    {
        cnt++;
        if (num == -1) num = calc();
        else num = gcd(num, calc());
        return;
    }
    else
    {
    /*    int j;
        if (tot >= 7 && dep < 2)
        {
            int tmp = vis;
            j = rand()%10;
            while ((vis & (1<<j)) && (tmp & (1<<j))) j = rand()%10;        
            if (j == 0 && dep == 0) j = rand()%10;
            vis |= (1<<j);
            tmp |= (1<<j);
            p[dep] = j;
            dfs(dep+1);
            vis -= (1<<j);               
        }
        else*/
        if (dep&1)
        {
                for (int i=9; i>=0; i--)
        if (!vis[i])
        {
            if ((i == 0 && dep == 0) || (dep==tot-1 && i == 0)) continue;
           // vis |= (1<<i);           
            vis[i] = true;
            p[dep] = i;
            dfs(dep+1);
           // vis -= (1<<i);
           vis[i] = false;
        }          
        }
        else
        for (int i=0; i<=9; i++)
        if (!vis[i])
        {
            if ((i == 0 && dep == 0) || (dep==tot-1 && i == 0)) continue;
           // vis |= (1<<i);           
            vis[i] = true;
            p[dep] = i;
            dfs(dep+1);
           // vis -= (1<<i);
           vis[i] = false;
        }
    }
}
void init()
{
     np = 0;
     memset(pri, true, sizeof(pri));
     for (long long i=2; i<=10000000; i++)
     if (pri[i])
     {
        pa[np++] = i;
        for (long long j=i*i; j<=10000000; j+=i) pri[j] = false;
     }  
   //  for (int i=0; i<=100; i++) cout <<pa[i] <<" ";
     }
void work(long long m)
{
     nc = 0;
     int tmp = 0;
     for (int i=0; i<np; i++)
     {
         if (pa[i] > m) break;
         if (m % pa[i] == 0)
         {
               tmp = 0;
               while (m % pa[i] == 0)
               {
                  m/=pa[i];
                  tmp++;                     
               }
               ti[nc] = tmp;
               c[nc++] = pa[i];   
         }
     }
     if (m != 1) ti[nc] = 1, c[nc++] = m;
     return;
  //   cout <<nc<<endl;
    // for (int i=0; i<nc; i++) cout <<c[i] << " "<<ti[nc]<<endl;
     }
void make(int idx, long long sum) //取到第idx个素因子，积为sum 
{
    // if (sum * sum == num) {d[ans++] = sum; return;}
    // if (sum*sum > num) return;  
     if (idx >= nc)
     {
         d[ans++] = sum;
       //  if (num > upp && num % sum == 0)
      //   if (sum * sum != num) d[ans++] = num / sum;
         return;             
     }
     make(idx+1, sum);  //当前因子不取的情况 
     long long st = 1;
     for (int i=1; i<=ti[idx]; i++) 
     {
         st *= c[idx];
         make(idx+1, sum * st);
     } 
     return;  
     }
int main()
{
    ios::sync_with_stdio(false);
   // srand(time(NULL));
    int T, ca=0;
    cin >>T;
    init();
    //cout <<np <<endl;
    while (T--)
    {
        cin >>s;
     //   cout <<"s is :" <<s <<endl;
        gid.clear();
        tot = cnt = 0;
        for (int i=0; i<s.length(); i++)
          if (gid.find(s[i]) == gid.end()) gid[s[i]] = ++tot;
        num = -1;
        memset(vis, false, sizeof(vis));
      //  vis = 0;
        dfs(0);
       // cout <<num <<endl;
     /*   while (next_permutation(p, p+10))
        {
        //   cout <<tmp<<endl;

            tmp = calc();
            if (num!=tmp) k=0,num = gcd(num, tmp);          
            if (num == 1) break;
        }*/
        cout <<"Case "<<++ca<<":";
     //   cout <<num <<endl;
     //   long long i;
        ans = 0;
      /*  long long i;
        for (i=1; i*i<num; i++)
            if (num % i == 0) {d[ans++] = i; d[ans++] = num/i;}
        if (i*i == num) d[ans++] = i;*/
       // num = 100;
      /* cin >>num;
       for (i=1; i*i<num; i++)
            if (num % i == 0) {d[ans++] = i; d[ans++] = num/i;}
        if (i*i == num) d[ans++] = i;
        sort(d, d+ans);
                for (int j=0; j<ans; j++) cout <<" "<<d[j];
        cout <<endl;
        ans = 0;*/
       // cin >>num;
        work(num);
        make(0, 1);
        sort(d, d+ans);
        for (int j=0; j<ans; j++) cout <<" "<<d[j];
        cout <<endl;
    }
    
    system("pause");
    return 0;
}
