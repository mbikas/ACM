#include <stdio.h> 
#include <ctype.h> 
#include <string.h> 

void main() 
{ 
//   #ifndef ONLINE_JUDGE 
//   #endif    

   char xl[1002], yl[1002]; 

   char x[1002][20]; 
   char y[1002][20]; 
   int c[200][200] = {0}; 

   int i, j, count = 0; 
    
   while (gets(xl) && gets(yl)) { 
      count++; 

      printf("%2d. ", count); 
      if (strlen(xl) == 0 || strlen(yl) == 0) { 
         printf("Blank!\n"); 
         continue; 
      } 

      char *ch; 
      for (ch = xl; *ch; ch++) 
         if (!isalnum(*ch)) 
            *ch = ' '; 

      for (ch = yl; *ch; ch++) 
         if (!isalnum(*ch)) 
            *ch = ' '; 

      i = 1; 
      char *tok; 
      for (tok = strtok(xl, " "); tok; tok = strtok(NULL, " "), i++) 
         strcpy(x[i], tok); 

      int m = i - 1; 

      j = 1; 
      for (tok = strtok(yl, " "); tok; tok = strtok(NULL, " "), j++) 
         strcpy(y[j], tok); 

      int n = j - 1; 

      for (i = 1; i <= m; i++) 
         for (j = 1; j <= n; j++) 
            if (strcmp(x[i], y[j]) == 0) 
               c[i][j] = c[i - 1][j - 1] + 1; 
            else 
               if (c[i - 1][j] >= c[i][j - 1]) 
                  c[i][j] = c[i - 1][j]; 
               else 
                  c[i][j] = c[i][j - 1]; 

      printf("Length of longest match: %d\n", c[m][n]); 

   } 

    
} 
