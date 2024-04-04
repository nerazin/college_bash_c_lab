// Example: ./a.out tfile out_file

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
	int close_ret_in, close_ret_out;
	int ch;
	FILE *in_file;
	FILE *out_file;

	if (argc != 3)
		return 1;
	if (check_file(argv[1]) || check_file(argv[2]))
		return 1;
	in_file = fopen(argv[1], "r");
	out_file = fopen(argv[2], "w");
	while ((ch = getc(in_file)) != EOF) {
		putc(ch, out_file);
	}
	close_ret_in = fclose(in_file);
	close_ret_out = fclose(out_file);
	if (close_ret_in || close_ret_out)
		return 1;
	return 0;
}
