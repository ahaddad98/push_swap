/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:56:23 by ahaddad           #+#    #+#             */
/*   Updated: 2021/04/18 13:29:50 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(int reslt, int b, int count)
{
	if (count > 19)
	{
		if (b >= 0)
			return (-1);
		else
			return (0);
	}
	return (reslt * b);
}

int	ft_atoi(const char *str)
{
	int		a;
	int		b;
	int		c;
	int		counter;

	a = 0;
	b = 1;
	c = 0;
	counter = 0;
	while (str[a] == ' ' || str[a] == '\f' || str[a] == '\n' || str[a] == '\t'
		|| str[a] == '\r' || str[a] == '\v')
		a++;
	if (str[a] == '+' || str[a] == '-')
	{
		if (str[a] == '-')
			b = -1;
		a++;
	}
	while (str[a] != '\0' && str[a] >= '0' && str[a] <= '9')
	{
		c = c * 10 + str[a] - '0';
		a++;
		counter++;
	}
	return (check(c, b, counter));
}

long long	ft_atoi_loong(char *str)
{
	long long		ret;
	int				sign;
	int				i;

	i = 0;
	ret = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\r' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\t')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1 * sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret = ret * 10 + str[i] - '0';
		i++;
	}
	return (ret * sign);
}
