
#include<stdio.h>
int main()
{
	long int ara[7], dumy, total_p;

	for( ; scanf("%ld%ld%ld%ld%ld%ld",&ara[1],&ara[2],&ara[3],&ara[4],&ara[5],&ara[6])==6 ; )
	{
		if(ara[1] ==0 && ara[2]==0 && ara[3]==0 && ara[4]==0 && ara[5]==0 && ara[6]==0)	break;

		total_p = 0;

	    total_p = ara[6] + ara[5] + ara[4] + ara[3]/4 ;

			ara[3] = ara[3]%4 ;
			
			dumy = ara[5] *11;

			if(ara[1]<dumy)	ara[1] = 0;

			else 
				ara[1] = ara[1] - dumy;

		    dumy = ara[4] *5;

			if(ara[2]<dumy)
			{
				dumy = ( dumy - ara[2] )*4;
					
				ara[2] = 0;

				if(ara[1]>0 && ara[1]<=dumy)	ara[1] = 0;

				else ara[1] = ara[1] - dumy;
			}

			else ara[2] = ara[2] - dumy ;

			if(ara[3]!=0 )
			{
				total_p = total_p + 1;

				if(ara[2]>0 && ara[3]==1)
				{
					ara[2] = ara[2] - 5 ;

				    if(ara[1]>0)  ara[1] = ara[1] - 7 ;
				}

				else if(ara[2]>0 && ara[3]==2)
				{
					ara[2] = ara[2] - 3 ;

				    if(ara[1]>0)  ara[1] = ara[1] - 6 ;
				}

				else if(ara[2]>0 && ara[3]==3)
				{
					ara[2] = ara[2] - 1 ;

				    if(ara[1]>0)  ara[1] = ara[1] - 5 ;
				}
			}

			if(ara[2]>0) 
			{
				if(ara[2]>=9)
				{
					total_p = total_p + ara[2]/9 ;

				   ara[2] = ara[2]%9;
				}
				
				else 
				{
					total_p = total_p + 1;

					dumy = 36 - ara[2]*4;

					ara[2] = 0;

					if(ara[1]<=dumy && ara[1]>0)	ara[1] = 0;

					else if(ara[1]>0 && ara[1]>dumy)	ara[1] = ara[1] - dumy;
				}
			}

			if(ara[2]>0)
			{
				total_p = total_p+1;

				dumy = (9 - ara[2])*4;

				ara[2] = 0;

				if(ara[1]>0)	ara[1] = ara[1] - dumy;
			}

			if(ara[1]>0)
			{
				if(ara[1]>=36)
				{
					total_p = total_p + ara[1]/36;

					ara[1] = ara[1]%36;
				}

				else
				{
					total_p = total_p + 1;
					ara[1] = 0;
				}
			}
			
			if(ara[1]>0)	total_p = total_p + 1;

			printf("%ld\n",total_p);
	}
	return 0;
}
