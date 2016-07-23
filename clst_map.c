/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clist_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 16:06:32 by grass-kw          #+#    #+#             */
/*   Updated: 2016/07/23 16:06:52 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clst.h"

t_clst	*clst_map(t_clst *alst, t_clst *(*f)(t_clst *))
{
	t_clst *new_clst;
	t_clst	*cursor;

	cursor = alst;
	new_clst = NULL;
	if (cursor == NULL)
		return (NULL);
	clst_push_back(&new_clst, f(cursor));
	while (cursor->next != alst)
	{
		cursor = cursor->next;
		clst_push_back(&new_clst, f(cursor));
	}
	return (new_clst);
}
