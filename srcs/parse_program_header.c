/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_program_header.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:32:42 by lletourn          #+#    #+#             */
/*   Updated: 2024/05/20 11:43:42 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <elf.h>

void	parse_program_header32(char *file, Elf32_Off p_offset)
{
	char	*programheader;

	programheader = file + p_offset;
}
