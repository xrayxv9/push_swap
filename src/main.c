/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:59:35 by cmorel            #+#    #+#             */
/*   Updated: 2024/12/01 17:30:43 by xray             ###   ########.fr       */
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
	if (!s)
		return (-1);
	if (!is_sorted(s))
	{
		pre_sort(s);
		ft_lstclear(&s);
		ft_lstclear(&s2);
	}
	else 
		ft_printf("The given list is Already sorted.");
}
