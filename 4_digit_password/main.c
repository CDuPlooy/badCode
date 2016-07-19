#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(){
      char *veryBadBuffer = malloc(9);
      char *buffer = veryBadBuffer;
      char *pass = buffer + 4;
      strcpy(pass,"abcd");

      puts("Enter the 4 digit password : ");
      gets(buffer);


      size_t i , correct = 0;
      for(i = 0 ; i < 4; i++)
            if(pass[i]==buffer[i])
                  correct++;

      if(correct == 4)
            puts("You got the password!");
      else
            puts("Incorrect password!");

      free(buffer); //free even in bad code ;)
      return 0;
}
