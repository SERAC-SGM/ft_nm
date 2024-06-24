/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_program_header.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:32:42 by lletourn          #+#    #+#             */
/*   Updated: 2024/06/24 18:03:38 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/nm.h"
#include <elf.h>

static int	check_p_type(void *programheader, char class)
{
	t_elf_word	p_type;

	if (class == ELFCLASS32)
		goto x32;
	goto x64;
x32:
	p_type = ((Elf32_Phdr *)programheader)->p_type;
	goto check;
x64:
	p_type = ((Elf64_Phdr *)programheader)->p_type;
	goto check;
check:
	if (p_type == PT_NULL
		|| p_type == PT_LOAD
		|| p_type == PT_DYNAMIC
		|| p_type == PT_INTERP
		|| p_type == PT_NOTE
		|| p_type == PT_SHLIB
		|| p_type == PT_PHDR
		|| p_type == PT_TLS
		|| p_type == PT_GNU_EH_FRAME
		|| p_type == PT_GNU_STACK
		|| p_type == PT_GNU_RELRO
		|| p_type == PT_SUNWBSS
		|| p_type == PT_SUNWSTACK
		|| p_type == PT_HIOS
		|| p_type == PT_LOPROC
		|| p_type == PT_HIPROC)
		return (SUCCESS);

	ft_printf("Unknown p_type: %d\n", p_type);
	return (FAILURE);
}

static int check_p_flags(void *programheader)
{
	t_elf_word	p_flags;

	p_flags = ((Elf64_Phdr *)programheader)->p_flags;
	if (p_flags == PF_X
		|| p_flags == PF_W
		|| p_flags == PF_R)
		return (SUCCESS);
	ft_printf("Unknown p_flags\n");
	return (FAILURE);
}

static int check_p_offset()
{
	return (SUCCESS);
}

int	parse_program_header(t_elfheader *elf, void *file)
{
	char		*programheader;

	if (elf->ei_class == ELFCLASS32)
		programheader = file + elf->u_ehdr.elf32.e_phoff;
	else
		programheader = file + elf->u_ehdr.elf64.e_phoff;

	if (check_p_type(programheader, elf->ei_class) == FAILURE
		|| (elf->ei_class == ELFCLASS64 && check_p_flags(programheader) == FAILURE)
		|| check_p_offset() == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
