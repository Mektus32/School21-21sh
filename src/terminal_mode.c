#include "sh21.h"

void change_terminal_mode()
{
	static struct termios oldt;
	static struct termios newt;

	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	newt.c_cc[VTIME] = 0;
	newt.c_cc[VMIN] = 1;
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}
