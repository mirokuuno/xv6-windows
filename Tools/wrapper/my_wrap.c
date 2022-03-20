/* my_wrap.c

   This program shows the parameters that are passed to subprograms when gcc executes them.
   Usage: gcc -wrapper my_wrap.exe -ggdb -o sign.exe sign.c
   
   by Hiroshi Uno */

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
	printf("==================================\n");

	int i;
	for (i=0; i<argc; i++)
	{
		printf("[%02d] %s\n", i, argv[i]);
	}
	printf("==================================\n");

    return 0;
}