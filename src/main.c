#include "sh21.h"

void init(t_general *sh, char **env)
{
	struct termios old;
	sh->environ.current_env = ft_twarrcpy((const char**)env, INT_MAX);
	tcgetattr(STDIN_FILENO, &old);
	sh->mode.oldt = (const struct termios)old;
	sh->mode.is_set = FALSE;
	change_terminal_mode("raw", &sh->mode);
}

int		main(int argc, char **argv, char **env)
{
	t_general sh;

	//argc > 1 ? usage() : 0;
	init(&sh, env);
	main_loop(&sh);
    ft_printf("Hello 21sh\n");
    return (0);
}
