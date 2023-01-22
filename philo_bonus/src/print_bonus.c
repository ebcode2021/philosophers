/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:11:01 by eunson            #+#    #+#             */
/*   Updated: 2023/01/22 19:43:02 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print_action(t_proc *proc, long long start_time, char *msg)
{
	sem_wait(proc->print);
	if (ft_strncmp(msg, DIE_MSG, 5) && check_die(proc) == 1)
	{
		sem_post(proc->print);
		return ;
	}
	printf("%lld ", get_elapsed_time(start_time));
	printf("%d %s\n", proc->philo->idx, msg);
	sem_post(proc->print);
}

void	print_error_with_exit(char *msg)
{
	printf("Error :: %s\n", msg);
	exit (EXIT_FAILURE);
}

void	print_manual(void)
{
	printf("-------------------------------------------------------------\n\n");
	printf("║▌│█║▌│ █║▌│█│║▌█║▌│ █│█║▌│ ██│║▌║\n");
	printf("\t This is Manual for you...∧,,,∧\n");
	printf("\t\t\t       (  ̳• · • ̳) \n");
	printf("\t\t\t         /    /r 🎁\n\n");
	printf("| First             : number_of_philosophers\n");
	printf("| Second            : time_to_die\n");
	printf("| Third             : time_to_eat\n");
	printf("| Fourth            : time_to_sleep\n");
	printf("| Fifth(optional)   : number_of_times_each_philosopher_must_eat\n\n");
	printf("-------------------------------------------------------------\n\n");
}