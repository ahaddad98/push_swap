/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:10:12 by ahaddad           #+#    #+#             */
/*   Updated: 2021/04/18 14:16:01 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# define BUFFER_SIZE 1000

typedef struct s_push_swap
{
	char				**a;
	char				**b;
	int					checker;
	char				**med;
	int					nbr_of_med;
	int					nbr_of_inst;
	int					max_in_arr;
	int					len_of_stack;
	int					i;
	int					j;
	int					len;
	int					max_index;
	int					check_flags;
	long long int		mediane;
}		t_push_swap;

void	swap_a(char **ab, t_push_swap *push_swap);
void	push_a(t_push_swap *push_swap);
void	push_b(t_push_swap *push_swap);
char	**ft_strdup_2d(char **str);
int		count_line(char **env);
void	rotate(char **a, t_push_swap *push_swap, char *msg);
void	rot_rot(char **a, t_push_swap *push_swap, char *msg);
int		ft_strcmp(const char *s1, const char *s2);
void	swap_b(char **tab, t_push_swap *push_swap);
void	ft_free_2dem_arr(void ***arr);
void	ft_free_arr(void **array);
void	push_b_2(t_push_swap *push_swap);
void	tri_insert(t_push_swap *push_swap, int len);
void	get_mediane(t_push_swap *push_swap, int len);
int		check_under_pivot(char **ag, int pivot);
int		check_bigg_pivot(char **ag, int pivot);
int		get_index(t_push_swap *push_swap, int med);
int		get_index2(t_push_swap *push_swap, int med);
int		get_index1(t_push_swap *push_swap, int med);
int		get_max(t_push_swap *push_swap);
int		get_min(t_push_swap *push_swap);
void	algo_3_elem(t_push_swap *push_swap);
void	algo_less_5_elem(t_push_swap *push_swap);
void	use_mediane(t_push_swap *push_swap, int len);
void	push_b_less_med(t_push_swap *push_swap, int len);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
int		get_next_line(int fd, char **line);
int		check_if_sort(t_push_swap *push_swap);
void	print_a_b(t_push_swap *push_swap);
void	get_instruc_com(t_push_swap *push_swap, char *line);
void	get_instruc(t_push_swap *push_swap, char *line);
void	get_a_from_arg(t_push_swap *push_swap, char **av, int ac);

#endif
