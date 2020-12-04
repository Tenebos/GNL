/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <aldamien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 16:22:23 by aldamien          #+#    #+#             */
/*   Updated: 2020/12/04 16:35:32 by aldamien         ###   ########.fr       */
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
	char		*buf;
	static char	*chain;
	int			ret;
	char		*tmp;

	if (fd == -1 || !line || !(buf = malloc(sizeof(char) * BUFFER_SIZE + 1))
		|| read(fd, buf, 0) == -1 || BUFFER_SIZE <= 0)
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
	free(buf);
	return (ret);
}

int		main()
{
	int		fd;
	char	*line;
	int		i;
	int		ret;

	i = 1;
	fd = open("42", O_RDONLY);
	if (fd == -1)
	{
		printf("open() error");
		return (1);
	}
	while (i <= 4)
	{
		i++;
		ret = get_next_line(fd, &line);
		if (ret >= 0)
		{
			printf("line externe : %s\n\n", line);
			free(line);
		}
	}
	close (fd);
}
