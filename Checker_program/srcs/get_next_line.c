/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 20:55:37 by ahaddad           #+#    #+#             */
/*   Updated: 2021/04/14 13:32:51 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static	int		get_line(char **new, int n, char **line, int fd)
{
	char		*temp;
	int			i;

	i = 0;
	while (new[fd][i] && new[fd][i] != '\n')
		i++;
	*line = ft_strsub(new[fd], 0, i);
	if (!new[fd][i])
	{
		temp = new[fd];
		new[fd] = NULL;
		free(temp);
		return (0);
	}
	else
	{
		temp = new[fd];
		new[fd] = ft_strdup((new[fd]) + i + 1);
		free(temp);
	}
	if (!new[fd] || !*line)
		return (-1);
	if (n || (n == 0 && new[fd] != NULL))
		return (1);
	return (-1);
}

int				get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*rt[4864];
	char		*tmp;
	int			r;

	buf = NULL;
	if (!line || fd < 0 || fd >= 4864 || BUFFER_SIZE <= 0
			|| !(buf = malloc(BUFFER_SIZE + 1)) || read(fd, buf, 0) == -1)
		return (-1);
	if (!rt[fd])
		if (!(rt[fd] = ft_strdup("")))
			return (-1);
	while ((!ft_strchr(rt[fd], '\n')) && (r = read(fd, buf, BUFFER_SIZE)))
	{
		if (r < 0)
			return (-1);
		tmp = rt[fd];
		buf[r] = '\0';
		if (!(rt[fd] = ft_strjoin(rt[fd], buf)))
			return (-1);
		free(tmp);
	}
	free(buf);
	return (get_line(rt, r, line, fd));
}
