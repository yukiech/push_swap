/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_handle3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuber <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:15:16 by ahuber            #+#    #+#             */
/*   Updated: 2022/01/06 15:31:31 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_rra(t_info *info)
{
	int	stock;
	int	i;

	i = info->array_a_nbr - 1;
	stock = info->array_a[i];
	while (i > 0)
	{
		info->array_a[i] = info->array_a[i - 1];
		i--;
	}
	info->array_a[0] = stock;
	info->str_command[info->str_i] = 'r';
	info->str_command[info->str_i + 1] = 'r';
	info->str_command[info->str_i + 2] = 'a';
	info->str_command[info->str_i + 3] = '\n';
	info->str_i = info->str_i + 4;
	//write(1, "rra\n", 4);
}

void	ps_rrb(t_info *info)
{
	int	stock;
	int	i;

	i = info->array_b_nbr - 1;
	stock = info->array_b[i];
	while (i > 0)
	{
		info->array_b[i] = info->array_b[i - 1];
		i--;
	}
	info->array_b[0] = stock;
	info->str_command[info->str_i] = 'r';
	info->str_command[info->str_i + 1] = 'r';
	info->str_command[info->str_i + 2] = 'b';
	info->str_command[info->str_i + 3] = '\n';
	info->str_i = info->str_i + 4;
	//write(1, "rrb\n", 4);
}

void	ps_rrr(t_info *info)
{
	ps_rra(info);
	ps_rrb(info);
	info->str_command[info->str_i - 6] = 'r';
	info->str_command[info->str_i - 5] = 'r';
	info->str_command[info->str_i - 4] = 'r';
	info->str_command[info->str_i - 3] = '\n';
	info->str_i = info->str_i - 2;
	//write(1, "rrr\n", 4);
}
