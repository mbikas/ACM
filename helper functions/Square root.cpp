#include<stdio.h>
#include<string.h>
//#include <time.h>


int rev(char a[]){
     int i,l,k,len;
	 char b;
     len=l=strlen(a);
     k=l/2;
     for(i=0,l--;i<k;i++,l--){
		 b=a[i];
		 a[i]=a[l];
		 a[l]=b;
	 }
	 return len;
}

int compare(char a[],char b[]){			//reverse compare
	int l1=strlen(a);
	int l2=strlen(b);
	if(l1>l2)
		return 1;
	else if(l1<l2)
		return 0;
	else{
		l1--;
		while(l1>=0)
		{
			if(b[l1]>a[l1])
				return 0;
			else if(a[l1]>b[l1])
				return 1;
			l1--;
		}
		return 1;
	}
}

void sub(char a[],char b[],char res[])
{
	int i,k,sign;

	sign=compare(a,b);			//positive means plus		//negative means minus

	if(sign==0){
		strcpy(res,a);
		strcpy(a,b);
		strcpy(b,res);
		sign =-1;
	}

	//rev(a);
	//rev(b);

	for(i=0;b[i];i++)
	{
		if(b[i]>a[i])
		{
			a[i]+=10;
			k=i+1;
			while(1)
			{
				if(a[k]>0)
				{
					a[k]--;
					break;
				}
				a[k++]='9';
			}
		}
		res[i]=a[i]-b[i]+48;
	}
	k=i;
	for(;a[i];i++){
		res[i]=a[i];
		if(a[i]>'0')
			k=0;
	}
	if(k)
		i=k;
	for(i;i>0;i--)
		if(res[i-1]>'0')
			break;
	if(sign<0)
		res[i++]='-';
	res[i]=0;
	//rev(res);
	//rev(b);
}

void add(char a[],char b[]){
	int i,c=0,r,l=0;
	//len=rev(a);
	//rev(b);
	for(i=0;b[i];i++){
		r=a[i]+b[i]-96+c;
		c=r/10;
		a[i]=(r%10+48);
	}
	while(c){		
		if(a[i]==0||l){
			a[i]='0';
			l=1;
		}
		r=a[i]+c-48;
		c=r/10;	   
		a[i++]=(r%10+48);		
	}
	if(l)
		a[i]=0;
	//rev(a);
	//return len;
}

void trim(char a[],int l){
	
	for(l;l>0;l--)
		if(a[l]>'0')
			break;
	a[l+1]=0;
	//rev(a);
}


void main()
{
	char a[1500],res[1500],rem[1500],ans[1500],odd[1500];
	long count,l,len,t,i,j;

	//clock_t start, finish;
   //double  duration;

	//freopen("input.txt","r",stdin);
	//freopen("out.txtb","w",stdout);
	//start = clock();
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%s",a);
		l=rev(a);
		if(l%2==1){
			l--;
			strcpy(rem,a+l);
			//a[l]=0;			
		}
		else{
			l-=2;
			strcpy(rem,a+l);
			//a[l]=0;			
		}			
		ans[0]=0;
		odd[0]='1';
		odd[1]=0;
		len=0;
		//memset(odd+1,'0',sizeof(char)*1100);
		while(l>=0){
			count=0;
			while(compare(rem,odd)){
				count++;
				sub(rem,odd,res);
				strcpy(rem,res);
				add(odd,"2");
			}
			for(i=++len;i>0;i--)
				ans[i]=ans[i-1];
			ans[0]=count+48;
			//sprintf(ans,"%s0",ans);
			//sprintf(res,"%ld",count);
			//add(ans,res);
			if(l==0)
				break;
			odd[len+1]=0;
			res[len+1]=0;
			for(i=len;i>0;i--){
				odd[i]=ans[i-1];
				res[i]=odd[i];
			}
			odd[0]='0';
			res[0]='0';
			//sprintf(odd,"0%s",ans);
			//strcpy(res,odd);
			add(odd,res);
			add(odd,"1");
			j=i=strlen(rem)+2;
			for(;i>1;i--)
				rem[i]=rem[i-2];
			rem[1]=a[--l];
			rem[0]=a[--l];
			//sprintf(rem,"%s%s",a+l,rem);
			//l+=2;
			trim(rem,j);
		}
		rev(ans);
		printf("%s\n",ans);
		if(t)
			printf("\n");
	}
	//finish = clock();
   //duration = (double)(finish - start) / CLOCKS_PER_SEC;
   //printf( "%lf seconds\n", duration );

}


