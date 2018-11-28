/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfonda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 15:03:20 by kfonda            #+#    #+#             */
/*   Updated: 2018/10/23 15:03:23 by kfonda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int d);
int					ft_isprint(int c);
int					ft_isspace(int c);
void				ft_bzero(void *s, size_t n);
int					ft_atoi(const char *str);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
char				*ft_strcat(char *dest, char *src);
char				*ft_strchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strdup(const char *src);
size_t				ft_strlcat(char *dest, char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strncat(char *dest, char *src, int nb);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strnstr(const char *str, const char *find, size_t len);
char				*ft_strrchr(const char *str, int c);
char				*ft_strstr(const char *str, const char *find);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_memcmp(const void *str1, const void *str2, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
char				*ft_itoa(int n);
void				*ft_memalloc(size_t size);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_strclr(char *s);
int					ft_strequ(char const *s1, char const *s2);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
int					ft_is_snt_space(char c);
int					ft_int_len(int n);
void				ft_print_int_array(int *arr, int n);
void				ft_striter(char *s, void (*f)(char *));
char				**ft_strsplit(char const *s, char c);
void				ft_strdel(char **as);
void				ft_memdel(void **ap);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_print_list(t_list *list);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_find_last_char(char const *s);
int					ft_make_word(char **w_list, int w_l, int wc, const char *s);
int					ft_words_num(char const *s, char c);
t_list				*ft_strsplit_to_lst(char const *s, char c);
void				ft_lstaddend(t_list **alst, t_list *new);
void				*ft_lstfold(t_list *lst, void *(*f)(void *, void *));
char				*ft_strsubend(char const *s, unsigned int start);

void				ft_free2d(char **array, int len);

#endif
