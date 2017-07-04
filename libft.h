/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 14:41:24 by pmoran            #+#    #+#             */
/*   Updated: 2016/11/28 00:07:52 by pmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

char				**nineteen(char **nineteent);
char				*connect_count(char *str);
char				**check_and_pass_tetras(char **str, char **nineteen_tetras);
int					throw_error(void);
char				*valid_and_crop(char **str, int i);
int					ft_atoi(char *str);
void				ft_bzero(void *b, size_t len);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_strjoin(char const *s1, char const *s2);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char *str);
void				ft_putstr_fd(char *str, int fd);
void				ft_putendl(char *str);
void				ft_putendl_fd(char const *str, int fd);
void				ft_putnbr(int nb);
void				ft_putnbr_fd(int nb, int fb);
int					ft_strlen(char const *str);
char				*ft_strcat(char *s1, char *s2);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dest, char *src);
void				ft_strdel(char **as);
char				*ft_strdup(char *s);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void(*f)(char *));
void				ft_striteri(char *s, void(*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, char *s2, int n);
int					ft_strncmp(char *s1, char *s2, unsigned int n);
char				*ft_strncpy(char *dest, char *src, unsigned int n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strstr(const char *str, const char *to_find);
char				*ft_strnstr(char *s1, char *s2, size_t len);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_strtrim(char const *s);
char				*ft_itoa(int n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				**ft_strsplit(char const *s, char c);
int					high_squarert(int n);
typedef struct		s_map
{
	int				size;
	char			**array;
}					t_map;
typedef struct		s_size
{
	int				x;
	int				y;
}					t_size;
typedef struct		s_etroid
{
	char			**pos;
	int				width;
	int				height;
	char			curr;
}					t_etroid;
typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;
t_list				*readin(char **str);
void				printmap(t_map *map);
void				freemap(t_map *map);
t_map				*map_new(int size);
int					place(t_etroid *tetroid, t_map *map, int x, int y);
void				set_piece(t_etroid *tetroid, t_map\
		*map, t_size *size, char c);
t_map				*solve(t_list *list);
t_size				*size_new(int x, int y);
t_etroid			*tetroid_new(char **pos, int width, int height, char c);
void				free_tetroid(t_etroid *tetroid);
t_list				*free_list(t_list *list);
void				ft_lstreverse(t_list **alst);
size_t				ft_lstcount(t_list *lst);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

#endif
