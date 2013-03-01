#include<stdio.h>
#include<string.h>
#include<map>
#include<vector>
#include<set>
#include<math.h>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
struct node{
    int a,b;
}data[100010];
bool cmp(const node &a,const node &b){
    return a.a+a.b<b.a+b.b;
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d%d",&data[i].a,&data[i].b);
        }
        sort(data,data+n,cmp);
        long long ans=0;
        long long cur=0;
        for(int i=0;i<n;i++){
            ans=max(ans,cur-data[i].b);
            cur+=data[i].a;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}