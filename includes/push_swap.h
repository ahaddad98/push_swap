/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:10:12 by ahaddad           #+#    #+#             */
/*   Updated: 2021/04/13 01:30:24 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_push_swap
{
    char                        **a;
    char                        **b;
    int                         *cast_a;
    int                         checker;
    char                        **med;
    int                         nbr_of_med;
    int                         nbr_of_inst;
    int                         max_in_arr;
    int                         max_index;
    long long int               mediane;
}           t_push_swap;

void        swap_a(char **ab, t_push_swap *push_swap);
void        push_a(t_push_swap *push_swap);
void        push_b(t_push_swap *push_swap);
char		**ft_strdup_2d(char **str);
int			count_line(char **env);
void        rotate(char **a, t_push_swap *push_swap);
void        rot_rot(char **a, t_push_swap *push_swap);
int         ft_strcmp(const char *s1, const char *s2);
void        swap_b(char **tab, t_push_swap *push_swap);
void		ft_free_2dem_arr(void ***arr);
void		ft_free_arr(void **array);
void        push_b_2(t_push_swap *push_swap);
void        tri_insert(t_push_swap *push_swap, int len);
void        get_mediane(t_push_swap *push_swap, int len);
int check_under_pivot(char **ag, int pivot);
int check_bigg_pivot(char **ag, int pivot);
int get_index(t_push_swap *push_swap, int med);
int get_index2(t_push_swap *push_swap, int med);
int get_index1(t_push_swap *push_swap, int med);
int get_max(t_push_swap *push_swap);
int get_min(t_push_swap *push_swap);
void    algo_3_elem(t_push_swap *push_swap);
void use_mediane(t_push_swap *push_swap, int len);
#endif