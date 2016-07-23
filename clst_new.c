/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clst_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 16:09:37 by grass-kw          #+#    #+#             */
/*   Updated: 2016/07/23 16:18:06 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clst.h"

static void	clst_bzero(void *s, size_t n)
{
	char	*tmp;

	tmp = (char *)s;
	while (n--)
	{
		*tmp = (unsigned char)0;
		tmp++;
	}
}

static void	*clst_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char	*tmp_src;
	unsigned char	*tmp_dst;

	tmp_src = (unsigned char *)src;
	tmp_dst = (unsigned char *)dst;
	while (len--)
	{
		*tmp_dst = *tmp_src;
		tmp_src++;
		tmp_dst++;
	}
	return ((void *)tmp_dst);
}

static void	*clst_memalloc(size_t size)
{
	void	*ret;

	if (!size || !(ret = malloc(size)))
		return (NULL);
	clst_bzero(ret, size);
	return (ret);
}

t_clst		*clst_new(void const *content, size_t content_size)
{
	t_clst	*ret;

	if (!(ret = (t_clst *)malloc(sizeof(t_clst))))
		return (NULL);
	ret->content = clst_memalloc(content_size);
	if (!content)
		ret->content = NULL;
	else
		clst_memcpy(ret->content, content, content_size);
	ret->content_size = 0;
	ret->next = NULL;
	ret->prev = NULL;
	return (ret);
}
