/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacavali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:30:01 by gacavali          #+#    #+#             */
/*   Updated: 2024/05/06 13:45:08 by gacavali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>

static size_t	ft_strlen_bis(const char *dst)
{
	size_t	i;

	i = 0;
	while (dst[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	len_dst;
	size_t	i;

	len_dst = ft_strlen_bis(dst);
	i = 0;
	if (size == 0)
		return (ft_strlen_bis(src));
	if (size < len_dst)
		return (ft_strlen_bis(src) + size);
	if (dst && src && size)
	{
		while (src[i] && (i + len_dst) < size - 1)
		{
			dst[len_dst + i] = src[i];
			i++;
		}
	}
	dst[len_dst + i] = '\0';
	return (len_dst + ft_strlen_bis(src));
}

char	*get_next_line(int fd)
{
	int	status;
	char	*buffer;
	char	*str;
	
	status = read(fd, buffer, sizeof(*buffer));
	printf("%d", fd);
	str = ft_strlcat(str, buffer, 30);
	return (str);
	
}

int	main(void)
{
	char	*str;
	int	fd;
	
	
	fd = open("get_next_line.txt", O_RDONLY);
	if (fd == -1)
	{
		write(1, "Error1\n", 7);
		return (1);
	}
	str = get_next_line(fd);
	printf("%s", str);
	return (0);
}
