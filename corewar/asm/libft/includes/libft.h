/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 10:02:20 by jngoma            #+#    #+#             */
/*   Updated: 2017/09/17 10:09:35 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>
# include <stdlib.h>
# define GET_LINE_BUFF_SIZE 32
# include "libft.h"
# define FT_COL(x) "\x1B[" x "m"

typedef struct			s_reader
{
	int					fd;
	char				*buffer;
	char				*el;
	int					stop;
	size_t				r_size;
	size_t				b_size;
}						t_reader;

typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

typedef long long int	t_putnbr;
typedef unsigned char	t_uc;

char					*ft_strcat(char *dest, const char *src);
char					*ft_strchr(char *s, int c);
char					*ft_strcpy(char *dest, const char *src);
char					*ft_strdup(const char *s);
char					*ft_strncat(char *dest, const char *src, size_t n);
char					*ft_strncpy(char *dest, const char *src, size_t n);
char					*ft_strnew(size_t size);
char					*ft_strrchr(char *s, int c);
char					*ft_strsub(char const *s, unsigned int strt, size_t ln);

int						ft_atoi(const char *nbr);
int						ft_isascii(int c);
int						ft_isdigit(int c);
int						ft_strclen(char *str, char c);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(const char *s1, const char *s2, size_t len);

size_t					ft_strlen(const char *s);

t_list					*ft_lstnew(void const *content, size_t content_size);

void					*ft_memalloc(size_t size);
void					*ft_memchr(const void *s, int c, size_t n);
void					*ft_memcpy(void *dest, const void *src, size_t n);
void					*ft_memmove(void *dest, const void *src, size_t n);
void					*ft_memset(void *s, int c, size_t n);
void					ft_bzero(void *s, size_t n);
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_memdel(void **ap);
void					ft_putchar_fd(char c, int fd);
void					ft_putchar(char c);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putstr(char const *s);
void					ft_putendl(const char *str);
int						ft_strequ(const char *s1, const char *s2);
char					*ft_strtrim(char const *s);
char					**ft_strsplit(char const *s, char c);
char					*ft_strdefix(char *str, int c);
char					*ft_strndup(const char *s, int len);
void					ft_putline(void);
void					**ft_destroy_2d(void **grid);
int						ft_items_in_grid(void **grid);
char					*ft_strstr(const char *haystack, const char *needle);
char					*ft_strjoin(char *dest, const char *src);
void					ft_replace(char **str, char c, char r);
void					ft_strdel(char **as);
/*
** My extra functions
*/

char					*ft_itoa_base(t_putnbr n, int base);

int						ft_abs(int nb);
int						get_next_line(const int fd, char **line);
int						ft_max(int a, int b);
int						ft_min(int a, int b);
int						ft_printf_core(int fd, const char *frmt, va_list *lst);
int						ft_printf_fd(int fd, const char *format, ...);
int						ft_printf(const char *format, ...);
void					ft_putwchar_fd(wchar_t c, int fd);
void					ft_putwstr_fd(wchar_t *str, int fd);

#endif
