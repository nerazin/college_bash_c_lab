// Example: ./a.out tfile 5

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>


int check_file(const char *filename)
{
	struct stat sb;
	if (stat(filename, &sb) != 0)
		return 1;
	if (sb.st_mode & S_IWUSR && sb.st_mode & S_IRUSR) {}
	else
		return 1;
	return 0;
}


int main(int argc, char const *argv[])
{
	int lines_num = 0;
	int close_ret;
	int ch;
	int lines_count = 0;
	FILE *readf;

	if (argc != 3)
		return 1;
	if (check_file(argv[1]))
		return 1;
	lines_num = atoi(argv[2]);
	readf = fopen(argv[1], "r");
	while ((ch = getc(readf)) != EOF) {
		putc(ch, stdout);
		if (ch == '\n')
			lines_count++;
		if (lines_count == lines_num) {
			getc(stdin);
			lines_count = 0;
		}
	}
	close_ret = fclose(readf);
	if (close_ret)
		return 1;
	return 0;
}
