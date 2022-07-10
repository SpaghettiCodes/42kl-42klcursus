#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>

#define BUFF_SIZE 12

typedef struct List{
	int fd;
	int	readuntil;
	char *contents;
	struct List* next;
} fd_list;

char		*get_next_line(int fd);

// list utils
fd_list		*fd_initialize(int fd);
fd_list		*fd_search_and_add(int fd, fd_list *list);
int			fd_fill_content(int fd, fd_list *list, char *buff);
char		*fd_search_line(fd_list *list);

// str utils
char		*str_substr(char *str, int start, int len);
int			str_len(char *str);
char		*str_join(char *str1, char *str2);

#endif
