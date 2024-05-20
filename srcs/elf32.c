/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elf32.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:28:11 by lletourn          #+#    #+#             */
/*   Updated: 2024/05/17 15:04:15 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/nm.h"

void	set_header32(t_elfheader *elf, void *file) // need big endian conversion
{
	memcpy(elf->u_ehdr.elf32->e_ident, file, EI_NIDENT);
	elf->u_ehdr.elf32->e_type = ((Elf32_Ehdr *)file)->e_type;
	elf->u_ehdr.elf32->e_machine = ((Elf32_Ehdr *)file)->e_machine;
	elf->u_ehdr.elf32->e_version = ((Elf32_Ehdr *)file)->e_version;
	elf->u_ehdr.elf32->e_entry = ((Elf32_Ehdr *)file)->e_entry;
	elf->u_ehdr.elf32->e_phoff = ((Elf32_Ehdr *)file)->e_phoff;
	elf->u_ehdr.elf32->e_shoff = ((Elf32_Ehdr *)file)->e_shoff;
	elf->u_ehdr.elf32->e_flags = ((Elf32_Ehdr *)file)->e_flags;
	elf->u_ehdr.elf32->e_ehsize = ((Elf32_Ehdr *)file)->e_ehsize;
	elf->u_ehdr.elf32->e_phentsize = ((Elf32_Ehdr *)file)->e_phentsize;
	elf->u_ehdr.elf32->e_phnum = ((Elf32_Ehdr *)file)->e_phnum;
	elf->u_ehdr.elf32->e_shentsize = ((Elf32_Ehdr *)file)->e_shentsize;
	elf->u_ehdr.elf32->e_shnum = ((Elf32_Ehdr *)file)->e_shnum;
	elf->u_ehdr.elf32->e_shstrndx = ((Elf32_Ehdr *)file)->e_shstrndx;
}

void	set_program_header32(t_elfheader *elf, void *file)
{
	elf->u_phdr.phdr32 = (Elf32_Phdr *)(file + elf->u_ehdr.elf32->e_phoff);
}
