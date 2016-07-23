/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clst.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 15:38:06 by grass-kw          #+#    #+#             */
/*   Updated: 2016/07/23 16:20:29 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLST_H
# define CLST_H
# include <stdlib.h>

typedef struct		s_clst
{
	void			*content;
	size_t			content_size;
	struct s_clst	*next;
	struct s_clst	*prev;
}					t_clst;

t_clst				*clst_new(void const *content, size_t content_size);
void				clst_iter(t_clst *alst, void (*f)(t_clst *));
void				clst_push_front(t_clst **alst, t_clst *new);
void				clst_push_back(t_clst **alst, t_clst *new);
t_clst				*clst_first_link(t_clst *alst);
t_clst				*clst_last_link(t_clst *alst);
void				clst_iter(t_clst *alst, void (*f)(t_clst *));
t_clst				*clst_map(t_clst *alst, t_clst *(*f)(t_clst *));
void				clst_delone(t_clst **alst, void (*f)(void *, size_t));
void				clst_del(t_clst **alst, void (*del)(void *, size_t));

#endif
