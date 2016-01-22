#include <stdio.h>
#include <string.h>

void reverse(char* str, int length) {
  printf("%p\n", str);  // 0x7fff508fbb50
  printf("%s\n", str);  // dar era sretniop
  printf("%c\n", *str); // d
  printf("%p\n", &str); // 0x7fff508fbb28
}

int main() {
  char phrase[] = "dar era sretniop";
  printf("%s", phrase);
  printf("Before: %s\n", phrase);
  printf("c phrase[0] = %c\n", phrase[0]);
  printf("c phrase[2] = %c\n", phrase[2]);
  printf("p phrase = %p\n", phrase);
  printf("p (phrase+1) = %p\n", (phrase+1));
  printf("p &phrase = %p\n", &phrase);
  printf("p &phrase+1 = %p\n", &phrase+1);
  //printf("c *&phrase = %c\n", *&phrase);
  printf("c *phrase = %c\n", *phrase);
  //printf("c *phrase[2] = %c\n", *phrase[2]);
  printf("c *phrase+1 = %c\n", *phrase+1);
  printf("c *phrase+2 = %c\n", *phrase+2);
  printf("p (char*)&phrase = %p\n", (char*)&phrase);
  printf("p (char*)phrase = %p\n", (char*)phrase);
  printf("s (char*)&phrase = %s\n", (char*)&phrase);
  printf("s (char*)phrase = %s\n", (char*)phrase);
  printf("c *(char*)&phrase = %c\n", *(char*)&phrase);
  printf("c *((char*)&phrase+1) = %c\n", *((char*)&phrase+1));
  //printf("&(char*)&phrase = %p\n", &(char*)&phrase);
  //reverse((char*)&phrase, strlen(phrase)); // &phrase gets the address of phrase and char* converts it to a pointer that points at that address.
  //printf("After: %s\n", phrase);
  return 0;
}
