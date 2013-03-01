#include<cstdio>
#include<cstring>
char a[1000005];
int t1,t2,l,r,n,res,len;
int b[500];
int main(){
    while(scanf("%d",&n) && n){
        memset(b,0,sizeof(b));
        getchar();
        gets(a);
        len=strlen(a);
        t1=t2=res=0;
        l=r=0;
        while(l<=r && r<len)
        {
            //printf("%d %d %d\n",l,r,t2);
            while(t1<=n && r<len)
            {
                if(b[ a[r] ]==0) 
                {
                    b[ a[r] ]=1; t1++;
                    if(t1>n) 
                    {
                        //b[ a[r] ]=0;
                        break;
                    }
                }else
                {
                    b[ a[r] ]++;
                }
                r++; t2++;
            }
            if(t2>res) res=t2;
            

            if(r>=len) break;
            while(1){
                b[ a[l] ]--;
                if(b[ a[l] ]==0) break;
                l++; t2--;        
            }
            //printf("l= %d\n",l);
            l++; t1--; r++;
        }
        printf("%d\n",res);
    }
    return 0;
}
