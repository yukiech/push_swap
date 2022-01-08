#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		++i;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	execute_commands(t_info *info, char *commands)
{
		if (ft_strcmp(commands, SA) == 0)
			ps_sa(info);
		else if (ft_strcmp(commands, SB) == 0)
			ps_sb(info);
		else if (ft_strcmp(commands, SS) == 0)
			ps_ss(info);
		else if (ft_strcmp(commands, PA) == 0)
			ps_pa(info);
		else if (ft_strcmp(commands, PB) == 0)
			ps_pb(info);
		else if (ft_strcmp(commands, RA) == 0)
			ps_ra(info);
		else if (ft_strcmp(commands, RB) == 0)
			ps_rb(info);
		else if (ft_strcmp(commands, RR) == 0)
			ps_rr(info);
		else if (ft_strcmp(commands, RRA) == 0)
			ps_rra(info);
		else if (ft_strcmp(commands, RRB) == 0)
			ps_rrb(info);
		else if (ft_strcmp(commands, RRR) == 0)
			ps_rrr(info);
}

int	main(int argc, char **argv)
{
	t_info	*info;
	char *commands;

	info = malloc(sizeof(t_info));
	commands = malloc(sizeof(char) * 10);
	main_unique(argc, argv, info, 1);
	commands = get_next_line(1);
	while (commands != NULL)
	{
		execute_commands(info, commands);
		free(commands);
		commands = get_next_line(1);
	}
	if (already_sorted(*info) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
