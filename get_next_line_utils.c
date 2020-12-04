/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldamien <aldamien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:56:50 by aldamien          #+#    #+#             */
/*   Updated: 2020/12/04 12:45:42 by aldamien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while ((s[i] != c) && (s[i] != '\0'))
		i++;
	if (s[i] == '\0' && c != '\0')
		return (NULL);
	return ((char *)s + i);
}

unsigned int	ft_strlen(const char *s)
{
	unsigned int	j;

	j = 0;
	while (s[j] != 0)
		j++;
	return (j);
}

char			*ft_strdup(const char *s)
{
	char	*s2;
	int		i;
	int		size;

	i = 0;
	size = ft_strlen(s);
	if (s == 0)
	{
		s2 = 0;
		return (s2);
	}
	if (!(s2 = malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (i < size)
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char			*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len;
	char	*s3;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!(s1 && s2))
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(s3 = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		s3[i + j] = s2[j];
		j++;
	}
	s3[i + j] = '\0';
	return (s3);
}

char			*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*new;
	unsigned int	s_len;
	unsigned int	i;

	s_len = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start > s_len)
	{
		if (!(new = malloc(sizeof(char) + 1)))
			return (NULL);
		new[0] = '\0';
		return (new);
	}
	if (s_len < start + len)
		len = s_len - start;
	if (!(new = malloc(sizeof(char) * s_len)))
		return (NULL);
	i = -1;
	while (++i < len && s[start + i])
		new[i] = s[start +i];
	new[i] = '\0';
	return (new);
}
