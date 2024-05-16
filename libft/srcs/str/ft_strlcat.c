/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:26:24 by lletourn          #+#    #+#             */
/*   Updated: 2024/05/13 15:26:25 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

size_t	ft_strlcat(char *dst, const char *src, unsigned int size)
{
	size_t	i;
	size_t	l_dst;
	size_t	l_src;

	l_src = ft_strlen(src);
	if (!size && !dst)
		return (l_src + size);
	i = 0;
	l_dst = ft_strlen(dst);
	if (size <= l_dst)
		return (l_src + size);
	while (i + l_dst < size - 1 && src[i])
	{
		dst[l_dst + i] = src[i];
		i++;
	}
	dst[l_dst + i] = '\0';
	return (l_dst + l_src);
}
