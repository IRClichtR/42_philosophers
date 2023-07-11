#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	mails = 0;

void	routine()
{
	int i = 0;
	pthread_mutex_t	mutex;

	while (i++ < 100000)
	{
		pthread_mutex_init(mutex, NULL);
		mails++;
	}
		
	//read value in mails
	//increment
	//wrtie back
	// 
}

int	main()
{
	pthread_t	t1;
	pthread_t	t2;
	void	*ptr = &routine;

//	pthread function: () 
	if (pthread_create(&t1, NULL, ptr, NULL) != 0)
		return (-1);
	if (pthread_create(&t2, NULL, ptr, NULL) != 0)
		return (-1);
//	pthread_join waits for threads to end

	if (pthread_join(t1, NULL) != 0)
		return (-2);
	if (pthread_join(t2, NULL) != 0)
		return (-2);
	printf("Number of mails = %d\n", mails);
	return (0);
}

// discovery of threads : how to create threads and how to wait for a thread to finish executing

/*
void	routine()
{
	printf("test for threads\n");
	sleep(2);
	printf("end of test\n");
}

int	main()
{
	pthread_t	t1;
	pthread_t	t2;
	void	*ptr = &routine;

//	pthread function: () 
	if (pthread_create(&t1, NULL, ptr, NULL) != 0)
		return (-1);
	if (pthread_create(&t2, NULL, ptr, NULL) != 0)
		return (-1);
//	pthread_join waits for threads to end

	if (pthread_join(t1, NULL) != 0)
		return (-2);
	if (pthread_join(t2, NULL) != 0)
		return (-2);
	return (0);
}
*/
