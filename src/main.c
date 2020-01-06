#include "sh21.h"

void init(t_general *sh, char **env)
{
	sh->current_env = ft_twarrcpy(env, INT_MAX);
}



int		main(int argc, char **argv, char **env)
{
	t_general sh;

	argc > 1 ? usage() : 0;
	init(&sh, env);
	change_terminal_mode();
	main_loop(&sh);
    ft_printf("Hello 21sh\n");
    return (0);
}
