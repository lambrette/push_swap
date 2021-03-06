/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:11:46 by abourdar          #+#    #+#             */
/*   Updated: 2022/02/08 11:11:47 by abourdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push.h"

void	start_sort(t_swap *data)
{
	if (data->lst_size == 2)
		sort_min(data);
	else if (data->lst_size == 3)
		sort_three(data);
	else if (data->lst_size < 10)
		sort_10(data);
	else if (data->lst_size <= 100)
		sort_100(data);
	else if (data->lst_size > 100)
		sort_more(data);
}

int	is_sorted(t_list_int *list, int *tab, int size)
{
	int			i;
	int			j;
	t_list_int	*lst;

	lst = list;
	i = 0;
	while (i < size)
	{
		tab[i] = (int)lst->content;
		lst = lst->next;
		i++;
	}
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size && tab[i] < tab[j])
			j++;
		if (j != size)
			return (0);
		i++;
	}
	return (1);
}
