/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 22:16:45 by ahaddad           #+#    #+#             */
/*   Updated: 2021/04/17 15:23:33 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	char			*ss;

	index = 0;
	if (!s || !f)
		return (NULL);
	ss = (char *)malloc(ft_strlen((char *)s) + 1);
	if (!ss)
		return (NULL);
	while (s[index])
	{
		ss[index] = (*f)(index, s[index]);
		index++;
	}
	ss[index] = '\0';
	return (ss);
}
