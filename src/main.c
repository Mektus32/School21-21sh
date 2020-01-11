#include "sh21.h"

void init(t_general *sh, char **env)
{
	struct termios	old;
	const char		*name = getenv("TERM");

	sh->debug_fd = open("debug_print", O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, S_IWRITE);
	sh->environ.current_env = ft_twarrcpy((const char**)env, INT_MAX);
	tcgetattr(STDIN_FILENO, &old);
	sh->mode.oldt = (const struct termios)old;
	sh->mode.is_set = FALSE;
	change_terminal_mode("raw", &sh->mode);
//	if (tgetent(NULL, name) != 1)
//		ft_exit(1);
	sh->line_params.cursor_x = 0;
	sh->line_params.cursor_y = 0;
	write(sh->debug_fd, "kek", 3);
//	ft_printf("{set:fd} fdfsfdsf %s", sh->debug_fd, "ewew");
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
