# Password

This example demonstrates the use of an integer as a boolean flag where 0 is false and anything else is considered to be true.

````c
void *data = malloc(4 + sizeof(int));
 //allocate memory for 4 bytes and an integer.
int *pass = data+4;
*pass = 0;
````

The above code is fairly interesting. What I wanted to do was actually:

````c
char *buffer = malloc(4);
int pass = 0;
````

Compiling with gcc and testing the code however resulted in some or other system reporting "Stack Trashing" and killing the process.
The first example solves the aforementioned problem.

The code in this example is a lot like the code in ``4_digit_password`` but uses a little more complex technique.

Before entering data the memory layout is:
````
....0000
````
After entering some scaly data the memory layout is:
````
abcde000
````
Note that password now points to the hex value ``0xe000`` which is not zero (false) and thus evaluates to true.
