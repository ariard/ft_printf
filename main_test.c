#include "ft_printf.h"


int			main(void)
{

	wchar_t		w;

	w = L'我';

	ft_putnbr(ft_sizewchar(w));
	return (0);
}
