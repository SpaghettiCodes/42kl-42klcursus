#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>

#define BUFF_SIZE 12

char		*get_next_line(int fd);

// str utils
char		*str_substr(char *str, int start, int len);
int			str_len(char *str);
char		*str_join(char *str1, char *str2);
int			has_sep(char *content);
char		*lineextractor(char *content);

#endif
