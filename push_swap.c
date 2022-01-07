/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuber <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 08:56:21 by ahuber            #+#    #+#             */
/*   Updated: 2022/01/07 12:29:28 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest(t_info *info)
{
	int	smallest;
	int	i;
	int	smallest_pos;

	smallest = INT_MAX;
	i = 0;
	smallest_pos = 0;
	while (i < info->array_a_nbr)
	{
		if (info->first_step[i] < smallest)
		{
			smallest = info->first_step[i];
			smallest_pos = i;
		}
		i++;
	}
	info->first_step[smallest_pos] = INT_MAX;
	return (smallest_pos);
}

void	from_step_to_array_a(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->array_a_nbr)
	{
		info->array_a[i] = info->second_step[i];
		i++;
	}
}

void	main_toolong(t_info *info, int argc, char **argv)
{
	if (argc > 2)
	{
		info->array_a_nbr = (argc - 1);
		info->first_step = malloc(sizeof(int) * argc);
		info->second_step = malloc(sizeof(int) * argc);
		info->array_a = malloc(sizeof(int) * argc);
		info->array_b = malloc(sizeof(int) * argc);
		info->str_i = 0;
		info->nbr_of_int = (argc - 1);
		info->nbr_of_int2 = (argc - 1);
		while (info->nbr_of_int-- > 0)
		{
			info->first_step[info->i] = ft_atoi(argv[info->i + 1], info);
			info->i = info->i + 1;
		}
		same_arg(info);
		while (info->nbr_of_int2 > 0)
		{
			info->smallest_pos = find_smallest(info);
			info->nbr_of_int2--;
			info->second_step[info->smallest_pos] = info->j;
			info->j = info->j + 1;
		}
		from_step_to_array_a(info);
	}
}

void	main_toolong2(t_info *info, int argc)
{
	info->i = 0;
	info->j = 1;
	info->array_b_nbr = 0;
	info->argc = argc - 1;
	//if (argc >= 100)
	//	info->chunk_size = info->argc / 12 + 22;
	//else
	if (argc <= 100)
		info->chunk_size = 20;
	info->chunk_done = 1;
	info->done = 0;
	info->nbr_done = 0;
	info->posi_in_chunk = 0;
	info->error = 1;
	if (argc == 1)
		free_me(info);
}

void	main_unique(int argc, char **argv, t_info *info)
{
	main_toolong2(info, argc);
	main_toolong(info, argc, argv);
	if (hate_the_letters(argc, argv) == 0)
		error(info);
	if (argc == 2)
		ft_split_shit(info, argv[1]);
	if (already_sorted(*info) == 1)
		free_me(info);
	if (info->array_a_nbr == 2)
		algo_two(info);
	else if (info->array_a_nbr == 3)
		algo_three(info);
	else if (info->array_a_nbr == 4)
		algo_four(info);
	else if (info->array_a_nbr == 5)
		algo_five(info);
	else
		algo_five_hundred(info);
	replace_double_ra_rb(info);
}

void	str_command_replace(t_info *info)
{
	int	i;

	i = 0;
	while (info->str_command_stock[i])
	{
		info->str_command_stock[i] = '+';
		i++;
	}
	i = 0;
	while (info->str_command[i])
	{	
		info->str_command_stock[i] = info->str_command[i];
		i++;
	}
	info->str_command_stock[i] = '\0';
}

int	main(int argc, char **argv)
{
	t_info	*info;
	int	chunk_size;
	int	i;
	int	n_command;
	int	n_command_stock;

	info = malloc(sizeof(t_info));
	info->str_command = malloc(sizeof(char) * (10000000 * 4));
	info->str_command_stock = malloc(sizeof(char) * (10000000 * 4));
	chunk_size = 17;
	n_command_stock = 10000;
	while (chunk_size < 28)
	{
		i = 0;
		n_command = 0;
		info->chunk_size = info->argc / 12 + chunk_size;
		main_unique(argc, argv, info);
		while (info->str_command[i])
		{
			if (info->str_command[i] == '\n')
				n_command++;
			i++;
		}
		if (n_command < n_command_stock)
		{
			n_command_stock = n_command;
			str_command_replace(info);
		}
		i = 0;
		while (info->str_command[i])
		{
			info->str_command[i] = '+';
			i++;
		}
		chunk_size++;		
	}
	i = 0;
	while (info->str_command_stock[i])
	{
		if (info->str_command_stock[i] != '+')
			printf("%c", info->str_command_stock[i]);
		i++;
	}
	free_me(info);
}
