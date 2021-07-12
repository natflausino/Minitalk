#ifndef MINITALK_H
# define MINITALK_H


# include <signal.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>

int	g_mess_received;
/*
* SERVER FUNCTIONS
*/

void	put_id(pid_t id);
int	setup_handlers(void);
void	sig_action(int signum, siginfo_t *info, void *ucontext);
void	receive_message(int num_bit, pid_t id_client);

/*
* CLIENT FUNCTIONS
*/

pid_t	get_numid(char *arg);
int	send_message(char *arg, pid_t num_id);
void check_message(int signum);

#endif