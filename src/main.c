/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:59:35 by cmorel            #+#    #+#             */
/*   Updated: 2024/12/13 15:09:49 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../parsing/parsing.h"
#include "../utils/utils.h"
#include "../sort/sort.h"

int	main(int argc, char **argv)
{
	t_list	*sa;
	t_list	*sb;

	sb = NULL;
	sa = NULL;
	if (argc < 2)
		return (-1);
	sa = parsing(argc, argv, sa);
	if (!sa)
		return (-1);
	if (!is_sorted(sa))
		give_index(&sa, &sb);
	if (sa)
		ft_lstclear(&sa);
}
