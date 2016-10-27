#include<stdio.h>
#include<math.h>

void main()
{

	//freopen("362.in","r",stdin);
	//freopen("362.out","w",stdout);

	long time,p,byte,sum,ct=1,byte1,x,rem,remainBytes;

	while(scanf("%ld",&byte)==1 && byte !=0)
	{
		byte1 = byte;
		x = 0;

		printf("Output for data set %ld, %ld bytes:\n",ct,byte);
		
		sum = 0;
		time =0;
		while(x < byte)
		{
	
			scanf("%ld",&p);
			sum = sum + p;
			x +=p;			
			time++;

			if(time%5 == 0 && time!=0)
			{

				remainBytes = byte1 - sum;
				rem = (long) ceil(remainBytes / ((double)sum / 5));

				if(sum==0)
					printf("   Time remaining: stalled\n");
				else
					printf("   Time remaining: %ld seconds\n",rem);

				byte1 = byte1 - sum;
				sum =0;

				
						
			}
		
		
		}//inner while

		printf("Total time: %ld seconds\n\n",time);
		
		ct++;
	
	
	
	}

}
