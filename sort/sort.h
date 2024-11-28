/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xray <xray@42angouleme.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:28:46 by xray              #+#    #+#             */
/*   Updated: 2024/11/28 15:35:20 by xray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SORT_H
# define SORT_H

# include "../parsing/parsing.h"
# include "../utils/utils.h"

typedef struct s_psort
{
	int	first;
	int	second;
	int	third;
	int	fourth;
	int	to_displace;
	int	len;
	int	first_l;
	int	second_l;
	int	third_l;
}		t_psort;

void	pre_sort(t_list	*s);

void	get_info(t_psort *ps, t_list *s);



#endif
