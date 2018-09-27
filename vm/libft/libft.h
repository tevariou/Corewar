#ifndef	LIBFT_H
# define LIBFT_H

# define TRUE 1
# define FALSE 0

# include <stdlib.h>

typedef int	t_bool;

char	*ft_strdup(const char *s1);
char	*ft_strndup(const char *s, size_t n);
char	*ft_strchr(const char *s, int c);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strsub(const char *s, unsigned int start, size_t len);
char	*ft_strnew(size_t size);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strcat(char *dest, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
char	**ft_strsplit(const char *s, char c);
int		ft_isspace(int c);
int		ft_isdigit(int c);
void	ft_putchar(char c);
void	ft_putstr(const char *s);
void	ft_putnbr(int n);
void	ft_strclr(char *s);
t_bool	ft_strequ(const char *s1, const char *s2);

#endif
