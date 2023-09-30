#include <unistd.h>

#include "temp.h"

void	ft_putstr(const char *str);
void	ft_putchar(char c);

int	main(void)
{
	if (get42() == 42)
	{
		ft_putstr("yo\n");
	}
}

void	ft_putstr(const char *str)
{
	while (*str)
	{
		ft_putchar(*str++);
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
