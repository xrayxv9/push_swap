/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:05:12 by cmorel            #+#    #+#             */
/*   Updated: 2024/11/26 11:10:53 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_utils.h"

t_list *error(int error, t_list *l)
{
	ft_lstclear(&l);
	ft_printf("Error\n");
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
