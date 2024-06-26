/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:06:37 by fhongu            #+#    #+#             */
/*   Updated: 2024/04/15 20:24:13 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ret;
	char	*retcopy;

	ret = malloc(ft_strlen(s1) + 1);
	if (!ret)
		return (NULL);
	retcopy = ret;
	while (*s1)
		*retcopy++ = *s1++;
	*retcopy = '\0';
	return (ret);
}
