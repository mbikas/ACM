#include<stdio.h>

void main()
{
	long step,mod,value,i;
	int good;

	while(scanf(" %ld %ld",&step,&mod)==2)
	{
		value=0;
		good=1;

		for(i=1;i<mod;i++)
        {		
			value=(value+step)%mod;
			if(value==0)
			{	good=0;
				break;
			}
		}

		if(good==1)
			printf("%10ld%10ld    Good Choice\n\n",step,mod);
		else
			printf("%10ld%10ld    Bad Choice\n\n",step,mod);

	}

}
