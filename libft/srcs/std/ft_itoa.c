/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:24:41 by lletourn          #+#    #+#             */
/*   Updated: 2024/05/13 15:24:43 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

size_t	ft_nblen(long long n)
{
	size_t	size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		size++;
		n *= -1;
	}
	while (n > 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{	
	long long	nb;
	char		*nstr;
	size_t		size;

	nb = (long long)n;
	size = ft_nblen(nb);
	nstr = malloc(sizeof(char) * (size + 1));
	if (!nstr)
		return (NULL);
	if (nb == 0)
		return (nstr[0] = '0', nstr[1] = '\0', nstr);
	if (nb < 0)
	{
		nb *= -1;
		nstr[0] = '-';
	}
	nstr[size--] = '\0';
	while (nb > 0)
	{
		nstr[size--] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (nstr);
}
