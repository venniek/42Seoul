/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 20:24:56 by naykim            #+#    #+#             */
/*   Updated: 2021/01/02 20:37:45 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

int ft_atoi(const char *str);
int ft_islower(int c);
int ft_isupper(int c);
int ft_isalpha(int c);
int ft_isdigit(int c);
int ft_isalnum(int c);
int ft_isascii(int c);
int ft_isprint(int c);
int ft_toupper(int c);
int ft_tolower(int c);
void *memset(void *ptr, int value, size_t num);
void *memcpy(void *dest, const void *src, size_t num);
void *memccpy(void *dest, const void *src, int c, size_t n);
void *memmove(void *dest, const void *src, size_t n);
void *memchr(const void *ptr, int value, size_t n);
int memcmp(const void  *ptr1, const void *ptr2, size_t n);
void bzero(void *ptr, size_t size);
size_t strlen(const char *s);
size_t strlcpy(char *dst, const char *s, size_t size);
size_t strlcat(char *dst, const char *src, size_t size);
char *strchr(const char *str, int a);
char *strrchr(const char *str, int a);
int strnstr
int strncmp(const char *str1, const char *str2, size_t n);
void *calloc(size_t n, size_t size);
char *strdup(const char *s);

char *ft_substr(char const *s, unsigned int start, size_t len);
char *ft_strjoin(char const *s1, chr const *s2);
char *ft_strtrim(char const *s1, char const *set);
char **ft_split(char const *s, char c);
char *ft_itoa(int n);
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
void ft_putchar_fd(char c, int fd);
void ft_putstr_fd(char *s, int fd);
void ft_putendl_fd(char *s, int fd);
void ft_putnbr_fd(int n, int fd);


#endif
