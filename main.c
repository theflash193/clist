#include <stdlib.h>
#include <stdio.h>

typedef struct		s_clist
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
	struct s_list	*prev;
}					t_clist;

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

t_clist	*ft_clstnew(void const *content, size_t content_size)
{
	t_clist	*ret;

	if (!(ret = (t_clist *)malloc(sizeof(t_clist))))
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

void	ft_clstadd(t_list **alst, t_list *new)
{
	t_list	*tmp;

	tmp = *alst;
	if (!tmp)
		*alst = new;
	else
	{
		new->next = tmp;
		*alst = new;
	}
}

int main(int argc, char const *argv[]) {
	t_clist *clist;
	int i;

	i = 42;
	clist = NULL;
	clist = ft_clstnew(&i, sizeof(int));
	int *a = clist->content;
	printf("elem->content %d\n", *a);
	return 0;
}