/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 12:04:37 by ahaddad           #+#    #+#             */
/*   Updated: 2021/04/19 17:36:55 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	which_algo(t_push_swap *push_swap, int len)
{
	if (len == 2)
	{
		if (ft_atoi(push_swap->a[0]) > ft_atoi(push_swap->a[1]))
			swap_a(push_swap);
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
	if (ft_strlen(str) == 1)
		if (ft_isdigit(str[i]) == 0)
			return (1);
	while (str[i])
	{
		if (i == 0)
		{
			if (str[i] == '-')
			{
				i++;
				continue ;
			}
		}
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

	get_flag(push_swap, av, ac);
	while (av[push_swap->j])
	{
		k = 0;
		tab = ft_split(av[push_swap->j], ' ');
		if (!tab[k])
			return (free_ret(tab));
		while (tab && tab[k])
		{
			if (ft_atoi_loong(tab[k]) > 2147483647)
				return (free_ret(tab));
			else if (ft_atoi_loong(tab[k]) < -2147483648)
				return (free_ret(tab));
			else if (is_num(tab[k]) == 1)
				return (free_ret(tab));
			k++;
			push_swap->len_of_stack++;
		}
		ft_free_2dem_arr((void ***)&tab);
		push_swap->j++;
	}
	return (0);
}

void	get_a_from_arg(t_push_swap *push_swap, char **av)
{
	int		k;
	int		i;
	int		j;
	char	**tab;

	j = 0;
	k = 0;
	i = 1;
	push_swap->a = malloc(sizeof(char *) * (push_swap->len_of_stack + 2));
	if (push_swap->check_flags)
		i = 2;
	while (av[i])
	{
		j = 0;
		tab = ft_split(av[i], ' ');
		while (tab[j])
		{
			push_swap->a[k] = ft_strdup(tab[j]);
			j++;
			k++;
		}
		ft_free_2dem_arr((void ***)&tab);
		i++;
	}
	push_swap->a[k] = NULL;
}

int	main(int ac, char **av)
{
	t_push_swap		push_swap;
	int				i;
	int				len;
	int				k;

	k = 0;
	i = 0;
	len = 0;
	if (ac > 1 && !check_args(av, ac, &push_swap))
	{
		get_a_from_arg(&push_swap, av);
		if (check_if_duplic(&push_swap))
			ft_putendl_fd("Error", 1);
		else if (push_swap.a && check_if_sort(&push_swap))
		{
			p_s_now(&push_swap, len);
			if (push_swap.b)
				ft_free_2dem_arr((void ***)&push_swap.b);
		}
		if (push_swap.a)
			ft_free_2dem_arr((void ***)&push_swap.a);
	}
	else if (ac > 1)
		ft_putendl_fd("Error", 1);
	return (0);
}
