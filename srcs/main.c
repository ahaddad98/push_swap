/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 13:38:15 by ahaddad           #+#    #+#             */
/*   Updated: 2021/03/28 17:21:47 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int				count_line(char **env)
{
	int i;

	i = 0;
	if (!env)
		return (0);
	while (env[i])
		i++;
	return (i);
}

 void         convert_tab(char **tab, int **a)
{
    int len;
    len = count_line(tab);
    *a = malloc(sizeof(int) * len);
    int i = 1;
    int k = 0;
    while (tab[i])
    {
        (*a)[k] = ft_atoi(tab[i]);
        k++;
        i++;
    }
}

char			**ft_strdup_2d(char **str)
{
	int			len;
	char		**ret;
	int			i;

	i = 0;
	len = count_line(str);
	ret = malloc(sizeof(char *) * (len + 1));
	i = 0;
	while (str[i])
	{
		ret[i] = ft_strdup(str[i]);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

void    rotate(char **a)
{
    char *p;
    int  i = 0;
    int j = 1;
    p = ft_strdup(a[0]);
    while (a[j])
    {
        a[i] = ft_strdup(a[j]);
        i++;
        j++;
    }
    a[i] = ft_strdup(p);
}

void        rot_rot(char **a)
{
    char *p;
    int i = 0;
    int j = 1;
    char **new_a;
    int len = count_line(a);
    new_a = malloc(sizeof(char *) * (len + 1));
    // p = ft_strdup(a[0]);
    // printf("{{{%s}}}\n",a[len -1]);
    new_a[0] = ft_strdup(a[len - 1]);
    while (i < len - 1)
    {
        // printf("{%s}\n",a[i]);
        new_a[j] = ft_strdup(a[i]);
        j++;
        i++;
    }
    new_a[j] = NULL;
    j = 0;
    while (new_a[j])
    {
        a[j] = ft_strdup(new_a[j]);
        j++;
    }
}

int main(int ac, char **av)
{
    char        **a;
    int         i = 1;
    int         k = 0;
    char        **b;
    t_push_swap push_swap;
    a = NULL;
    b = NULL;
    if (ac == 1)
        ft_putstr_fd("one element\n", 1);
    else if (ac == 0)
        ft_putstr_fd("no element\n", 1);
    if (av[0])
        ft_putstr_fd("OK\n", 1);
    push_swap.a = malloc(sizeof(char *) * ac);
    while (i < ac)
    {
        push_swap.a[k] = ft_strdup(av[i]);
        i++;
        k++;
    }
    push_swap.a[k] = NULL;
    k = 0;
    push_swap.b = malloc(sizeof(char *) * 1);
    push_swap.b[0] = ft_strdup("22200");
    rot_rot(push_swap.a);
    // swap(push_swap.a);
    if (push_swap.a == NULL)
    {
        puts("{raha NULL sir 3allah}");
    }
    while (push_swap.a[k])
    {
        printf("%s\n",push_swap.a[k]);
        k++;
    }
    return (0);
}