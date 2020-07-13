/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ngn_int_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 12:38:04 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/07/12 15:07:11 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ngn_int.h"

int		**ngn_int_matrix_creat(size_t x, size_t y)
{
	int	**matrix;

	if ((matrix = (int **)ft_calloc(1, (y + 1) * sizeof(int *))) == NULL)
		return (NULL);
	matrix[y] = NULL;
	while (y--)
	{
		if ((matrix[y] = (int *)malloc(x * sizeof(int))) == NULL)
		{
			ngn_int_matrix_clear(matrix);
			return (NULL);
		}
		ft_memset(matrix[y], 0xFF, x * sizeof(int));
	}
	return (matrix);
}

void	ngn_int_matrix_clear(int **matrix)
{
	size_t	i;

	i = 0;
	while(matrix[i] != NULL)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
