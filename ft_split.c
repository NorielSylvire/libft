/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhongu <fhongu@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 20:11:46 by fhongu            #+#    #+#             */
/*   Updated: 2023/04/08 21:17:15 by fhongu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_words(const char **str, char delimiter);

size_t	word_len(const char **str, char delimiter);

int		my_free(char **ret, size_t i);

char	**ft_split(char const *s, char c)
{
	char		**ret;
	size_t		i;
	size_t		wlen;
	size_t		nwords;

	nwords = count_words((const char **)(size_t) & s, c);
	ret = ft_calloc(nwords, sizeof (char *));
	i = 0;
	wlen = 0;
	while (i++ < nwords - 1 && ret != NULL)
	{
		wlen = word_len(&s, c);
		*ret = ft_calloc(wlen, sizeof (char));
		if (my_free(ret, i))
			return (NULL);
		ft_strlcpy(*ret, s, wlen);
		ret++;
		s += wlen - 1;
	}
	if (ret != NULL)
		ret -= nwords - 1;
	return (ret);
}

size_t	count_words(const char **str, char dlm)
{
	size_t		nwords;
	const char	*scopy;

	nwords = 0;
	scopy = *str;
	while (*scopy && *scopy == dlm)
		scopy = scopy + 1;
	if (*scopy != '\0')
	{
		*str = scopy;
		nwords++;
	}
	else
		return (1);
	while (*scopy)
	{
		if (*scopy == dlm && *(scopy + 1) && *(scopy + 1) != dlm)
			nwords++;
		scopy = scopy + 1;
	}
	return (nwords + 1);
}

size_t	word_len(const char **str, char delimiter)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (**str == delimiter)
		*str += 1;
	while (**str && **str != delimiter)
	{
		len++;
		*str += 1;
	}
	*str -= len;
	return (len + 1);
}

int	my_free(char **ret, size_t i)
{
	size_t	icopy;

	if (*ret != NULL)
		return (0);
	icopy = i;
	while (i > 1)
		free(*(ret - (i-- - 1)));
	free(ret - (icopy - 1));
	return (1);
}
