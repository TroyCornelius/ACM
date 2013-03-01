int main()
{
	init();
	int n,m,l;
    while(scanf("%d%d%d",&n,&m,&l)!=EOF) {
        for(int i=1;i<=n;i++) {
            double p,t,v;
            scanf("%lf%lf%lf",&p,&t,&v);
            for(int j=0;j<=m;j++) {
                man[i].t[j]=l/v+t*j;
                man[i].p[j]=power(1-p/100,(m-j))*power((p/100),j)*C[m][j];
            }
        }
        for(int i=1;i<=n;i++) {
            double ans=0;
            for(int ci=0;ci<=m;ci++) {
                double pp=man[i].p[ci];
                for(int j=1;j<=n;j++)
                {
                    if(i==j)
						continue;
					double ppp=0;
					for(int k=0;k<=m;k++)
						if(man[i].t[ci]<man[j].t[k])
							ppp+=man[j].p[k];
					pp*=ppp;
				}
				ans+=pp;
			}
			printf("%.8lf\n",ans);
		}
	}
} 
