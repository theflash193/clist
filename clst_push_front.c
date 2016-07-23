/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clst_push_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 16:10:28 by grass-kw          #+#    #+#             */
/*   Updated: 2016/07/23 16:11:01 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clst.h"

void	clst_push_front(t_clst **alst, t_clst *new)
{
	t_clst	*last;
	t_clst	*second;

	if (!*alst)
	{
		*alst = new;
		new->next = new;
		new->prev = new;
		return ;
	}
	last = (*alst)->prev;
	second = *alst;
	new->next = second;
	new->prev = last;
	second->prev = new;
	last->next = new;
	*alst = new;
}
