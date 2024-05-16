/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:23:29 by lletourn          #+#    #+#             */
/*   Updated: 2024/05/13 15:23:30 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return (0);
	if (fd < 0)
		return (-1);
	if (write(fd, s, ft_strlen(s)) == -1)
		return (-1);
	return (0);
}
