/* setpaddr.c set pysical address

   This program corrects the physical address of kernel_elf.
   Usage: setpaddr kernel_elf > kernel_elf.set

   by Hiroshi Uno */
 
#include <stdio.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stdlib.h>

struct elf_header {
	char e_ident[16];
	short e_type;
	short e_machine;
	long e_version;
	long e_entry;
	long e_phoff;
	long e_shoff;
	long e_flags;
	short e_ehsize;
	short e_pehtsize;
	short e_phnum;
	short e_shetsize;
	short e_shnum;
	short e_shstrndx;
};

struct pg_header {
	long p_type;
	long p_offset;
	long p_vaddr;
	long p_paddr;
	long p_filesz;
	long p_memmsz;
	long p_flags;
	long p_align;
};

void error(char *fmt, ...);
long lseek(int fd, long offset, int origin);
void pg_dump(struct pg_header *h);

#define PH_MAX 10

//                   0x80100000
#define MASK_PATTERN 0x00FFFFFF

int main (int argc, char *argv[])
{
	struct elf_header header;
	struct pg_header phd[PH_MAX];
	int	i, pnum;
	
	if (argc !=2)
		error("Ussage: setpaddr elffile");
	
	FILE* file = fopen(argv[1], "r+b");
	if(!file)
		error("setpaddr: can't open %s", argv[1]);
	fread(&header, sizeof(header), 1, file);

	if(header.e_type == 0x02 &&
		header.e_ident[1] == 'E' &&
		header.e_ident[2] == 'L' &&
		header.e_ident[3] == 'F') {
	} else {
		error("setpaddr: %s is not elf file", argv[1]);
	}
	
	fprintf(stdout, "\n--- Original Values ---\n\n");

	fseek(file, header.e_phoff, SEEK_SET ); // move to program headder
	pnum = header.e_phnum;
	if (pnum > PH_MAX)
		error("setpaddr: e_phnum = %x is too large", pnum);

	for (i=0; i<pnum; i++) {
		fread(&phd[i], sizeof(struct pg_header), 1, file);
		pg_dump(&phd[i]);
	}

	fprintf(stdout, "--- Set Values ---\n\n");

	fseek(file, header.e_phoff, SEEK_SET ); // move to program headder
	for (i=0; i<pnum; i++) {
		phd[i].p_paddr = phd[i].p_paddr & MASK_PATTERN;
		pg_dump(&phd[i]);
		fwrite(&phd[i], sizeof(struct pg_header), 1, file);
	}
	fclose(file);
	return 0;
}

void pg_dump(struct pg_header *h)
{
	fprintf(stdout, "\tp_type: %x\n", h->p_type);
	fprintf(stdout, "\tp_paddr: %x\n\n", h->p_paddr);
}

void error(char *fmt, ...)
{
	va_list args;
	
	va_start(args, fmt);
	fprintf(stderr, "error: ");
	vfprintf(stderr, fmt, args);
	fprintf(stderr, "\n");
	va_end(args);
	exit(1);
}

