/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 21:00:44 by ahaddad           #+#    #+#             */
/*   Updated: 2021/04/17 17:05:17 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*t;

	i = 0;
	while (s1[i])
		i++;
	t = malloc(sizeof(char) * (i + 1));
	if (!t)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		t[i] = s1[i];
		i++;
	}
	t[i] = '\0';
	return (t);
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*p;
	int		i;

	if (!s)
		return (NULL);
	p = malloc((len + 1) * sizeof(char));
	i = 0;
	if (!p)
		return (NULL);
	p[len] = '\0';
	while (len--)
	{
		p[i] = s[start];
		i++;
		start++;
	}
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (NULL);
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	s3[i] = '\0';
	return (s3);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*a;

	a = (unsigned char *)s;
	while (*a)
	{
		if (*a == (unsigned char)c)
			return ((char *)a);
		a++;
	}
	if (*a == (unsigned char)c)
		return ((char *)a);
	return (NULL);
}
