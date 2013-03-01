#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cctype>
using namespace std;

const int N = 9;
const int mm = N*N*N*(N*N*4)+N;
const int mn = N*N*N+N;

int U[mm], D[mm], L[mm], R[mm], C[mm], X[mm];
int H[mn], S[mn], Q[mn], ans[mn];
bool vis[mn];
char str[mn];
int size;
void prepare(int r, int c)
{
     for(int i=0; i<=c; i++)
     {
        S[i] = 0;
        U[i] = D[i] = i;
        L[i+1] = i;
        R[i] = i+1;             
     }
     R[size=c] = 0;
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
        for (int i=0; i<k; i++) str[(X[Q[i]]-1)/9+1] = (X[Q[i]]-1)%9+1;
        for (int i=1; i<=N*N; i++) printf("%d", str[i]);
        printf("\n");
        return true;               
     }
     int i,j,c,tmp=mm;
     for (i=R[0]; i; i=R[i])
       if (S[i] < tmp) tmp = S[c=i];
     remove(c);
     for (i=D[c]; i!=c; i=D[i])
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
     ++S[C[++size]=c];
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
void calc(int &r, int &c1, int &c2, int &c3, int &c4, int i, int j, int k)
{
     r=(i*N+j)*N+k, c1=i*N+j+1, c2=N*N+i*N+k, c3=N*N*2+j*N+k, c4=N*N*3+((i/3)*3+(j/3))*N+k;
     }
int main()
{
    int i,j,k,r,c1,c2,c3,c4;
    while (~scanf("%s", str), str[0]!='e')
    {
          prepare(mn, N*N*4);
          memset(vis, false, sizeof(vis));
          for (k=0,i=0; i<9; i++)
            for (j=0; j<9; j++,k++)
            if (isdigit(str[k]))
            {
               calc(r, c1, c2, c3, c4, i, j, str[k]-'0');
               Link(r, c1), Link(r, c2), Link(r, c3), Link(r, c4);
               vis[c2] = vis[c3] = vis[c4] = true;                                
            }
          for (i=0; i<9; ++i)
            for (j=0; j<9; ++j)
              for (k=1; k<=9; ++k)
              {
                  calc(r, c1, c2, c3, c4, i, j, k);
                  if (vis[c2] || vis[c3] || vis[c4]) continue;
                  Link(r, c1), Link(r, c2), Link(r, c3), Link(r, c4);                  
              }
          Dance(0);     
    }
    return 0;
    }
