#include <stdio.h>
#include <math.h>
#include <complex.h>

int checkMandelbrot(int a, int b, int N, int M);

int main(){
   int N, M;
   scanf("%d %d", &N, &M);
   for (int i = 0; i < M; i++){ //iterate through the rows (b)
      for (int j = 0; j < N; j++){ //iterate through the columns (a)
         if (checkMandelbrot(j, i, N, M) == 1){
            printf("*");
         } else {
            printf(" ");
         }
      }
      printf("\n");
   }
}

int checkMandelbrot(int a, int b, int N, int M){
   _Complex double c = ((double) a/N * 3.5 - 2.5) + ((double) b/M -.5) * 2 * I; //The complex number associated to (a,b)
   _Complex double z = 0;
   for (int i = 0; i < 500; i++){

      /*_Complex double z_next = cpow(z, 2.0); 
      z = z_next + c;*/

      z = z*z + c; // This has alot less errors than using pow(cpow) because pow uses logarithms etc. 
      
      if (cabs(z) > 2){ // This does exit the loop early.
         return(0);
      }

      //printf("When i = %d, z = ", i);
      //printf("%.2f +%.2fi \n", creal(z), cimag(z));
   }
   if (cabs(z) <= 2){
      return(1);
   } else {
      return(0);
   }
}
