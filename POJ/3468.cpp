#include <iostream>
#include <cstdio>
#include <cstring>
#define Maxn 100050
using namespace std;

class bit_tree
{
      public:
      long long b[Maxn], c[Maxn];
      int n;
      bit_tree(int a){n = a+2;memset(b,0,sizeof(b));memset(c,0,sizeof(c));}
      int lowbit(int x){return x&(-x);}
      void insert1(int idx, long long val)
      {
           for (;idx && idx<=n; idx+=lowbit(idx)) b[idx]+=val;           
      }
      void insert2(int idx, long long val)
      {
           for (; idx; idx-=lowbit(idx)) c[idx]+=val;
      }
      long long query1(int idx)
      {
          long long s = 0;
          for (;idx;idx-=lowbit(idx)) s+=b[idx];
          return s;          
      }
      long long query2(int idx)
      {
          long long s = 0;
          for (;idx<=n; idx+=lowbit(idx)) s+=c[idx];
          return s;          
      }
      void _insert(int p, long long val)
      {
           insert1(p, p*val);
           insert2(p-1, val);           
      }
      long long _query(int p)
      {
          return query1(p) + query2(p) * p;    
      }
      void insert_seg(int l, int r, long long val)
      {
           _insert(r, val);
           _insert(l-1, -val); 
      }
      long long find_sum(int l, int r)
      {
          return _query(r) - _query(l-1);       
      }      
      };
int n, m;
int main()
{
    ios::sync_with_stdio(false);
    cin >>n >>m;
    long long num, v;
    int t1, t2; 
    char op;
    bit_tree t(n);
    for (int i=1; i<=n; i++)
    {
        cin >>num;   
        t.insert_seg(i+2,i+2,num);
    }
    for (int i=0; i<m; i++)
    {
        cin >>op >>t1 >>t2;
        t1+=2; t2+=2;
        if (op == 'Q') 
        {
           cout <<t.find_sum(t1, t2) <<endl;
        }
        else
        {
           cin >>v;
           t.insert_seg(t1, t2, v);   
        }
    }
    return 0;
    } 
