#include "sh21.h"

BOOL	quotes(t_params_line *cursor, char ch)
{
	if (ch == '\"')
	{
		if (cursor->count_single_quotes)
			return (TRUE);
		else if (cursor->count_double_quotes)
			--cursor->count_double_quotes;
		else
			++cursor->count_double_quotes;
	}
	else
	{
		if (cursor->count_double_quotes)
			return (TRUE);
		else if (cursor->count_single_quotes)
			--cursor->count_single_quotes;
		else
			++cursor->count_single_quotes;
	}
	return (cursor->count_double_quotes || cursor->count_single_quotes);
}