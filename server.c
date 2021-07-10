#include "minitalk.h"


void	put_id(pid_t id)
{
	char c_id;

	if (!id)
		return ;
	put_id(id / 10);
	c_id = (id % 10) + '0';
	write (1, &c_id , 1);
}

int	main(int argc, char **argv)
{
	pid_t			id;

	if (argc != 1)
	{
		write (1, "Error\n", 6);
		return (-1);
	}

	id = getpid();
	write (1, "Use this to send a message:", 27);
	put_id(id);
	write (1, "\n", 1);

	while (1)
		pause();
	(void)argv;
	return (0);
}
