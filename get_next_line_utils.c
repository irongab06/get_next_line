/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:24:35 by gacavali          #+#    #+#             */
/*   Updated: 2024/05/07 15:28:03 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}


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
