/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 17:43:40 by ahaddad           #+#    #+#             */
/*   Updated: 2021/04/17 15:21:22 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*res;
	int		i;

	i = 0;
	res = (char *)str;
	while (res[i])
	{
		if (res[i] == c)
			return (&res[i]);
		i++;
	}
	if (c == '\0')
	{
		return (&res[i]);
	}
	return (0);
}
