/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poss <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 12:54:32 by poss              #+#    #+#             */
/*   Updated: 2023/10/01 13:07:10 by poss             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMBAT_H
# define COMBAT_H

typedef enum e_action
{
	ATTACK,
	OBJECT,
	INVALID,
}			t_action;

void		prompt_action(void);
t_action	get_action(void);

#endif
