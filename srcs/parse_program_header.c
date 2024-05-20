/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_program_header.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:32:42 by lletourn          #+#    #+#             */
/*   Updated: 2024/05/20 17:04:49 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/nm.h"

int	parse_program_header(t_elfheader *elf, void *file)
{
	char		*programheader;

	if (elf->ei_class == ELFCLASS32)
		programheader = file + elf->u_ehdr.elf32.e_phoff;
	else
		programheader = file + elf->u_ehdr.elf64.e_phoff;

	if (check_p_type(programheader) == FAILURE
		|| (elf->ei_class == ELFCLASS64 && check_p_flags(programheader) == FAILURE))
		return (FAILURE);
	return (SUCCESS);
}
