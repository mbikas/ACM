#include<stdio.h> 
#include<ctype.h> 
#include<string.h> 
#include<stdlib.h> 

struct TREE{ 
   int count; 
   char *alpha; 
   struct TREE *left,*right; 
}; 

int judgeanswer; /* judge if there is no answer */ 

void getstring(char*); 
void inorder(struct TREE *node,int num); 

int main() 
{    

	//freopen("10126.in","r",stdin);
	//freopen("10126.out","w",stdout);


   char letter[200]; 
   int num; 
   struct TREE *root,*ptr; 
   int nl=0; 

   while(scanf("%d",&num)!=EOF){ 
      judgeanswer=0; 

      root=(struct TREE *)malloc(sizeof(struct TREE)); 
      root->left=root->right=NULL; 
      getstring(letter); 
      root->alpha=(char *)malloc(strlen(letter)+1); 
      strcpy(root->alpha,letter); 
      root->count=1; 
       
      if(strcmp(letter,"endoftext")) { 
         while(1){ 
            getstring(letter); 
            if(!strcmp(letter,"endoftext")) break; 
             
            ptr=root;          
            while(1){ 
               if(!strcmp(letter,ptr->alpha)){ 
                  ptr->count++;                      
                  break; 
               } 
               else if(strcmp(letter,ptr->alpha)>0){ 
                  if(ptr->right==NULL){                         
                     ptr->right=(struct TREE*)malloc(sizeof(struct TREE)); 
                     ptr=ptr->right; 
                     ptr->left=ptr->right=NULL; 
                     ptr->alpha=(char *)malloc(strlen(letter)+1);                         
                     strcpy(ptr->alpha,letter); 
                     ptr->count=1;                         
                     break; 
                  } 
                  else 
                     ptr=ptr->right;                
               } 
               else { 
                  if(ptr->left==NULL){ 
                     ptr->left=(struct TREE*)malloc(sizeof(struct TREE)); 
                     ptr=ptr->left;                         
                     ptr->left=ptr->right=NULL; 
                     ptr->alpha=(char *)malloc(strlen(letter)+1); 
                     strcpy(ptr->alpha,letter); 
                     ptr->count=1;                         
                     break;                         
                  } 
                  else 
                     ptr=ptr->left;                   
               }/* end of else */ 
            }/* end of while(1) */             
         }/* end of while(1) */
		 if(nl) printf("\n"); 
         else nl=1;
         inorder(root,num); 
      }/* end of if(strcmp(letter,"endoftext")) */ 
       
      if(!judgeanswer) printf("There is no such word.\n"); 
       
   }/* end of "while(scanf("%d",&num)!=EOF)" */ 
   return 0; 
} 

void getstring(char* letter){ 
   char ch;    
   int i=0,state=0; 

   while((ch=getchar())!=EOF){ 
      if(isalpha(ch)) { 
         ch=tolower(ch); 
         letter[i++]=ch; 
         state=1; 
      } 
      else if(state==1) 
         break; 
   } 
   letter[i]='\0';    
} 

void inorder(struct TREE *node,int num){ 
   if(node!=NULL){ 
      inorder(node->left,num); 
      if(node->count==num) { 
         printf("%s\n",node->alpha);    
         judgeanswer=1; 
      } 
      inorder(node->right,num);          
   } 
} 
