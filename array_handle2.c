/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_handle2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuber <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:15:16 by ahuber            #+#    #+#             */
/*   Updated: 2021/12/15 16:18:59 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_ra(t_info *info)
{
	int	stock;
	int	i;

	i = 0;
	stock = info->array_a[0];
	while (i < info->array_a_nbr)
	{
		info->array_a[i] = info->array_a[i + 1];
		i++;
	}
	info->array_a[i - 1] = stock;
	write(1, "ra\n", 3);
}

void	ps_rb(t_info *info)
{
	int	stock;
	int	i;

	i = 0;
	stock = info->array_b[i];
	while (i < info->array_b_nbr)
	{
		info->array_b[i] = info->array_b[i + 1];
		i++;
	}
	info->array_b[i - 1] = stock;
	write(1, "rb\n", 3);
}

void	ps_rr(t_info *info)
{
	ps_ra(info);
	ps_rb(info);
	write(1, "rr\n", 3);
}
