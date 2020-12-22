#ifndef HEADERS_H
# define HEADERS_H

# define FRAMERATE 20

# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <time.h>
# include <curses.h>
# include <signal.h>

size_t	ft_strlen_nl(const char *s, size_t maxlen);
int		get_file_size(int fd);
void	free_waves(int **waves);
int		**draw_ocean();
char	*read_file();
int		draw_story(char *story, char *beep_boop, unsigned int frame);

#endif
