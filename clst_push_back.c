/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clst_push_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 16:10:04 by grass-kw          #+#    #+#             */
/*   Updated: 2016/07/23 16:20:48 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clst.h"

void	clst_push_back(t_clst **alst, t_clst *new)
{
	t_clst	*first;
	t_clst	*before_last;

	if (*alst == NULL)
	{
		*alst = new;
		new->next = new;
		new->prev = new;
		return ;
	}
	first = *alst;
	before_last = first;
	while (before_last->next != first)
		before_last = before_last->next;
	before_last->next = new;
	first->prev = new;
	new->next = first;
	new->prev = before_last;
}
