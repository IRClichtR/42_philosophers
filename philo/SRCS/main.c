#include "philo.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
		return (0);
	data = malloc(sizeof(t_data));
	if (init_data(data, ac, av) == -1)
	{
		str_error("ERROR: DATA ALLOC FAILED\n", data);
		return (1);
	}
	if (resume(data) == -1)
	{
		str_error("ERROR: THREAD EXECUTION FAILED\n", data);
		return (1);
	}
	del_memalloc(data);
	free(data);
	return (0);
}
