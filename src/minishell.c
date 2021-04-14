#include "minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	(void)envp;
	printf("minishell!\n");
	exec_cmd(parse_cmd(argv[argc - 1]));
	return (0);
}
