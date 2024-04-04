// Example: ./a.out /

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <dirent.h>


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
	DIR *dp_cur;
	DIR *dp_path;
	struct dirent *ep;
	struct dirent *current_dir;
	struct dirent *arg_dir;

	if (argc != 2)
		return 1;
	if (check_file(argv[1]) || check_file("."))
		return 1;

	dp_cur = opendir("./");
	if (dp_cur != NULL) {
		while ((ep = readdir(dp_cur)) != NULL)
			puts(ep->d_name);

		closedir(dp_cur);
	}
	puts("---SPECIFIED FOLDER---");
	dp_path = opendir(argv[1]);
	if (dp_path != NULL) {
		while ((ep = readdir(dp_path)) != NULL)
			puts(ep->d_name);

		closedir(dp_path);
	}
	return 0;
}