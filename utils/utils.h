/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:11:19 by cmorel            #+#    #+#             */
/*   Updated: 2024/12/01 16:38:19 by xray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef UTILS_H
#define UTILS_H

# include "../parsing/parsing.h"

void	push(t_list **stack, t_list **stack_to, int code);

void	rotate(t_list **stack, int code);

void	rrotate(t_list **stack, int code);

void	swap(t_list **stack, int code);

#endif
