#include "minitalk.h"

pid_t	get_numid(char *arg)
{
	int num;

	num = 0;
	while (*arg)
	{
		if ('0' <= *arg && *arg <= '9')
		{
			num = (num * 10) + *arg - '0';
		}
		else
			return (-1);
		arg++;
	}
	printf ("%i", num);
	return (num);
}

int	main(int argc, char **argv)
{
	pid_t			num_id;

	if (argc != 3)
	{
		write (1, "Error\n", 6);
		return (1);
	}
	num_id = get_numid(argv[1]);
	if(num_id <= 1)
	{
		write (1, "Error?\n", 7);
		return (1);
	}
	mess_received = 0;

	if (!mess_received)
		sleep(10);
	if(mess_received)
		return (0);
	write (1, "Error!\n", 7);
	return (1);
}