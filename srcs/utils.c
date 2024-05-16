/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:33:09 by lletourn          #+#    #+#             */
/*   Updated: 2024/05/16 17:13:41 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/nm.h"
#include <inttypes.h>

void	print_elf32(t_elfheader *elf)
{
	printf(
			"file signature: %x %x %x %x\nclass: %d\ndata: %d\nversion: %d\nOS/ABI: %d\nABI Version: %d\npadding: %d %d %d %d %d %d %d\n",
			elf->u_ehdr.elf32->e_ident[0], elf->u_ehdr.elf32->e_ident[1], elf->u_ehdr.elf32->e_ident[2], elf->u_ehdr.elf32->e_ident[3],
			elf->u_ehdr.elf32->e_ident[4], elf->u_ehdr.elf32->e_ident[5], elf->u_ehdr.elf32->e_ident[6], elf->u_ehdr.elf32->e_ident[7],
			elf->u_ehdr.elf32->e_ident[8], elf->u_ehdr.elf32->e_ident[9], elf->u_ehdr.elf32->e_ident[10], elf->u_ehdr.elf32->e_ident[11],
			elf->u_ehdr.elf32->e_ident[12], elf->u_ehdr.elf32->e_ident[13], elf->u_ehdr.elf32->e_ident[14], elf->u_ehdr.elf32->e_ident[15]);
	ft_printf("e_type : %d\n", elf->u_ehdr.elf32->e_type);
	ft_printf("e_machine : %d\n", elf->u_ehdr.elf32->e_machine);
	ft_printf("e_version : %d\n", elf->u_ehdr.elf32->e_version);
	ft_printf("e_entry : %x\n", elf->u_ehdr.elf32->e_entry);
	ft_printf("e_phoff : %d\n", elf->u_ehdr.elf32->e_phoff);
	ft_printf("e_shoff : %x\n", elf->u_ehdr.elf32->e_shoff);
	ft_printf("e_flags : %d\n", elf->u_ehdr.elf32->e_flags);
	ft_printf("e_ehsize : %d\n", elf->u_ehdr.elf32->e_ehsize);
	ft_printf("e_phentsize : %d\n", elf->u_ehdr.elf32->e_phentsize);
	ft_printf("e_phnum : %d\n", elf->u_ehdr.elf32->e_phnum);
	ft_printf("e_shentsize : %d\n", elf->u_ehdr.elf32->e_shentsize);
	ft_printf("e_shnum : %d\n", elf->u_ehdr.elf32->e_shnum);
	ft_printf("e_shstrndx : %d\n", elf->u_ehdr.elf32->e_shstrndx);
}

void	print_elf64(t_elfheader *elf)
{
	printf(
			"file signature: %x %x %x %x\nclass: %d\ndata: %d\nversion: %d\nOS/ABI: %d\nABI Version: %d\npadding: %d %d %d %d %d %d %d\n",
			elf->u_ehdr.elf32->e_ident[0], elf->u_ehdr.elf32->e_ident[1], elf->u_ehdr.elf32->e_ident[2], elf->u_ehdr.elf32->e_ident[3],
			elf->u_ehdr.elf32->e_ident[4], elf->u_ehdr.elf32->e_ident[5], elf->u_ehdr.elf32->e_ident[6], elf->u_ehdr.elf32->e_ident[7],
			elf->u_ehdr.elf32->e_ident[8], elf->u_ehdr.elf32->e_ident[9], elf->u_ehdr.elf32->e_ident[10], elf->u_ehdr.elf32->e_ident[11],
			elf->u_ehdr.elf32->e_ident[12], elf->u_ehdr.elf32->e_ident[13], elf->u_ehdr.elf32->e_ident[14], elf->u_ehdr.elf32->e_ident[15]);
	ft_printf("e_type : %d\n", elf->u_ehdr.elf64->e_type);
	ft_printf("e_machine : %d\n", elf->u_ehdr.elf64->e_machine);
	ft_printf("e_version : %d\n", elf->u_ehdr.elf64->e_version);
	ft_printf("e_entry : %x\n", elf->u_ehdr.elf64->e_entry);
	ft_printf("e_phoff : %d\n", elf->u_ehdr.elf64->e_phoff);
	ft_printf("e_shoff : %x\n", elf->u_ehdr.elf64->e_shoff);
	ft_printf("e_flags : %d\n", elf->u_ehdr.elf64->e_flags);
	ft_printf("e_ehsize : %d\n", elf->u_ehdr.elf64->e_ehsize);
	ft_printf("e_phentsize : %d\n", elf->u_ehdr.elf64->e_phentsize);
	ft_printf("e_phnum : %d\n", elf->u_ehdr.elf64->e_phnum);
	ft_printf("e_shentsize : %d\n", elf->u_ehdr.elf64->e_shentsize);
	ft_printf("e_shnum : %d\n", elf->u_ehdr.elf64->e_shnum);
	ft_printf("e_shstrndx : %d\n", elf->u_ehdr.elf64->e_shstrndx);
}

void	ft_exit(char num, t_elfheader *elf)
{
	if (elf->ei_class == ELFCLASS32)
	{
		free(elf->u_ehdr.elf32);
		// free(elf->u_phdr.phdr32);
		// free(elf->u_shdr.shdr32);
	}

	else
	{
		free(elf->u_ehdr.elf64);
		// free(elf->u_phdr.phdr64);
		// free(elf->u_shdr.shdr64);
	}
	exit(num);
}
