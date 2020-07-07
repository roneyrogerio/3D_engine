/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ngn_int_splittedline.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 04:07:21 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/07/05 05:26:34 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ngn_int.h"

char	**ngn_int_splittedline(int fd)
{
	int		ret;
	char	*line;
	char	**splitted;

	while ((ret = ngn_int_getline(fd, &line)) != -1)
	{
		if (ret > 0)
			break ;
		free(line);
	}
	if (ret <= 0)
		return (NULL);
	splitted = ft_split(line, ' ');
	free(line);
	return (splitted);
}
