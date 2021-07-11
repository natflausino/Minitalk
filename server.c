#include "minitalk.h"

//o server vai receber --> ele vai tranformar um conjunto de bits numa string
void	sighandler(int signum)
{
	static int	str;
	static int	len;

	//len = 0;
	//str = 0;
	if (signum == SIGUSR1)
	{
		str = str + (1 << (7 - len)); // mexer nos parenteses
	}
	if ((len++) == 8)
	{
		write(1, &str, 1);
		len = 0;
		str = 0;
	}
}

int	verify_signal(void)
{
	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
	return (0);
}

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
	verify_signal();
	id = getpid();
	write (1, "Use this to send a message:", 27);
	put_id(id);
	write (1, "\n", 1);
	while (1)
		pause();
	(void)argv;
	return (0);
}
