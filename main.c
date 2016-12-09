#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>
#include <locale.h>

int		main(void)
{
	int		len2;
	int		len;

	len2 = 0;
	len = 0;

	int	c;
	char	*s;

	s = setlocale(LC_ALL, "");
	len = ft_printf("%6C\n", 945);
	ft_putchar(10);
	len2 = printf("%6C\n", 945);
	printf("\n\n");
	ft_putchar(10);
	ft_putnbr(len);
	ft_putchar(10);
	ft_putnbr(len2);

	return (0);
}
