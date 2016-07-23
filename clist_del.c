/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clist_del.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 16:05:28 by grass-kw          #+#    #+#             */
/*   Updated: 2016/07/23 16:29:08 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clst.h"

void	clst_del(t_clst **alst, void (*del)(void *, size_t))
{
	t_clst	*cursor;
	t_clst	*delete;
	t_clst	*last;

	if (*alst == NULL)
		return ;
	last = (*alst)->prev;
	last->next = NULL;
	cursor = *alst;
	while (cursor)
	{
		delete = cursor;
		cursor = cursor->next;
		delete->prev = NULL;
		delete->next = NULL;
		clst_delone(&delete, (*del));
	}
	*alst = NULL;
}
