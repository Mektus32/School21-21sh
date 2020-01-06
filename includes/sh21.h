#ifndef SH21_H
# define SH21_H

# include "libft.h"
# include "ft_printf.h"
# include <stdio.h>
# include <curses.h>
# include <term.h>
# include <termios.h>

typedef struct	s_params_line
{
	char	*str;
	int		str_len;
	int		cursor_x;
	int		cursor_y;
}				t_params_line;

typedef struct	s_environ
{
	char	**current_env;

}				t_environ;

typedef struct	s_terminal_mode
{
	struct termios	oldt;
	BOOL			is_set;
}				t_terminal_mode;

typedef struct	s_general
{
	t_params_line	line_params;
	t_environ		environ;
	t_terminal_mode	mode;
}				t_general;

/*
** main.c
*/
void			init(t_general *sh, char **env);

/*
** terminal_mode.c
*/
void change_terminal_mode(char *mode, t_terminal_mode *term);

/*
** output_functions.c
*/
void				usage();
void				print_error(char *error);

/*
** read_buffer.c
*/
char *read_buffer(t_general *sh);
void quotes(int *count_double_quotes, int *count_quotes, char ch);

/*
** main_loop.c
*/
void				main_loop(t_general *sh);

/*
** small_functions.c
*/
int					print_ch(int ch);
void				ft_exit(int status);

#endif
