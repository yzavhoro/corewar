/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 12:14:27 by alazarev          #+#    #+#             */
/*   Updated: 2018/07/28 14:53:37 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBFT_H
# define _LIBFT_H
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

void			*ft_memset(void *mem, int sign, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			ft_strcpy_cw(unsigned char *dst,
				const unsigned char *src, size_t len);
size_t			ft_strlen(const char *s);
size_t			ft_strmaslen(char **s);
char			*ft_strndup(const char *s1, int n);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *restrict s1, const char *restrict s2);
char			*ft_strncat(char *restrict s1,
				const char *restrict s2, size_t n);
size_t			ft_strlcat(char *restrict s1,
				const char *restrict s2, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *base, const char *find);
char			*ft_strnstr(const char *base, const char *find, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnew(size_t size);
char			**ft_strmasnew(int x, int y);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
void			ft_strmasfree(char ***str);
char			**ft_strsplit(char const *s, char c);
size_t			ft_strnsplit(char const *s, char c);
char			*ft_strrvrs(char const *s);
char			*ft_strrealloc(char **s, size_t len);
size_t			ft_strarrlen(char **s);
char			**ft_strarrdup(char **s);
void			ft_strarrfree(char **s);
char			*ft_itoa(int n);
char			*ft_itoa_base(int n, int base);
char			*ft_itoa_base_lower(int n, int base);
int				ft_atoi_base(const char *str, int str_base);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_ranknumber_base(intmax_t value, int base);
int				ft_rankunumber_base(uintmax_t value, int base);

void			ft_putnbr_fd(int n, int fd);
void			ft_putunbr_base_upper(unsigned long long n, int base);
void			ft_putunbr_base_lower(unsigned long long n, int base);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putchar_fd(char c, int fd);
void			ft_putnbr(long long n);
void			ft_putunbr(uintmax_t n);
void			ft_putendl(char const *s);
void			ft_putstr(char const *s);
void			ft_putchar(char c);
void			ft_putnchar(char c, int n);
void			ft_putnstr(char const *s, int n);
size_t			ft_charcount(char const *s, char c);

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

void			ft_error(char *str);
int				ft_rank(intmax_t value);
#endif
