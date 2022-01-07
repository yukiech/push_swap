/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuber <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:24:27 by ahuber            #+#    #+#             */
/*   Updated: 2022/01/06 23:37:36 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	replace_double_ra_rb(t_info *info)
{
	int	i;

	i = -1;
	while (info->str_command[++i])
	{
		if (info->str_command[i] == 'r' && info->str_command[i + 1] == 'a')
		{
			if (info->str_command[i + 3] == 'r' && info->str_command[i + 4] == 'b')
			{
				info->str_command[i + 1] = 'r';
				info->str_command[i + 3] = '+';
				info->str_command[i + 4] = '+';
				info->str_command[i + 5] = '+';
				
			}
		}
		if (info->str_command[i] == 'r' && info->str_command[i + 1] == 'b')
		{
			if (info->str_command[i + 3] == 'r' && info->str_command[i + 4] == 'a')
			{
				info->str_command[i + 1] = 'r';
				info->str_command[i + 3] = '+';
				info->str_command[i + 4] = '+';
				info->str_command[i + 5] = '+';
				
			}
		}
	}
	i = -1;
	//while (info->str_command[++i])
	//{
	//	if (info->str_command[i] != '+')
	//		printf("%c", info->str_command[i]);
	//}
}
