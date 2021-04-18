/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 12:04:37 by ahaddad           #+#    #+#             */
/*   Updated: 2021/04/18 01:53:07 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	which_algo(t_push_swap *push_swap, int len)
{
	if (len == 2)
	{
		if (ft_atoi(push_swap->a[0]) > ft_atoi(push_swap->a[1]))
			swap_a(push_swap->a, push_swap);
	}
	else if (len == 3)
		algo_3_elem(push_swap);
	else if (len <= 5)
		algo_less_5_elem(push_swap);
	else
		use_mediane(push_swap, len);
}

int	is_num(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	check_args(char **av, int ac)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (av[j])
	{
		if (ft_atoi_loong(av[j]) > 2147483647)
			return (1);
		else if (ft_atoi_loong(av[j]) < -2147483648)
			return (1);
		else if (is_num(av[j]) == 1)
			return (1);
		j++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_push_swap		push_swap;
	int				i;
	int				ret_read;
	int				len;
	int				k;

	k = 0;
	i = 1;
	len = 0;
	if (ac > 1 && !check_args(av, ac))
	{
		push_swap.a = malloc(sizeof(char *) * (ac + 1));
		while (av[i])
		{
			push_swap.a[k] = ft_strdup(av[i]);
			i++;
			k++;
		}
		push_swap.a[k] = NULL;
		push_swap.b = NULL;
		len = count_line(push_swap.a);
		which_algo(&push_swap, len);
		if (push_swap.a)
			ft_free_2dem_arr((void ***)&push_swap.a);
		if (push_swap.b)
			ft_free_2dem_arr((void ***)&push_swap.b);
	}
	return (0);
}
