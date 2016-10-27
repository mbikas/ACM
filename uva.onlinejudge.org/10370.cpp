//Acm 10370 Above Avarage
//solved by Bikas CSE SUST
#include<stdio.h>
#define size 1000

void main()
{  int testCase,student,i;
	float avarage,grade,p,grades[size];

	scanf("%d",&testCase);

	while(testCase>0){

	  p=0;
	  avarage=0.0;
	  scanf("%d",&student);

	  for(i=0;i<student;i++)
	  {
		scanf("%f",&grade);
		avarage+= grade;
		grades[i]=grade;
	  }

	  avarage=avarage/student;

	  for(i=0;i<student;i++)
	  {
		 if(grades[i]>avarage)
		  p++;
	  }

	 avarage=(p/student)*100;

	 printf("%.3f%\n",avarage);




	  testCase--;
	}
 }
