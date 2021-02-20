#include "get_next_line.h"
#include <stdio.h>

int    main()
{
    char *line;
    int    check;
    int    fd;

    fd = open("test.txt", O_RDONLY);
    while ((check = get_next_line(fd, &line)) > 0) {
        printf("line: %s\n", line);
        free(line);
    }
    printf("line: %s\n", line);
    free(line);
    return (0);
}
