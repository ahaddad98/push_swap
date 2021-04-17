/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_insert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 00:42:25 by amine             #+#    #+#             */
/*   Updated: 2021/04/17 15:11:12 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	get_med_com(t_push_swap *push_swap, int len, char **tmp1, int i)
{
	if (len > 20 && len <= 100)
	{
		push_swap->med = malloc(sizeof(char *) * ((len / 7)));
		i = len / 7;
		while (i < len)
		{
			push_swap->med[push_swap->j] = ft_strdup(tmp1[i]);
			push_swap->j++;
			i = i + (len / 7);
		}
		push_swap->med[push_swap->j] = NULL;
	}
	else if (len > 100)
	{
		push_swap->med = malloc(sizeof(char *) * ((len / 12)));
		i = len / 12;
		while (i < len)
		{
			push_swap->med[push_swap->j] = ft_strdup(tmp1[i]);
			push_swap->j++;
			i = i + (len / 12);
		}
		push_swap->med[push_swap->j] = NULL;
	}
}

void	get_med_len(t_push_swap *push_swap, int len, char **tmp1, int i)
{
	int		k;

	if (len <= 5)
	{
		push_swap->med = malloc(sizeof(char *) * 2);
		i = len / 2;
		k = 0;
		push_swap->med[k] = ft_strdup(tmp1[i]);
		k++;
		push_swap->med[k] = NULL;
	}
	else if (len > 5 && len <= 20)
	{
		push_swap->med = malloc(sizeof(char *) * 2);
		i = len / 2;
		k = 0;
		push_swap->med[k] = ft_strdup(tmp1[i]);
		push_swap->med[k + 1] = NULL;
	}
	else
	{
		push_swap->j = 0;
		get_med_com(push_swap, len, tmp1, i);
	}
}

void	tri_insert(t_push_swap *push_swap, int len)
{
	char	*tmp;
	char	**tmp1;

	push_swap->i = 0;
	tmp1 = ft_strdup_2d(push_swap->a);
	tmp = NULL;
	while (tmp1[push_swap->i])
	{
		push_swap->j = push_swap->i;
		tmp = NULL;
		while (push_swap->j < len)
		{
			if (ft_atoi(tmp1[push_swap->i]) > ft_atoi(tmp1[push_swap->j]))
			{
				tmp = tmp1[push_swap->j];
				tmp1[push_swap->j] = tmp1[push_swap->i];
				tmp1[push_swap->i] = tmp;
			}
			push_swap->j++;
		}
		push_swap->i++;
	}
	push_swap->med = NULL;
	get_med_len(push_swap, len, tmp1, push_swap->i);
	ft_free_2dem_arr((void ***)&tmp1);
}

void	get_mediane(t_push_swap *push_swap, int len)
{
	tri_insert(push_swap, len);
}
