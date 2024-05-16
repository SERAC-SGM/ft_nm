/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:24:27 by lletourn          #+#    #+#             */
/*   Updated: 2024/05/13 15:24:31 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

ssize_t	ft_index(const char *s, int c)
{
	ssize_t			i;
	unsigned char	uc;

	if (!s)
		return (-1);
	uc = (unsigned char)c;
	i = 0;
	while (s[i] && s[i] != uc)
		i++;
	if (s[i] == uc)
		return (i);
	return (-1);
}
