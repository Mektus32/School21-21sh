#ifndef SH21_H
# define SH21_H

# include "libft.h"
# include "ft_printf.h"
# include <stdio.h>
# include <curses.h>
# include <term.h>
# include <termios.h>

typedef struct	s_general
{
	char	*terminal_buffer;
	char	**current_env;
	char	*prompt;
}				t_general;

/*
** main.c
*/
void			init(t_general *sh, char **env);

/*
** terminal_mode.c
*/
void			change_terminal_mode();

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

#endif
