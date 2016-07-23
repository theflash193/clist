/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clst_iter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 16:08:10 by grass-kw          #+#    #+#             */
/*   Updated: 2016/07/23 16:08:20 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clst.h"

void	clst_iter(t_clst *alst, void (*f)(t_clst *))
{
	t_clst *cursor;

	cursor = alst;
	if (cursor == NULL)
		return ;
	f(cursor);
	while (cursor->next != alst && cursor != NULL)
	{
		cursor = cursor->next;
		f(cursor);
	}
}
