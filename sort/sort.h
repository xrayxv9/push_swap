/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xray <xray@42angouleme.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:28:46 by xray              #+#    #+#             */
/*   Updated: 2024/12/09 09:53:14 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SORT_H
# define SORT_H

# include "../parsing/parsing.h"
# include "../utils/utils.h"

typedef struct s_dual
{
	int	smaller;
	int	bigger;
	int	code;
}	t_dual;

void	give_index(t_list	**sa, t_list **sb);

int		max_bytes(t_list *sa);

void	radix(t_list **sa, t_list **sb);

#endif
