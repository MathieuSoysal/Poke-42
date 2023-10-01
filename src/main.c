/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:55:51 by poss              #+#    #+#             */
/*   Updated: 2023/10/01 12:47:30 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"
#include "temp.h"
#include <stdio.h>

int	main(void)
{
	int	c;

	if (get42() == 42)
	{
		ft_putstr("yo\n");
	}
	c = ft_getc_fd(STDIN);
	if (c == EOF)
		printf("EOF\n");
	else
		printf("the char is %c\n", c);
}
