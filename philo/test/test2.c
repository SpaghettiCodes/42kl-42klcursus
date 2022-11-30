#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_data {
	int		id;
	int		stuff1;
	int		start;
	int		someonedied;
	char	*epic_string;
	pthread_mutex_t id_lock;
	pthread_mutex_t	data_lock;
} t_data;

int	str_len(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_dup(char *str)
{
	char *ret;
	ret = malloc (sizeof(char) * (str_len(str) + 1));
	int	i = 0;
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

int	*thread(void *arg)
{
	int	id;
	int	havefork;
	int	i;
	t_data *data;

	data = (t_data *) arg;

	pthread_mutex_lock(&data->id_lock);
	id = ++data->id;
	pthread_mutex_unlock(&data->id_lock);

	while (!data->start)
		if (data->start)
			break;
	
	i = 0;
	while (!data->someonedied)
	{	
		pthread_mutex_lock(&data->data_lock);
		printf("ID = %d\n", id);
		if (data->stuff1 == 1)
		{
			printf("I took Fork\n");
			i = 0;
			data->stuff1 = 0;
			havefork = 1;
		}
		else
		{
			if (havefork == 0)
			{
				printf("Who took fork >:(\n");
				i++;
				if (i == 10)
				{
					printf("I died XP\n");
					data->someonedied = 1;
				}
			}
			else
			{
				printf("Returned Fork\n");
				data->stuff1 = 1;
				havefork = 0;
			}
		}
		pthread_mutex_unlock(&data->data_lock);
		// if (havefork)
		// 	usleep(10000);
	}
}

void	init(t_data *data)
{
	data->id = 0;
	data->stuff1 = 1;
	data->epic_string = ft_dup("Very Epic String\n\0");
	data->start = 0;

	pthread_mutex_init(&data->id_lock, NULL);
	pthread_mutex_init(&data->data_lock, NULL);
}

int main()
{
	pthread_t threadone;
	pthread_t threadtwo;
	t_data *data;

	data = malloc(sizeof(t_data));
	printf("Initializing...\n");
	init(data);
	printf("Initializing Complete!\n");

	printf("Threading...\n");
	data->id = 0;
	pthread_create(&threadone, NULL, (void *)thread, (void *)data);
	pthread_create(&threadtwo, NULL, (void *)thread, (void *)data);
	data->start = 1;
	pthread_join(threadone, NULL);
	pthread_join(threadtwo, NULL);
	pthread_mutex_destroy(&data->id_lock);
	pthread_mutex_destroy(&data->data_lock);
}