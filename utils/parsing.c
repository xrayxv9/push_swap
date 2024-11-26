/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:13:14 by cmorel            #+#    #+#             */
/*   Updated: 2024/11/26 10:24:48 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_utils.h"

int	ft_is_digit(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!(s[i] == ' ' || (s[i] >= '\t' && s[i] <= '\r') ||
				(s[i] >= '0' && s[i] <= '9') || s[i] == '+' || 
				s[i] == '-'))
			return (0);
		i++;
	}
	return (1);
}

void	add(int *i, int *space, int *sign, char c)
{
	(*i)++;
	if (space)
		(*space)++;
	if (sign)
	{
		if (c == '-')
			(*sign) = -1;
	}
}

int	addlist(char *s, t_list **l, int i, int space)
{
	int		nbr;
	int		sign;

	while (s[i])
	{
		nbr = 0;
		sign = 1;
		while (s[i] == ' ' || (s[i] >= '\t' && s[i] <= '\r'))
			add(&i, &space, NULL, '0');
		if (s[i] == '+' || s[i] == '-')
			add(&i, NULL, &sign, s[i]);
		while (s[i] >= '0' && s[i] <= '9')
		{
			nbr = nbr * 10 + (s[i] - '0');
			i++;
		}
		if (space - 1 > 0)
			ft_lstadd_back(l,  ft_lstnew(nbr * sign));
		else 
			return (0);
		break ;
	}
	if (s[i] != '\0')
		return (addlist(s, l, i, 1));
	return (1);
}

int	check_doubles(t_list *l)
{
	t_list	*curr;
	t_list	*f;

	f = l;
	while (f)
	{
		curr = f->next;
		while (curr)
		{
			if (curr->content == f->content)
				return (0);
			curr = curr->next;
		}
		f = f->next;
	}
	return (1);
}

t_list	*parsing(int argc, char **t, t_list *l)
{
	int		i;

	i = 1;
	l = NULL;
	while (i < argc)
	{
		if (!ft_is_digit(t[i]))
			return (error(0, l));
		if (!addlist(t[i], &l, 0, 2))
			return (error(1, l));
		i++;
	}
	if (!check_doubles(l))
		return (error(2, l));
	return (l);
}
