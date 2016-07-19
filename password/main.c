#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
     void *data = malloc(4 + sizeof(int)); //allocate memory for 4 bytes and an integer.
     int *pass = data+4;
     *pass = 0;

     puts("Enter the password: ");
     gets(data);

     if(strcmp(data,"abcd")==0)
          *pass = 1;

     if(*pass)
          puts("Correct password");
     else
          puts("Incorrect password");
     return 0;
}
