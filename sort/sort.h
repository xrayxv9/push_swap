/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xray <xray@42angouleme.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:28:46 by xray              #+#    #+#             */
/*   Updated: 2024/11/28 14:39:55 by xray             ###   ########.fr       */
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
}		t_psort;



#endif
