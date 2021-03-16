int					main(int ac, char **av)
{
	char	*line;
	int		fd1;

	ac = 0;
	av[1] = "./file1.txt";
	fd1 = open(av[1], O_RDONLY);
	get_next_line(fd1, &line);
	printf("%s\n", line);
	get_next_line(fd1, &line);
	printf("%s\n", line);
	return (0);
}