#include<stdio.h>

void main()
{
	long ncows,ncars,nshow;
	double ans;

	while(scanf("%ld %ld %ld",&ncows,&ncars,&nshow)==3)
	{
		if((ncows+ncars-nshow-1)==0)ans = 0.0;
		else
		ans = ((1.0*(ncows*ncars+ncars*(ncars-1))/(ncows+ncars-nshow-1))/(ncows+ncars));
	
		printf("%.5lf\n",ans);
	
	}

}