#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define MaxD 5
#define pb push_back
#define fi first
#define se second
#define mp make_pair
using namespace std;

const int N = 60;
const int mn = N*16+N;
const int mm = N*MaxD+N+N;

int U[mm], D[mm], L[mm], R[mm], X[mm], C[mm];
int H[mn], S[mn], Q[mn];
int size, cnt;
int n, m, k;
vector<int>g[64];
pair<int,int> work[64], sta[16];
void prepare(int r, int c)
{
     for (int i=0; i<=c; i++)
     {
         S[i] = 0;
         U[i] = D[i] = i;
         L[i+1] = i;
         R[i] = i+1;         
     }
     R[size = c] = 0;
     while (r) H[r--] = -1;     
     }
void remove(int c)
{
     L[R[c]] = L[c], R[L[c]] = R[c];
     for (int i=D[c]; i!=c; i=D[i])
       for (int j=R[i]; j!=i; j=R[j])
         U[D[j]] = U[j], D[U[j]] = D[j], --S[C[j]];     
     }
void resume(int c)
{
     for (int i=U[c]; i!=c; i=U[i])
       for (int j=L[i]; j!=i; j=L[j])
         ++S[C[U[D[j]] = D[U[j]] = j]];
     L[R[c]] = R[L[c]] = c;
     }
bool Dance(int k)
{
     if (!R[0])
     {
        return true;               
     }
     int i, j, c, tmp=mm;
     for (i=R[0]; i; i=R[i])
       if (S[i] < tmp) tmp = S[c=i];
     remove(c);
     for (i=D[i]; i!=c; i=D[i])
     {
         Q[k] = i;
         for (j=R[i]; j!=i; j=R[j]) remove(C[j]);
         if (Dance(k+1)) return true;
         for (j=L[i]; j!=i; j=L[j]) resume(C[j]);    
     }
     resume(c);
     return false;
     }
void Link(int r, int c)
{
     ++S[C[++size] = c];
     X[size] = r;
     D[size] = D[c];
     U[D[c]] = size;
     U[size] = c;
     D[c] = size;
     if (H[r] < 0) H[r] = L[size] = R[size] = size;
     else
     {
         R[size] = R[H[r]];
         L[R[H[r]]] = size;
         L[size] = H[r];
         R[H[r]] = size;         
     }
     }
void init(int days)
{
     cnt = 1;
     for (int i=1; i<=days; i++)
       for (int j=i; j<=days; j++)
         sta[cnt++] = mp(i, j);
     sta[0] = mp(0, 0);
     }
int main()
{
    int a, b, id, r, c;
    init();
    while (~scanf("%d%d%d", &n, &m, &k))
    {
          init(k);
          prepare(n*16, n*k+n);
          for (int i=0; i<=n; i++) g[i].clear();
          for (int i=0; i<m; i++)
          {
              scanf("%d%d", &a, &b);
              g[a].pb(b);
              g[b].pb(a);      
          }
          for (int i=0; i<n; i++)
          {
              scanf("%d%d", &a, &b);
              work[i] = mp(a, b);              
          }     
          
          for (int i=1; i<=n; i++)
          {
              for (int j=0; j<cnt; j++)
              {
                  r = (i-1)*cnt + j;
                  for (int p=g[i]; p<g[i].size(); p++)
                  {
                      id = g[i][p];
                      for (int t=sta[j].first; t<=sta[j].en; t++)
                      {
                          
                          
                      }                      
                      
                      
                  }
                  
              }
              
          }      
          
          
    }
    
    
    
    return 0;
    }
