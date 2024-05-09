char	*get_line(static char *leftover, char *line)
{
	char	*new_line;
	char	*temp;
	int	len;
	
	len = ft_strchr(leftover, '\n') - leftover;
	new_line = ft_strlcpy(leftover, len);
	temp = ft_substr(leftover, len, ft_strlen(leftover) - len);
	free(leftover);
	if (temp != NULL)
		leftover = ft_strjoin(NULL, temp);	
	free(temp);
	return (new_line);
}

void	get_entire_line(char *buffer, static char *leftover, int fd)
{
	char	*temp;
	int	len;

	len = 0;	
	temp = NULL;
	while (!ft_strchr(leftover, '\n'))
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len <= 0)
			break ;
		buffer[len] = '\0';
		temp = ft_strjoin(leftover, buffer);
		free(leftover);
		leftover = ft_strcpy(leftover, temp);
		free(temp);
	}
	return (leftover);
	// je recupere avant le \n je le renvoi et je stock ce qu'il uy a apres .

}

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*line;
	static char	*leftover;

	get_entire_line(buffer, leftover, fd)

	// verrifier si leftover est nul ne pas oublier.
	
	line = get_line(leftover, line);
	return (line);
}
