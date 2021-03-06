/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <aldamien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:48:22 by aldamien          #+#    #+#             */
/*   Updated: 2020/12/04 18:24:12 by aldamien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

int				get_next_line(int fd, char **line);
int				get_next_line1(int fd, char **line);
void			get_next_line2(char *buf, char **tmp, char **chain);
unsigned int	ft_strlen(const char *s);
char			*ft_strdup(const char *src);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strchr(const char *s, int c);
char			*ft_substr(const char *s, unsigned int start, size_t len);

#endif
