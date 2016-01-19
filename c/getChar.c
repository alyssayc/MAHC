#include <stdio.h>

int main ()
{
   char c;
   char* line;
   for (int i = 0; i < 2; i++){
   printf("Enter character: ");
   c = getchar();
 
   printf("Character entered: %c\n", c);
   scanf("%s", line);
   c = getchar();
   printf("The rest of the line is: %s\n", line);  
   }
   return(0);
}
