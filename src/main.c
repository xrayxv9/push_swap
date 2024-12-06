/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:59:35 by cmorel            #+#    #+#             */
/*   Updated: 2024/12/06 14:51:32 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../parsing/parsing.h"
#include "../utils/utils.h"
#include "../sort/sort.h"

int	main(int argc, char **argv)
{
	t_list	*s;
	
	s = NULL;
	if (argc < 2)
	{
		ft_printf("Could you please give me something to sort ?");
		return (-1);
	}
	s = parsing(argc, argv, s);
	if (!s)
		return (-1);
	if (!is_sorted(s))
		give_index(&s);
	else 
		ft_printf("The given list is Already sorted.");
	if (s)
		ft_lstclear(&s);
}
