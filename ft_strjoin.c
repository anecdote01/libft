/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 11:08:00 by mkorucu           #+#    #+#             */
/*   Updated: 2022/07/03 11:28:06 by mkorucu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joinedstr;
	char	*cursor;
	size_t	s1len;
	size_t	s2len;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	joinedstr = (char *)malloc(sizeof(char) * (s1len + s2len + 1));
	cursor = joinedstr;
	if (!joinedstr)
		return (NULL);
	while (*s1)
		*joinedstr++ = *s1++;
	while (*s2)
		*joinedstr++ = *s2++;
	*joinedstr = '\0';
	return (cursor);
}
