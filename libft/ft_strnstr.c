/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 10:38:57 by ahaddad           #+#    #+#             */
/*   Updated: 2021/04/17 15:24:24 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (!s2[j])
		return ((char *)(s1));
	while (i < len && s1[i])
	{
		j = 0;
		if (s1[i] == s2[j])
		{
			j = 1;
			while (s2[j] && s2[j] == s1[i + j] && (i + j) < len)
				j++;
			if (!s2[j])
				return ((char *)&s1[i]);
		}
		i++;
	}
	return (NULL);
}
