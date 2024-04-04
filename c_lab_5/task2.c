// Just run

#include <unistd.h>

int main(int argc, char const *argv[])
{
	char *out_message = "this message is printed using write()\n";
	for (int i = 0; out_message[i] != '\0'; i++)
		write(1, &out_message[i], 1);
	return 0;
}
