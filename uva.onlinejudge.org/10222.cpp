//Acm 10222 Decode Mad Man
//solved by Bikas CSE SUST

#include<stdio.h>
void main()
{
 int i;
 char a[]={'q','w','q','w','e','r','t','y','u','i','o','p','[',']'};
 char b[]={'a','s','a','s','d','f','g','h','j','k','l',';','\''};
 char c[]={'z','x','z','x','c','v','b','n','m',',','.','/'};
 char d[]={'`','1','`','1','2','3','4','5','6','7','8','9','0','-','=','\\'};
 char e[]={'Q','W','Q','W','E','R','T','Y','U','I','O','P','{','}'};
 char f[]={'A','S','A','S','D','F','G','H','J','K','L',':','\"'};
 char g[]={'Z','X','Z','X','C','V','B','N','M','<','>','?'};
 char ch;


 while((ch=getchar())!='\n'){

	 if(ch==' ')
		 printf(" ");
	 else{

		 for(i=2;i<=15;i++){

			 if(ch==a[i])
				{ printf("%c",a[i-2]);
				  break;
				}
			 else if(ch==b[i])
				{ printf("%c",b[i-2]);
				  break;
				}
			 else if(ch==c[i])
				{ printf("%c",c[i-2]);
				  break;
				}

			 else if(ch==d[i])
				{ printf("%c",d[i-2]);
				  break;
				}

			 else if(ch==e[i])
				{ printf("%c",e[i-2]);
				  break;
				}
			 else if(ch==f[i])
				{ printf("%c",f[i-2]);
				  break;
				}
			 else if(ch==g[i])
				{ printf("%c",g[i-2]);
				  break;
				}

		 } //end of for

	  }//end of else

	}//end of while
 }



