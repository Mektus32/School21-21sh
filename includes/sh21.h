#ifndef SH21_H
# define SH21_H

# include "libft.h"
# include "ft_printf.h"
# include <stdio.h>
# include <curses.h>
# include <term.h>
# include <termios.h>
# include <fcntl.h>

/*
** keys to move cursor
*/
# define LEFT_ARROW 4479771
# define RIGHT_ARROW 4414235
# define CTR_UP_ARROW 71696882162459
# define CTR_DOWN_ARROW 72796393790235

/*
** keys to check history
*/
# define UP_ARROW 4283163
# define DOWN_ARROW 4348699

/*
** keys to copying text
*/
# define CTR_A_LEFT_ARROW 7499541704577499
# define CTR_A_RIGHT_ARROW 73895905418011
# define CTR_A_UP_ARROW 71696882162459
# define CTR_A_DOWN_ARROW 72796393790235

/*
** key to paste text
*/
# define CTR_P 16

/*
** keys to movement according to
*/
# define CTR_LEFT 74995417045787
# define CTR_RIGHT 73895905418011

/*
** keys home/end
*/
# define HOME 4741916
# define END 4610843

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

/*
** key_handler.c
*/
void keys(long ch, t_params_line cursor);

#endif
