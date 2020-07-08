/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ngn_strerror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 02:35:36 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/07/08 08:16:51 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ngn_int.h"

const char	*ngn_strerror(int code)
{
	if (code == NGN_MEMERR)
		return ("Error\nCannot allocate memory.\n");
	if (code == NGN_OPENERR)
		return ("Error\nCannot open the config file.\n");
	if (code == NGN_FILERR)
		return ("Error\nInvalid config file.\n");
	if (code == NGN_FDERR)
		return ("Error\nInvalid file descriptor.\n");
	if (code == NGN_RESERR)
		return ("Error\nInvalid resolution in the config file.\n");
	if (code == NGN_TEXERR)
		return ("Error\nInvalid texture in the config file.\n");
	if (code == NGN_TEXFILERR)
		return ("Error\nInvalid texture format. You need bmp files.\n");
	if (code == NGN_TEXNFERR)
		return ("Error\nCannot open a texture file.\n");
	if (code == NGN_COLERR)
		return ("Error\nInvalid color in the config file.\n");
	return (NULL);
}
