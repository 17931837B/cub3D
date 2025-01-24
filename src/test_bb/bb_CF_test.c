#include "cub3d.h"

void	free_box(char **box)
{
	int	i;

	i = 0;
	while (box[i])
	{
		free(box[i]);
		i++;
	}
	free(box);
}

bool	is_num(char **list)
{
	int	i;
	int	j;

	i = 0;
	while (list[i])
	{
		j = 0;
		while (list[i][j])
		{
			if (list[i][j] != '\n' && (!ft_isdigit(list[i][j]) || j > 3))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	is_wrong_val(char **list)
{
	if (!(list[2] && !list[3]) || !is_num(list))
	{
		printf("Error\nColor value wrong.\n");
		free_box(list);
		return (true);
	}
	if ((0 <= ft_atoi(list[0])) && (ft_atoi(list[0]) <= 255)
		&& (0 <= ft_atoi(list[1])) && (ft_atoi(list[1]) <= 255)
		&& (0 <= ft_atoi(list[2])) && (ft_atoi(list[2]) <= 255))
	{
		free_box(list);
		return (false);
	}
	printf("Error\nColor value over.\n");
	free_box(list);
	return (true);
}

bool	is_wrong_color(char *line)
{
	char	**box;
	char	**box2;

	if ((line[0] == 'F' || line[0] == 'C') && line[1] == ' ')
	{
		box = ft_split(line, ' ');
		if (!(box[1] && !box[2]))
		{
			free_box (box);
			return (true);
		}
		free (box[0]);
		box2 = ft_split(box[1], ',');
		free (box[1]);
		free (box);
		if (is_wrong_val(box2))
			return (true);
	}
	return (false);
}

bool	check_color(char *line, t_check_bb *check_list, int fd)
{
	if (is_wrong_color(line))
	{
		free(line);
		free(check_list);
		close(fd);
		return (false);
	}
	return (true);
}
