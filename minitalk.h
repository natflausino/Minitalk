#ifndef MINITALK_H
# define MINITALK_H


# include <signal.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>


int	mess_received;
/*
* SERVER FUNCTIONS
*/

void	put_id(pid_t id);

/*
* CLIENT FUNCTIONS
*/

pid_t	get_numid(char *arg);

#endif