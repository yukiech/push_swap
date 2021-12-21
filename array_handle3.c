/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuber <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:15:16 by ahuber            #+#    #+#             */
/*   Updated: 2021/12/15 16:18:38 by ahuber           ###   ########.fr       */
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
	write(1, "rra\n", 4);
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
	write(1, "rrb\n", 4);
}

void	ps_rrr(t_info *info)
{
	ps_rra(info);
	ps_rrb(info);
	write(1, "rrr\n", 4);
}
