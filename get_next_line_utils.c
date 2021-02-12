/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 02:13:59 by naykim            #+#    #+#             */
/*   Updated: 2021/02/13 02:14:13 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

char *ft_strjoin(char *s1, char *s2) {
    char *str;
    unsigned int len1;
    unsigned int len2;
    unsigned int i;
    unsigned int k;

    i = 0;
    k = 0;
    if (s1 == 0 || s2 == 0)
        return (NULL);
    len1 = (unsigned int) ft_strlen(s1);
    len2 = (unsigned int) ft_strlen(s2);
    if (!(str = (char *)malloc(sizeof(char) * (len1 + len2 + 1))))
        return (NULL);
    while (k < len1)
        str[i++] = s1[k++];
    k = 0;
    while (k < len2)
        str[i++] = s2[k++];
    str[i] = '\0';
    return (str);
}