/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:59:35 by cmorel            #+#    #+#             */
/*   Updated: 2024/11/28 17:55:11 by xray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../parsing/parsing.h"
#include "../utils/utils.h"
#include "../sort/sort.h"

int	main(int argc, char **argv)
{
	t_list	*s;
	t_list	*s2;
	
	s = NULL;
	s2 = NULL;
	if (argc < 2)
	{
		ft_printf("Could you please give me something to sort ?");
		return (-1);
	}
	s = parsing(argc, argv, s);
	if (!is_sorted(s))
	{
		pre_sort(s);
	}
	else 
		ft_printf("The given list is Already sorted.");
	ft_lstclear(&s);
	ft_lstclear(&s2);
}
