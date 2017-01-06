#include "get_next_line.h"
#include "libft.h"

int     main(int argc, char **argv)
{
	int fd;
	//int fd2;
	int ret;
	char **line;

	line  = (char **)malloc(sizeof(char*));
	*line = ft_strnew(BUFF_SIZE);
	if (argc == 1)
		write(2, "File name missing.\n", 19);
	if (argc >= 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			return (1);
		while ((ret = get_next_line(fd, line)) == 1)
		{
			ft_putstr(*line);
			//;
		}
		 close(fd);
	}
}
