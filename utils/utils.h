/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:11:19 by cmorel            #+#    #+#             */
/*   Updated: 2024/11/28 11:03:31 by xray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef UTILS_H
#define UTILS_H

# include "../parsing/parsing.h"

void	push(t_list **stack, t_list **stack_to);

void	rotate(t_list **stack);

void	rrotate(t_list **stack);

void	swap(t_list **stack);

#endif
