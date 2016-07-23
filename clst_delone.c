/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clist_delone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 16:06:13 by grass-kw          #+#    #+#             */
/*   Updated: 2016/07/23 16:06:19 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clst.h"

void	clst_delone(t_clst **alst, void (*f)(void *, size_t))
{
	f((*alst)->content, (*alst)->content_size);
	free((*alst));
	*alst = NULL;
}
