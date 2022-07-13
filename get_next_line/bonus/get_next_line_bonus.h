#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define BUFF_SIZE 42

typedef struct s_List{
	int fd;
	int	readuntil;
	int	checkuntil;
	char *contents;
	struct s_List* next;
} t_fd_list;

char		*get_next_line(int fd);

// list utils
t_fd_list		*fd_initialize(int fd);
t_fd_list		*fd_search_and_add(int fd, t_fd_list *list);
int			fd_fill_content(int fd, t_fd_list *list, char *buff);
char		*fd_search_line(t_fd_list *list);
void		fd_search_and_destroy(int fd, t_fd_list **list);

// str utils
char		*str_substr(char *str, int start, int len);
int			str_len(char *str);
char		*str_join(char *str1, char *str2);
int			has_sep(t_fd_list *list);

#endif
