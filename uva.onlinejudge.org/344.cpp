//Acm 344 Roman Digits
//solved by Bikas CSE SUST

#include<stdio.h>
#include<string.h>
void main()
{
char *roman[]={"i","ii","iii","iv","v","vi","vii","viii","ix","x",
				  "xi","xii","xiii","xiv","xv","xvi","xvii","xviii","xix","xx",
				  "xxi","xxii","xxiii","xxiv","xxv","xxvi","xxvii","xxviii","xxix","xxx",
				  "xxxi","xxxii","xxxiii","xxxiv","xxxv","xxxvi","xxxvii","xxxviii","xxxix","xl",
				  "xli","xlii","xliii","xliv","xlv","xlvi","xlvii","xlviii","xlix","l",
				  "li","lii","liii","liv","lv","lvi","lvii","lviii","lix","lx",
				  "lxi","lxii","lxiii","lxiv","lxv","lxvi","lxvii","lxviii","lxix","lxx",
				  "lxxi","lxxii","lxxiii","lxxiv","lxxv","lxxvi","lxxvii","lxxviii","lxxix","lxxx",
				  "lxxxi","lxxxii","lxxxiii","lxxxiv","lxxxv","lxxxvi","lxxxvii","lxxxviii","lxxxix","xc",
				  "xci","xcii","xciii","xciv","xcv","xcvi","xcvii","xcviii","xcix","c"
					};

char output[]={'i','v','x','l','c'};
int i,j,n,ans[5],length;
while(scanf("%d",&n)==1&&n!=0)
{
  for(i=0;i<5;i++)
	ans[i]=0;

  for(i=0;i<n;i++)
	{ length=strlen(roman[i]);

	for(j=0;j<length;j++)
	  {
	 if(roman[i][j]=='i')
	  ans[0]++;
	 else if(roman[i][j]=='v')
	  ans[1]++;
	 else if(roman[i][j]=='x')
	  ans[2]++;
	 else if(roman[i][j]=='l')
	  ans[3]++;
	 else if(roman[i][j]=='c')
	  ans[4]++;


	}//inner for
  } //for


  printf("%d: ",n);
  for(i=0;i<5;i++)
	 { printf("%d ",ans[i]);
		printf("%c",output[i]);
		if(i!=4)
		printf(", ");
	 }
	printf("\n");










 }




 }//main
