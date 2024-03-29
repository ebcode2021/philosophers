/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_all_proc_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:04:46 by eunson            #+#    #+#             */
/*   Updated: 2023/01/22 20:51:00 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	all_close(t_proc *proc)
{
	sem_close(proc->fork);
	sem_close(proc->print);
	sem_close(proc->routine);
}

void	wait_all_proc(t_proc *proc)
{
	waitpid(-1, &(proc->status), 0);
	if (WEXITSTATUS(proc->status) == EXIT_FAILURE)
		kill(0, SIGINT);
	all_close(proc);
}
