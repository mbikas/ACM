#include <stdio.h> 

int main() 
{ 
 char maze = 0, temp = 0; 
 int n = 0, i = 0; 

 while ( scanf( "%c", &maze ) == 1 ) 
 { 
    if ( maze == '\n' && temp == '\n' ) 
    {  printf("\n"); n = 0; temp = 0; maze = 0; 
    } 
    else 
    {  if ( maze >= '0' && maze <= '9' ) 
          n += maze - 48; 
       else if ( maze == '!' ) 
          printf("\n"); 
       else if ( maze == 'b' ) 
       {  for ( i = 0; i < n; i++ ) 
             printf(" "); 
          n = 0; 
       } 
       else if ( ( maze >= 'A' && maze <= 'Z' ) || maze == '*' ) 
       {  for ( i = 0; i < n; i++ ) 
             printf("%c", maze); 
          n = 0; 
       } 
       else 
          printf( "%c", maze ); 
       temp = maze; 
    } 
 } 

 return 0; 
}