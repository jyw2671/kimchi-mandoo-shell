#include "minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	int	i;

	printf("minishell!\n");
	i = 0;
	while (i < argc)
		printf("%s\n", argv[i++]);

	i = 0;
	while (envp[i])
		printf("%s\n", envp[i++]);

	return (0);
}
