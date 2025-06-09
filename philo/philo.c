/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:52:37 by maeskhai          #+#    #+#             */
/*   Updated: 2025/06/09 13:46:42 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_pthread_create(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philos)
	{
		pthread_create(&table->philos[i].thread, 
			NULL, philo_routine, &table->philos[i]);
		i++;
	}
	ft_check_die(table);
}

void	ft_pthread_join(t_table *table)
{
	int	i;

	pthread_join(table->check_die, NULL);
	i = 0;
	while (i < table->nb_philos)
	{
		pthread_join(table->philos[i].thread, NULL);
		i++;
	}
}

void	ft_initialize(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philos)
	{
		table->philos[i].index = i + 1;
		table->philos[i].meal_count = 0;
		table->philos[i].last_meal = get_time_ms();
		table->philos[i].left_fork = &table->forks[i];
		table->philos[i].right_fork = &table->forks[(i + 1) % table->nb_philos];
		table->philos[i].table = table;
		pthread_mutex_init(&table->philos[i].last_meal_mutex, NULL);
		pthread_mutex_init(&table->philos[i].meal_mutex, NULL);
		i++;
	}
}

void	ft_creat_philos(t_table *table)
{
	pthread_mutex_init(&table->death_mutex, NULL);
	pthread_mutex_init(&table->print_mutex, NULL);
	pthread_mutex_init(&table->eat_mutex, NULL);
	table->philos = malloc(sizeof(t_philo) * table->nb_philos);
	if (!table->philos)
	{
		ft_print_error("Error\n");
		return ;
	}
	ft_initialize(table);
	table->is_dead = 0;
	if (table->nb_of_meals == 0)
		return ;
	ft_pthread_create(table);
	ft_pthread_join(table);
}

int	main(int ac, char **av)
{
	t_table	table;

	if (ac == 5 || ac == 6)
	{
		if (ft_check_nbrs(ac, av, &table) == -1)
		{
			ft_print_error("Error\n");
			return (1);
		}
		ft_forks_to_philos(&table);
		table.start_time = get_time_ms();
		ft_creat_philos(&table);
		// ft_check_die(&table);
		ft_cleanup(&table);
	}
	else
	{
		ft_print_error("Error\n");
		return (1);
	}
}
