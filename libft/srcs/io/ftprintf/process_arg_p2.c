/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_arg_p2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:23:01 by lletourn          #+#    #+#             */
/*   Updated: 2024/05/13 15:23:03 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/libft.h"

void	p_hex(t_output *output, va_list ap)
{
	unsigned int	x;

	x = (unsigned int)va_arg(ap, unsigned int);
	output->to_print = ft_utoa_base(x, "0123456789abcdef");
	output->size = ft_strlen(output->to_print);
}

void	p_uphex(t_output *output, va_list ap)
{
	unsigned int	x;

	x = (unsigned int)va_arg(ap, unsigned int);
	output->to_print = ft_utoa_base(x, "0123456789ABCDEF");
	output->size = ft_strlen(output->to_print);
}

void	p_pct(t_output *output, va_list ap)
{
	(void)ap;
	output->to_print = ft_strdup("%");
	output->size = 1;
}
