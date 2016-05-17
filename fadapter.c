#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define FADBUF 1024

const char* usage = "Usage: fadapter <infifo> > <outfifo>";

int main(int argc, char** argv)
{
    if(argc > 2)
    {
	fprintf(stderr, "fadapter: not enough arguments\n%s\n", usage);
	exit(EXIT_FAILURE);
    }

    const char* infilename = argv[1];
    while(true)
    {
	FILE* infile = fopen(infilename, "r");
	if(!infile)
	{
	    perror("failed to open input file");
	    exit(EXIT_FAILURE);
	}
	
	while(true)
	{
	    char buf[FADBUF];
	    int r = fread(buf, 1, 1, infile);
	    if(r < 1) break; //FIFO closing, reopen
	    int w = fwrite(buf, 1, r, stdout);
	    if(w < r) //somehow failed to write everything
	    {
		perror("failed to write to standard out");
		exit(EXIT_FAILURE);
	    }
	    fflush(stdout);
	}

	fclose(infile);
    }
}
