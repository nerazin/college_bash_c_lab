// Example: ./a.out somefile
// Also ./a.out /dev/stdout

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>


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
	int in_c = 0;
	int close_ret;
	FILE *outf;

	if (argc != 2)
		return 1;
	if (check_file(argv[1]))
		return 1;
	outf = fopen(argv[1], "w");
	while (in_c != 6) {
		in_c = getc(stdin);
		putc(in_c, outf);
	}
	close_ret = fclose(outf);
	if (close_ret)
		return 1;
	return 0;
}
