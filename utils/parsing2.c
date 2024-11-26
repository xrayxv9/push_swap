/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:05:12 by cmorel            #+#    #+#             */
/*   Updated: 2024/11/26 17:07:36 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_utils.h"

t_list *error(t_list *l)
{
	ft_printf("Error\n");
	if (l)
		ft_lstclear(&l);
	return (NULL);
}

int check_strings(char *s)
{
	int	i;

	i = 0;
	while (s[i] && !(s[i] >= '0' && s[i] <= '9'))
		i++;
	if (s[i] == '\0')
		return (0);
	return (1);
}

int	ft_check_overflow(char *s, int overflow)
{
	char	*over;
	int		i;
	int		code;

	over = ft_itoa(overflow);
	i = 0;
	code = 1;
	while (over[i] && s[i])
	{
		if (over[i] != s[i])
		{
			code = 0;
			break ;
		}
		i++;
	}
	if (s[i] != ' ' && !(s[i] >= '\t' && s[i] <= '\r'))
		code = 0;
	free(over);
	return (code);
}

int	check_space(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			return (1);
		i++;
	}
	return (0);
}
