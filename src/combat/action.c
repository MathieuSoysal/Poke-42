/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 12:59:09 by poss              #+#    #+#             */
/*   Updated: 2023/10/01 13:18:35 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "combat.h"
#include "io.h"

t_action	get_action(void)
{
	char	c;

	c = ft_getc_fd(STDIN);
	if (c == 'A')
		return (ATTACK);
	if (c == 'O')
		return (OBJECT);
	return (INVALID);
}

void	prompt_action(void)
{
	ft_putstr("Your turn:\n");
	ft_putstr("\t(A)ttack\n");
	ft_putstr("\t(O)bject\n");
}
