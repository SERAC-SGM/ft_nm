/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:26:25 by lletourn          #+#    #+#             */
/*   Updated: 2024/05/13 15:26:26 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	n;

	n = 0;
	if (size > 0)
	{
		while (n < size - 1 && src[n])
		{
			dst[n] = src[n];
			n++;
		}
		dst[n] = '\0';
	}
	while (src[n])
		n++;
	return (n);
}
