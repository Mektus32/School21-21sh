#include "sh21.h"

int		g_fd;

void init(t_general *sh, char **env)
{
	struct termios	old;
	const char		*name = getenv("TERM");

	sh->debug_fd = open("debug_print", O_CREAT | O_WRONLY | O_TRUNC | O_APPEND/*, S_IWRITE*/);
	g_fd = sh->debug_fd;
	sh->environ.current_env = ft_twarrcpy((const char**)env, INT_MAX);
	tcgetattr(STDIN_FILENO, &old);
	sh->mode.oldt = (const struct termios)old;
	sh->mode.is_set = FALSE;
	change_terminal_mode("raw", &sh->mode);
	if (tgetent(NULL, name) != 1)
		ft_exit(1);
	sh->line_params.input_mode = STANDART_MODE;
	ft_printf("{set:fd}init is done\n", g_fd);
}

int		main(int argc, char **argv, char **env)
{
	t_general sh;
	long	a = 0;

	//argc > 1 ? usage() : 0;
	init(&sh, env);
	main_loop(&sh);
	change_terminal_mode("std", &sh.mode);
    return (0);
}
