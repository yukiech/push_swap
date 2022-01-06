/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuber <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:15:16 by ahuber            #+#    #+#             */
/*   Updated: 2022/01/06 15:32:21 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sa(t_info *info)
{
	int	stock;
	int	i;

	i = 0;
	if (info->array_a_nbr > 1)
	{
		stock = info->array_a[i];
		info->array_a[i] = info->array_a[i + 1];
		info->array_a[i + 1] = stock;
	}
	info->str_command[info->str_i] = 's';
	info->str_command[info->str_i + 1] = 'a';
	info->str_command[info->str_i + 2] = '\n';
	info->str_i = info->str_i + 3;
	//write(1, "sa\n", 3);
}

void	ps_sb(t_info *info)
{
	int	stock;
	int	i;

	i = 0;
	if (info->array_b_nbr > 1)
	{
		stock = info->array_b[i];
		info->array_b[i] = info->array_b[i + 1];
		info->array_b[i + 1] = stock;
	}
	info->str_command[info->str_i] = 's';
	info->str_command[info->str_i + 1] = 'b';
	info->str_command[info->str_i + 2] = '\n';
	info->str_i = info->str_i + 3;
	//write(1, "sb\n", 3);
}

void	ps_ss(t_info *info)
{
	ps_sa(info);
	ps_sb(info);
	info->str_command[info->str_i - 6] = 's';
	info->str_command[info->str_i - 5] = 's';
	info->str_command[info->str_i - 4] = '\n';
	info->str_i = info->str_i - 3;
	//write(1, "ss\n", 3);
}

void	ps_pa(t_info *info)
{
	int	stock;
	int	i;

	i = 0;
	if (info->array_b_nbr > 0)
	{
		stock = info->array_b[i];
		while (i < (info->array_b_nbr - 1))
		{
			info->array_b[i] = info->array_b[i + 1];
			i++;
		}
		i = info->array_a_nbr;
		while (i >= 0 )
		{
			info->array_a[i + 1] = info->array_a[i];
			i--;
		}
		info->array_a[0] = stock;
		info->array_b_nbr--;
		info->array_a_nbr++;
	}
	info->str_command[info->str_i] = 'p';
	info->str_command[info->str_i + 1] = 'a';
	info->str_command[info->str_i + 2] = '\n';
	info->str_i = info->str_i + 3;
	//write(1, "pa\n", 3);
}

void	ps_pb(t_info *info)
{
	int	stock;
	int	i;

	i = 0;
	if (info->array_a_nbr > 0)
	{
		stock = info->array_a[i];
		while (i < (info->array_a_nbr - 1))
		{
			info->array_a[i] = info->array_a[i + 1];
			i++;
		}
		i = info->array_b_nbr;
		while (i >= 0 )
		{
			info->array_b[i + 1] = info->array_b[i];
			i--;
		}
		info->array_b[0] = stock;
		info->array_a_nbr--;
		info->array_b_nbr++;
	}
	info->str_command[info->str_i] = 'p';
	info->str_command[info->str_i + 1] = 'b';
	info->str_command[info->str_i + 2] = '\n';
	info->str_i = info->str_i + 3;
	//write(1, "pb\n", 3);
}
