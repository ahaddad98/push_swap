/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 13:38:15 by ahaddad           #+#    #+#             */
/*   Updated: 2021/04/18 13:27:48 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

int	check_args(char **av, int ac, t_push_swap *push_swap)
{
	int		k;
	char	**tab;

	k = 0;
	push_swap->j = 1;
	push_swap->len_of_stack = 0;
	while (av[push_swap->j])
	{
		k = 0;
		tab = ft_split(av[push_swap->j], ' ');
		while (tab[k])
		{
			if (ft_atoi_loong(tab[k]) > 2147483647)
				return (1);
			else if (ft_atoi_loong(tab[k]) < -2147483648)
				return (1);
			else if (is_num(tab[k]) == 1)
				return (1);
			k++;
			push_swap->len_of_stack++;
		}
		ft_free_2dem_arr((void ***)&tab);
		push_swap->j++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_push_swap		push_swap;
	char			*line;
	int				ret_read;

	if (ac > 1 && !check_args(av, ac, &push_swap))
	{
		get_a_from_arg(&push_swap, av, ac);
		while (get_next_line(0, &line))
		{
			get_instruc(&push_swap, line);
			print_a_b(&push_swap);
			ft_free_arr((void **)&line);
		}
		ft_free_arr((void **)&line);
		if (push_swap.a)
			ft_free_2dem_arr((void ***)&push_swap.a);
		if (push_swap.b)
			ft_free_2dem_arr((void ***)&push_swap.b);
	}
	else
		ft_putendl_fd("Error", 1);
	return (0);
}
