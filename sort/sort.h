/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xray <xray@42angouleme.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:28:46 by xray              #+#    #+#             */
/*   Updated: 2024/11/29 14:54:50 by cmorel           ###   ########.fr       */
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

t_list	*bigger(t_list **l);

int		first_l(t_psort *ps, t_list *s);

int		second_l(t_list *s, int	limit, int limit_len);

#endif
