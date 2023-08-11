#include "philo.h"

void	str_error(char *msg, t_data *data)
{
	printf("%s\n", msg);
	del_memalloc(data);
}
