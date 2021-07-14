#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>    //delete!!!!!!!!!!!!
# include <unistd.h>
# include <fcntl.h>


#  ifndef BUFFER_SIZE
#   define BUFFER_SIZE 300
#  endif

# define K_ESC 53
# define K_LEFT_A 0
# define K_RIGHT_D 2
# define K_UP_W 13
# define K_DOWN_S 1

typedef struct s_map
{
	int **map;
	int width;
	int height;
} t_map;

void make_map(char *av[], t_map *map);
int char_to_i(char a);

char			*ft_strjoin(char **s1, char *s2);
unsigned int	ft_strlen(char *s);
char			*ft_substr(char *s, unsigned int start, size_t len);
char			*ft_strdup(char *s);

int	ft_newline(const char *save);
int	update_save(char **save, int index, char **line);
int	read_done(char **line, char **save, int size);
int				get_next_line(int fd, char **line);

#endif
