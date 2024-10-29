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
#include <stdio.h>

void	print_stack(int *stack1, int *stack2, int len)
{
	if (!stack1 || !stack2 || !len)
		return ;
	while (0 < len)
	{
		printf("%d   |   %d\n", stack1[len-1], stack2[len-1]);
		len--;
	}
	printf("_____________________\n");
	printf("stack1   |   stack2\n");
}

int main()
{
	int stack1[5] = {1, 2, 3, 4, 5};
	int stack2[5] = {0, 0, 0, 0, 0};
	print_stack(stack1, stack2, 5);

}
