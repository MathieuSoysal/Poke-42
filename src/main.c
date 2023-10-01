/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:55:51 by poss              #+#    #+#             */
/*   Updated: 2023/10/01 13:11:15 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "combat.h"
#include "io.h"

int	main(void)
{
	t_action	action;

	prompt_action();
	action = get_action();
	if (action == ATTACK)
		ft_putstr("pikachu ATTACK\n");
	else if (action == OBJECT)
		ft_putstr("eat this pikachu\n");
	else
		ft_putstr("invalid action\n");
}
