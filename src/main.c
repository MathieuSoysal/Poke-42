/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:55:51 by poss              #+#    #+#             */
/*   Updated: 2023/10/01 11:55:52 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "temp.h"
#include <unistd.h>

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
