/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:23:45 by lletourn          #+#    #+#             */
/*   Updated: 2024/05/13 15:23:51 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*arr;
	size_t	i;

	if (n != 0 && (n * size) / n != size)
		return (NULL);
	arr = malloc(n * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < n * size)
		((unsigned char *)arr)[i++] = 0;
	return (arr);
}
