/*
 * Author:  Troy
 * Created Time:  2012/7/22 2:06:07
 * File Name: a.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <time.h>
#include <cctype>
#include <functional>
#include <deque>
#include <iomanip>
#include <bitset>
#include <assert.h>
#include <numeric>
#include <sstream>
#include <utility>

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,b) FOR(i,0,b)
#define sf scanf
#define pf printf
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

const int N = 10;
const int mm = N*N*N*10 + N+1000;
const int mn = N * N * N + N+1000;

int U[mm+5], D[mm+5], L[mm+5], R[mm+5], C[mm+5], X[mm+5];
int H[mn+5], S[mn+5], Q[mn+5], ans[mn+5];
bool vis[mn];
//char str[mn];
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
    //cout <<"fuck" <<endl;
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
    //cout <<k <<endl;
    if (!R[0])
    {
        //for (int i=0; i<k; i++) ans[(X[Q[i]]-1)/9+1] = (X[Q[i]]-1)%9+1;
        //for (int i=1; i<=N*N; i++) printf("%d", ans[i]);
        //printf("\n");
        cout <<N <<" --- " <<endl;
        REP(i, k)
        {
            cout <<X[Q[i]] % N;
            if (i == k-1) cout <<endl;
            else cout <<" ";            
        }
        return true;               
    }
    int i,j,c,tmp=mm;
    //cout <<R[0] <<endl;
    for (i=R[0]; i; i=R[i])
        if (S[i] < tmp) tmp = S[c=i];
    
    //cout <<-1 <<endl;
    remove(c);
    for (i=D[c]; i!=c; i=D[i])
    {
        Q[k] = i;
        cout <<X[Q[k]] <<" "<<k <<endl;
        for (j=R[i]; j!=i; j=R[j]) remove(C[j]);
        //cout <<"fuck" <<endl;
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
int main()
{
    prepare(N*N+N, 6*N-2);
    FOR(i, 1, N+1)
        FOR(j, 1, N+1)
        //REP(i, N)
        //REP(j, N)
        {
            int r = (i-1) * N + j;
            Link(r, i); Link(r, N + j);
            Link(r, N*2+i+j-1); Link(r, N * 5 + i - j - 1);
        }
    //cout <<1 <<endl;
    Dance(0);
    cout <<1 <<endl;

    return 0;
}
