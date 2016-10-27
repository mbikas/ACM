#include<stdio.h>
#include<string.h>
#include<math.h>

int day, evening, night;

void Time_Count(int s, int e)
{
	int i;

	if(s>=e)
		e = 1440 + e;
	

	day = evening = night = 0;
	
	for(i=s;i<e;i++)
	{
		if(i>=480 && i<1080)
			day++;

		else if(i>=1080 && i<1320)
			evening++;
		
		else if( (i>=1320 && i<1440) || ( i>=0 && i<=480 ))
		{
			if(i==1439 && i+1!= e)
			{
				i = 0;
				e = e - 1440;
			}
			
			night++;
		}
	}
}

void main()
{
	char  a, str[10], ch;
	float A[3], B[3], C[3], D[3], E[3], total;
	
	int str_h, str_m, end_h, end_m, dumy, i, j, k, start, end;

	 A[0] = 0.10;     A[1] = 0.06;     A[2] = 0.02;
	 B[0] = 0.25;	  B[1] = 0.15;	   B[2] = 0.05;
	 C[0] = 0.53;     C[1] = 0.33;	   C[2] = 0.13;
	 D[0] = 0.87;	  D[1] = 0.47;	   D[2] = 0.17;
	 E[0] = 1.44;	  E[1] = 0.80;	   E[2] = 0.30;

	 for(;scanf("%c%c%s%c%d%c%d%c%d%c%d",&a, &ch, str, &ch, &str_h, &ch, &str_m, &ch, &end_h, &ch, &end_m)==11;)
	 {
		 scanf("%c",&ch);

		 start = str_h*60 + str_m;
		 
		 end = end_h*60 + end_m;

		 Time_Count(start, end);

		 if(a=='A')
			 total = day*A[0] + evening*A[1] + night*A[2];

		 else if(a=='B')
			 total = day*B[0] + evening*B[1] + night*B[2];

		 else if(a=='C')
			 total = day*C[0] + evening*C[1] + night*C[2];

		 else if(a=='D')
			 total = day*D[0] + evening*D[1] + night*D[2];

		 else if(a=='E')
			 total = day*E[0] + evening*E[1] + night*E[2];

		 printf("%10s%6d%6d%6d%3c%8.2f\n",str,day, evening, night, a,total);
	 }
}







