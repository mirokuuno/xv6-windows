/* Sign.c

   This program writes the boot signature (0x55 and 0xaa) to the specified file.
   Usage: 	sign bootblock

   by Hiroshi Uno */

#include <stdio.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stdlib.h>


void error(char *fmt, ...);

int main (int argc, char *argv[])
{
	char buf[1000];
	int	i, n;
	
	if (argc !=2)
		error("Usage: sign file");
	
	FILE* file = fopen(argv[1], "r+b");
	if(!file)
		error("sing: can't open %s", argv[1]);
	
	n = fread(buf, 1, 1000, file);
	

	if(n > 510)
		error("boot block too large: %d bytes (max 510)", n); 
	
	printf ("boot block is %d bytes (max 510)", n);
	
	if (n < 509)
		for (i = n; i < 510; i++)
			buf[i] = 0x0;

	buf[510] = 0x55;
	buf[511] = 0xaa;

	fseek(file, 0, SEEK_SET ); // move to start
	fwrite(buf, 512, 1, file);
				
	fclose(file);
	return 0;
	
}

void error(char *fmt, ...)
{
	va_list args;
	
	va_start(args, fmt);
	vfprintf(stderr, fmt, args);
	fprintf(stderr, "\n");
	va_end(args);
	exit(1);
}

