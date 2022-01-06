/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuber <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:04:14 by ahuber            #+#    #+#             */
/*   Updated: 2022/01/06 17:53:48 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	try_push_next(t_info *info, int swap)
{
	if (info->array_b[0] == info->array_b[info->array_b_nbr - 2] && !swap)
	{
		ps_pa(info);
		return (1);
	}
	return (0);
}

int	smart_rotate_b(t_info *info)
{
	int	cnt;
	int	swap;
	int	i = 0;
	int	sz;

	cnt = 0;
	swap = 0;
	sz = info->array_b_nbr;
	info->b = info->array_b[i];
	while (info->array_b[i] != sz && ++cnt)
		i++;
	while (info->array_b[0] != sz)
	{
		if (!try_push_next(info, swap))
		{
			if (cnt > sz / 2)
				ps_rrb(info);
			else
				ps_rb(info);
		}
		else
			swap = 1;
	}
	return (swap);
}

static void	push_in_chunks(t_info *info)
{
	int	cnt;

	cnt = 0;
	while (info->array_a_nbr > 0)
	{
		if (info->array_a[0] <= (info->chunk_size * info->chunk_done))
		{
			ps_pb(info);
			if (info->array_b[0]
				< info->chunk_size * info->chunk_done - (info->chunk_size / 2))
				ps_rb(info);
			cnt++;
		}
		else
		{
			ps_ra(info);
		}
		if (cnt >= info->chunk_size * info->chunk_done)
			info->chunk_done = info->chunk_done + 1;
	}
}

static void	push_back_in_order(t_info *info)
{
	while (info->array_b_nbr > 0)
	{
		if (smart_rotate_b(info))
		{
			ps_pa(info);
			if (info->array_b_nbr > 1
				&& info->array_b[0] < info->array_b[1])
				ps_ss(info);
			else
				ps_sa(info);
		}
		else
			ps_pa(info);
	}
}

/*int	find_biggest(t_info *info)
{
	int	biggest;
	int	i;
	int	biggest_pos;

	i = 0;
	biggest = info->array_b[i];
	biggest_pos = 0;
	while (i < info->array_b_nbr)
	{
		if (info->array_b[i] > biggest)
		{
			biggest = info->array_b[i];
			biggest_pos = i;
		}
		i++;
	}
	return (biggest_pos);
}

void	five_hundred_chunk_resend(t_info *info)
{
	int	biggest;
	int	stock;

	info->nbr_done = info->chunk_size;
	while (info->nbr_done > 0)
	{
		biggest = find_biggest(info);
		stock = info->array_b[biggest];
		if (biggest < info->chunk_size * 2)
		{
			while (biggest-- > 0)
				ps_rb(info);
		}
		else
		{
			while (info->array_b[0] != stock)
				ps_rrb(info);
		}
		ps_pa(info);
		info->nbr_done = info->nbr_done - 1;
	}
}*/

void	algo_five_hundred(t_info *info)
{
	if (info->argc < 500)
		info->chunk_size = info->argc / 12 + 22;
	else
		info->chunk_size = 57;
	push_in_chunks(info);
	while (info->array_b_nbr > 0)
		push_back_in_order(info);
}
