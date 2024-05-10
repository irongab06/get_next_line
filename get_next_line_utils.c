/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:24:35 by gacavali          #+#    #+#             */
/*   Updated: 2024/05/09 13:14:12 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = NULL;
	s2 = malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (s2 == NULL)
		return (0);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	d;

	d = (char)c;
	i = 0;
	if (!s)
		return (NULL);
	if (s[i] == '\0' && d == '\0')
		return (&((char *)s)[i]);
	while (s[i] || d == '\0')
	{
		if (s[i] == d)
			return (&((char *)s)[i]);
		i++;
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*s1;
	size_t				i;
	unsigned int		s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	s1 = NULL;
	i = 0;
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	s1 = malloc(sizeof(char) * len + 1);
	if (s1 == NULL)
		return (NULL);
	while (s[start + i] && i < len)
	{
		s1[i] = s[start + i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;
	size_t	n;
	size_t	i;

	i = 0;
	n = (count * size);
	if ((count >= 65535 && size >= 65535) || count * size >= 65535)
		return (NULL);
	s = malloc(count * size);
	if (s == NULL)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
	return (s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*new_s;

	if (s1 == NULL && s2 == NULL)
	{
		new_s = ft_calloc(1, 1);
		return (new_s);
	}
	i = 0;
	if (s1 != NULL)
		i = ft_strlen(s1);
	if (s2 != NULL)
		i += ft_strlen(s2);
	new_s = ft_calloc(sizeof(char), i + 1);
	if (new_s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[j])
		new_s[i++] = s1[j++];
	j = 0;
	while (s2 && s2[j])
		new_s[i++] = s2[j++];
	return (new_s);
}
