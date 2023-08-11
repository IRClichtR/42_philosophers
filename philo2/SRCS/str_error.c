#include "philo.h"

int	str_error(char *err_msg, t_data *data)
{
	printf("%s\n", err_msg);
	del_malloc(data);
	return (-1);
}
