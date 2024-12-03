/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xray <xray@42angouleme.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:28:46 by xray              #+#    #+#             */
/*   Updated: 2024/12/03 10:17:44 by xray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SORT_H
# define SORT_H

# include "../parsing/parsing.h"
# include "../utils/utils.h"

typedef struct s_dual
{
	int	limit;
	int	len;
}		t_dual;

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
	int	limit;
}		t_psort;

void	pre_sort(t_list	*s);

void	get_info(t_psort *ps, t_list *s);

void	stackb_fill(t_list **sa, t_list **sb, t_psort *ps);

int		mini(t_list	*sa);

int		first_l(t_psort *ps, t_list *s);

t_list	*bigger(t_list **l);

#endif
