/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:20:47 by lletourn          #+#    #+#             */
/*   Updated: 2024/05/17 11:24:49 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/nm.h"

static void	check_signature(char *file)
{
	if (file[EI_MAG0] == ELFMAG0 && file[EI_MAG1] == ELFMAG1
		&& file[EI_MAG2] == ELFMAG2 && file[EI_MAG3] == ELFMAG3)
		return ;
	ft_printf("Invalid file signature\n");
	exit(1);
}

static char	check_ei_class(char *file)
{
	if (file[EI_CLASS] == ELFCLASS32 || file[EI_CLASS] == ELFCLASS64)
		return (file[EI_CLASS]);
	printf("Invalid class format\n");
	exit(1);
}

static void	check_ei_data(char *file)
{
	if (file[EI_DATA] == ELFDATA2LSB || file[EI_DATA] == ELFDATA2MSB)
		return ;
	ft_printf("Invalid data format\n");
	exit(1);
}

static void	check_ei_version(char *file)
{
	if (file[EI_VERSION] == EV_CURRENT)
		return ;
	ft_printf("Invalid header version\n");
	exit(1);
}

void	parse_header(t_elfheader *elf, void *file)
{
	check_signature(file);
	check_ei_class(file);
	check_ei_data(file);
	check_ei_version(file);
	check_e_version(file);
	// check_offset_size(file);
	// check_e_ehsize(file);
	// check_program_header(file);
	// check_section_header(file);
	elf->ei_class = ((char*)file)[EI_CLASS];
	elf->ei_data = ((char*)file)[EI_DATA];
	if (elf->ei_class == ELFCLASS32)
	{
		elf->u_ehdr.elf32 = malloc(sizeof(Elf32_Ehdr)); // separate alloc function
		elf->u_phdr.phdr32 = NULL;
		elf->u_shdr.shdr32 = NULL;
		set_header32(elf, file);
		print_elf32(elf); // to remove
	}
	else
	{
		elf->u_ehdr.elf64 = malloc(sizeof(Elf64_Ehdr)); // separate alloc function
		elf->u_phdr.phdr64 = NULL;
		elf->u_shdr.shdr64 = NULL;
		
		set_header64(elf, file);
		print_elf64(elf); // to remove
	}
	// ft_exit(0, elf); // to remove
}
