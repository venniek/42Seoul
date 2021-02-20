#include "get_next_line.h"
#include <stdio.h>

int    main()
{
    char *line;
    int    check;
    int    fd;
    int i;

    i = 1;
    line = "";
    fd = open("/Users/nayeon/Desktop/42/gnl/test.txt", O_RDONLY);
    while ((check = get_next_line(fd, &line)) > 0) {
        printf("line %d: %s\n", i, line);
        free(line);
        i++;
    }
    printf("line %d: %s\n", i, line);
    free(line);
    return (0);
}