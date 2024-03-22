#include "so_long.h"

void	print_arr(char **s, t_sl *sl)
{
	int i;

	i = 0;
	while(i < sl->map.height)
	{
		printf("%s", s[i]);
		i++;
	}
}

void	print_array(int *a, int size)
{
	int	i;
	
	i = 0;
	while (i < size)
	{
		printf("[%d] = %d \n", i, a[i]);
		i++;
	}
}