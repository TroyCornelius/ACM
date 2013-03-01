#include<stdio.h> 
#include<string.h> 
#include<iostream> 
#define M 100005 
int cnt[M], now[M]; 
int num[M], place[M];  
struct node {
    int flag;
    int L, R;
} tree[M * 3];
int query(int x, int p)
{     if (tree[p].flag)return 1;
    int mid = (tree[p].L + tree[p].R) >> 1;
    if (tree[p].L == tree[p].R) 
    {         
        return tree[p].flag;
    }  
    if (x <= mid)query(x, 2 * p);   
    else query(x, 2 * p + 1); 
}  void add(int L, int R, int p) 
{
    if (tree[p].flag)return;     
    if (L == tree[p].L && R == tree[p].R)
    {    
        tree[p].flag = 1;        
        return;  
    }   
  
    int mid = (tree[p].L + tree[p].R) >> 1;   
    if (R <= mid)add(L, R, 2 * p);   
    else if (L > mid)add(L, R, 2 * p + 1);  
    else 
    {        
        add(L, mid, 2 * p);      
        add(mid + 1, R, 2 * p + 1);   
    }
}  
void build(int L, int R, int p) 
{     
    tree[p].L = L, tree[p].R = R;     
    tree[p].flag = 0;    
    if (L == R)return;     
    int mid = (L + R) >> 1;    
    build(L, mid, 2 * p);    
    build(mid + 1, R, 2 * p + 1); 
}  
int main()
{    
    int cas, S, N;  
    int i, j;   
    scanf("%d", &cas);  
    while (cas-- && scanf("%d %d", &S, &N))
    {        
        for (i = 1; i <= N; i++) scanf("%d", &num[i]);       
        for (i = 1; i <= S; i++)place[i] = -1;  
        build(1, S, 1);    
        for (i = 1; i <= N; i++)
        {        
            if (place[num[i]] == -1) place[num[i]] = i;    
            else 
            {      
                int L = place[num[i]];      
                int R = i;               
                place[num[i]] = i;        
                if (R - L >= S)continue;     
                L = (L - 1) % S + 1;       
                R = (R - 1) % S + 1;        
                if (L > R)add(R, L - 1, 1);     
                else
                {      
                    if (L > 1)add(1, L - 1, 1);        
                    if (R <= S)add(R, S, 1);   
                }       
            }       
        }       
        int ans = 0;   
        for (i = 1; i <= S; i++) 
        {      
            if (query(i, 1) == 0)ans++;   
        }      
        printf("%d\n", ans);   
    }    
    return 0;
}
