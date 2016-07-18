# 4_digit_password:

This example shows why the gets() function is dangerous and shouldn't be used.
The following code is used to create a vulnerable buffer:
````c
char *veryBadBuffer = malloc(9); //Note the 9, 1 extra byte for the null terminator.
char *buffer = veryBadBuffer;
char *pass = buffer + 4;
````

Another option was:
````c
char *buffer = malloc(4);
char *pass = malloc(5); //Once again for the null terminator
````
But the above assumes that the compiler place buffer and pass next to one another.


Compile with:
````bash
clang main.c -o 4_digit_password
````

Note that the actual password is ````abcd```` ; The attack vector is quite simple in that<br>the ````gets```` function does not do bound checking. It writes 10 bytes of input if the user <br>provides 10 bytes of input.

The actual attack works as follows:

Before the user inputs data the memory layout is as follows.

````
....abcd\0
````

If the user were to input ````word```` the layout would be:

````
wordabcd\0
````

Note that the code compares 4 characters from buffer to 4 characters from pass.
We can abuse this by entering ````12341234````. in effect the 4 bytes ````abcd```` is overwritten with the last 4 bytes from the buffer ````1234````. Because the first and last four bytes of buffer are the exact same the conditional evaluates to true.

The layout is now:

````
12341234\0
````

When the code evaluates the 4 digits we find that `1234` is in fact equal to `1234`!
