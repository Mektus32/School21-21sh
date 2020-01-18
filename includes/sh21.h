#ifndef SH21_H
# define SH21_H

# include "libft.h"
# include "ft_printf.h"
# include "keys.h"
# include <stdio.h>
# include <curses.h>
# include <term.h>
# include <termios.h>
# include <fcntl.h>

extern int g_fd;

/*
** input mode
*/
# define STANDART_MODE 1 //if cursor 'x' is 0 then check 'y' and move on prev line or don't move
# define QUOTES_MODE 2 //if cursor 'x' if 0 then don't move
# define HISTORY_MODE 3 //if cursor 'x' is 0 then check 'y' and move on prev line or don't move. mb have something else

/*
** struct with line params.
** buffer, string lenght, cursor x coordinate and y.
** flag for input mode
*/
typedef struct	s_params_line
{
	int		input_mode;
	char	*str;
	int		str_len;
	int		cursor_x;
	int		cursor_y;
}				t_params_line;

/*
** struct with environment
*/
typedef struct	s_environ
{
	char	**current_env;

}				t_environ;

/*
** struct with params about terminal mode
*/
typedef struct	s_terminal_mode
{
	struct termios	oldt;
	BOOL			is_set;
}				t_terminal_mode;

/*
** general struct
*/
typedef struct	s_general
{
	t_params_line	line_params;
	t_environ		environ;
	t_terminal_mode	mode;
	int				debug_fd;
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

/*
** main_loop.c
*/
void				main_loop(t_general *sh);

/*
** small_functions.c
*/
int					print_ch(int ch);
void				ft_exit(int status);
void print_command(char *str, long ch);

/*
** key_handler.c
*/
void keys(long ch, t_params_line *cursor);

/*
** functions_for_move.c
*/
void	ft_left_arrow(t_params_line *cursor);
void	ft_right_arrow(t_params_line *cursor);

/*
** functions_for_get_coordinates.c
*/
int		get_len_line(char *str, int y);
void	get_x_y_after_print(char *str, int *x, int *y);
int		get_index(char *str, int y, int x);

/*
** print_functions.c
*/
void	ft_print_buffer(t_params_line *cursor);

#endif
