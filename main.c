#include "get_next_line.h"

int main(void)
{
    int fd;
    fd = open("buffer.txt", O_RDONLY);
//    printf("%s\n", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
