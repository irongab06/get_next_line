char	*get_next_line(int fd)
{
	int	file;
	char	*buffer_size;
	
	buffer = NULL;
	file = open("get_next_line.txt", O_RDONLY);
	if (file == -1)
	{
		write(1, "Error1\n", 7);
		return ;
	}

}
