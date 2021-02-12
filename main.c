#include "get_next_line.h"
#include <stdio.h>

int main()
{
    int fd;
    char *line;
    int i;

    line = "";
    fd = open("/Users/nayeon/Desktop/42/gnl/test.txt", O_RDONLY);
    i = 1;
    printf("%d\n", fd);
    while (get_next_line(fd, &line) > 0)
    {
        printf("line %d: %s\n", i, line);
        i++;
    }
    return 0;
}
