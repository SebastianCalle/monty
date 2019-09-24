#include "monty.h"
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv)
{
	char line[50];
	char **args;
	FILE *fd;
	int n = 0, num;

	fd = fopen(argv[1], "r");
	while(fgets(line, 50, (FILE*) fd))
	{
		args = _strtok(line, &n);
		if (strcmp(args[0], "push") == 0)
		{
			num = atoi(args[1]);
			printf("%s %d\n", args[0], num);
		}
		n = 0;
		free(args[0]);
		free(args[1]);
		free(args);
	}
	fclose(fd);

	return (0);
}
