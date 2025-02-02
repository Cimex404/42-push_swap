#ifndef PS_CHECKER_H
# define PS_CHECKER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <stdio.h>

/*		Get_next_line		*/
char	*get_next_line(int fd);
char	*append(char *line, char *buffer, int read_bytes);
void	free_mem(char *line);

#endif