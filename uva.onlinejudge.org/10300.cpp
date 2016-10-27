 //Acm 10300 Ecological Premium
 //solved by Bikas CSE SUST

 #include<stdio.h>

 void main()
 {
  int testCase,i,j,k,n,sum;

	scanf("%d",&testCase);
  while(testCase>0){

	scanf("%d",&n);

	sum=0;
	while(n>0)
	 {
		scanf("%d %d %d",&i,&j,&k);
		sum=sum+(i*k);




	  n--;
	 }


	printf("%d\n",sum);



  testCase--;
 }
}
