// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.c                                             :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: xray <xray@42angouleme.fr>                 +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2024/10/26 22:12:25 by xray              #+#    #+#             //
//   Updated: 2024/10/26 22:25:06 by xray             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include "../printf/ft_printf.h"

void	print_stack(int *stack1, int *stack2, int len)
{
	if (!stack1 || !stack2 || !len)
		return ;
	while (0 < len)
	{
		ft_printf("%d   |   %d\n", stack1[len-1], stack2[len-1]);
		len--;
	}
	ft_printf("_____________________\n");
	ft_printf("stack1   |   stack2\n");
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_printf("Could you please give me something to sort ?");
		return (-1);
	}
	(void)argv;
	int stack1[5] = {1, 2, 3, 4, 5};
	int stack2[5] = {0, 0, 0, 0, 0};
	print_stack(stack1, stack2, 5);

}
