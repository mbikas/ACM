#include<stdio.h>
#include<string.h>

#define sz 10000




char op[6]="+-*/^";
//1=+,- : 2=*,/ 3=^

int prior[5]={1,0,2,1,3};
int top=0,count=0,len,i;
char in[sz],stack[sz],post[sz],c;

int isOp(char c){
	int j;
	for(j=0;j<6;j++)
		if(c==op[j])
			return 1;
		return 0;
}
void push(char ch)
{
	stack[top++]=ch;
}

char pop()
{
	top--;
	return stack[top];
}
void postorder(void)
{
  top=0;
  //strcpy(post,"");
  count=0;
  len=strlen(in);
  in[len]=')';
  stack[top++]='(';
  for(i=0;i<len+1;i++){
    if(in[i]=='(')push(in[i]);
    else if(in[i]==')'){
      while(1){
        c=pop();if(c=='(')break;
        post[count++]=c;
      }
    }
    else if(isOp(in[i])){
      while(1){
        c=pop();
        if(( prior[c%5]>
      prior[in[i]%5]-1) && isOp(c))	  post[count++]=c;
        else{
          top++;push(in[i]);break;
        }
      }
    }
    else post[count++]=in[i];
  }
  post [count]=0;
}


int main()
{

	//freopen("infix.in","r",stdin);
	//freopen("postfix.out","w",stdout);

	int test;
	char expression[sz],a[sz];
    


	scanf("%d",&test);

	while(test--)
	{
		strcpy(in,"");
   		scanf(" %[^\n]",in);
		top=0;
		postorder();
		printf("%s\n",post);
	}
	return 0;
}
