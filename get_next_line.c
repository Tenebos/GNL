/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <aldamien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 16:22:23 by aldamien          #+#    #+#             */
/*   Updated: 2020/12/04 18:33:43 by aldamien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	get_next_line2(char *buf, char **tmp, char **chain)
{
	if (*chain == NULL)
		*chain = ft_strdup(buf);
	else
	{
		*tmp = ft_strdup(*chain);
		free(*chain);
		*chain = ft_strjoin(*tmp, buf);
		free(*tmp);
	}
}

int		get_next_line(int fd, char **line)
{
	if (BUFFER_SIZE <= 0)
		return(-1);
	else
		return (get_next_line1(fd, line));
}

int		get_next_line1(int fd, char **line)
{
	static char	buf[BUFFER_SIZE + 1];
	static char	*chain;
	int			ret;
	char		*tmp;

	if (fd == -1 || !line || read(fd, buf, 0) == -1 || BUFFER_SIZE <= 0)
		return (-1);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0 || chain[0] != '\0')
	{
		buf[ret] = '\0';
		get_next_line2(buf, &tmp, &chain);
		if (ft_strchr(chain, '\n'))
		{
			*line = ft_substr(chain, 0, ft_strlen(chain) -
				ft_strlen(ft_strchr(chain, '\n')));
			chain = ft_strdup(ft_strchr(chain, '\n') + 1);
			break ;
		}
	}
	return (ret);
}
