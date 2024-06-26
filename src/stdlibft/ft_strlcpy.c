/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 21:08:23 by fhongu            #+#    #+#             */
/*   Updated: 2024/04/15 20:24:41 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	const char	*s;
	size_t		i;

	s = src;
	i = 0;
	if (dstsize == 0)
		return (ft_strlen(s));
	while (*src && i++ < dstsize - 1)
		*dst++ = *src++;
	*dst = '\0';
	return (ft_strlen(s));
}
