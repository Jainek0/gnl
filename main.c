// empty test.txt

 #include <fcntl.h>
 #include <stdio.h>
 #include "get_next_line.h"

int main()
{
	// int	fd;
	// int	i;
	// char *nextl;

	// i = 1;
	// fd = open("test.txt", O_RDONLY);

	

	// nextl = (char *) get_next_line(fd);
	// printf("[1]%s", nextl);

	
	// while (nextl)
	// {
	// 	i++;
	// 	free(nextl);
	// 	nextl = get_next_line(fd);
	// 	printf("[%d]%s", i, nextl);

	// 	close(fd);
	// }
	// free(nextl);

	// int fd = open("test.txt", O_RDONLY);
	int fd = 404;
	char *str = get_next_line(fd);

	while (str)
	{
		printf("%s",str);
		free(str);
		str = get_next_line(fd);
	}
	free(str);

}