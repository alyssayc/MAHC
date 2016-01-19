#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void increment(int *p){
	*p += 1;
}

int a; // its scope is the entire program
int main(){
	char str[100001];
	
	
	/*
	int i; // its scope is in the function main()
	for (i = 0; i < 10; i++){
		int b; //its scope is in the block (for loop)
	}
	return 0;
	*/
	/*
	int x = 0;
	printf("%d\n", x); // prints 0
	increment(&x); // increases the value of x by 1
	printf("%d\n", x); // prints 1
	return 0;
	*/
	/*
	int arr[10];
	arr[5] = 1;
	printf("%d\n", arr[5]); // prints 1
	printf("%d\n", *(arr+5)); // prints 1
	
	arr[5] = 6179;
	printf("%d\n", arr[5]); // prints 6179
	printf("%d\n", *(arr+5)); // prints 6179
	*/
	/*
	int x = 0; //init an int called x
	printf("%d\n", x); //Print the decimal number x
	int *p; //init a pointer that is of type integer
	p = &x; // so now p points at the address of x
	
	// dereferencing 
	*p = 1; // sets the value of the integer stored at p to 1
	printf("%d\n", x); //Print the decimal number x
	*/
	/*
	int x;
	int *p;
	p = &x;
		
	// p stores the byte number at which x's allocated memory starts
	printf("%p\n", p);
	int *q;
	q = p + 1;
	printf("%p\n", q);
	*/
	/*	
	int arr[10];

	// arr is a pointer
	printf("%p\n", arr);

	// points to the first element 
	arr[1] = 2;
	printf("%d\n", *arr); // It will always point towards the first element
	arr[2] = 5;
	printf("%d\n", *arr);
	*/

}
