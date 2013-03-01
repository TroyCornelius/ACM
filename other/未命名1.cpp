8;
	   int i=0;
	   int sum;
	   int l;
	   while((H=getchar())!='\n')
	   {  a[i]=H-'0';
	     		if(!getdata(l))
			continue;
		else i++;
	   }
	   i=0;
        while((H=getchar())!='\n')
	   {  b[i]=H-'0';
	      		if(!getdata(l))
			continue;
		else i++;
	   }
		
      for(i=0;i<8;i++)
	  sum*=a[i];
	  sum++;

	  for(i=0;i<8;i++)
		  if(sum%a[i]!=b[i])
		  {sum++;i=-1;}
		  printf("%d",sum);
}
     getdata(int a)
	 {   int i=2,n=1;
	      while(i<a)
		  {if(a%i==0){n=0;break;}
		  else i++;
		  }
		  return n;
	 }
