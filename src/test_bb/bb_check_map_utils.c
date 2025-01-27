#include "cub3d.h"

bool	is_s1(char c)
{
	if (c == ' ' || c == '1')
		return (true);
	return (false);
}

bool	is_around_s1(char **map, int i, int j)
{
	if (is_s1(map[i - 1][j - 1]) && is_s1(map[i][j - 1])
		&& is_s1(map[i + 1][j - 1]) && is_s1(map[i - 1][j])
		&& is_s1(map[i + 1][j]) && is_s1(map[i - 1][j + 1])
		&& is_s1(map[i][j + 1]) && is_s1(map[i + 1][j + 1]))
		return (true);
	return (false);
}
