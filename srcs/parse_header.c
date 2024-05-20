/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:20:47 by lletourn          #+#    #+#             */
/*   Updated: 2024/05/20 17:25:07 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/nm.h"
#include <elf.h>

static int	check_signature(char *file)
{
	if (file[EI_MAG0] == ELFMAG0 && file[EI_MAG1] == ELFMAG1
		&& file[EI_MAG2] == ELFMAG2 && file[EI_MAG3] == ELFMAG3)
		return (SUCCESS);
	ft_printf("Invalid file signature\n");
	return (FAILURE);
}

static int	check_ei_class(char *file)
{
	if (file[EI_CLASS] == ELFCLASS32 || file[EI_CLASS] == ELFCLASS64)
		return (SUCCESS);
	printf("Invalid class format\n");
	return (FAILURE);
}

static int	check_ei_data(char *file)
{
	if (file[EI_DATA] == ELFDATA2LSB || file[EI_DATA] == ELFDATA2MSB)
		return (SUCCESS);
	ft_printf("Invalid data format\n");
	return (FAILURE);
}

static int	check_ei_version(char *file)
{
	if (file[EI_VERSION] == EV_CURRENT)
		return (SUCCESS);
	ft_printf("Invalid header version\n");
	return (FAILURE);
}

static int	check_e_version(char *file)
{
	if (file[EI_VERSION] == EV_CURRENT)
		return (SUCCESS);
	ft_printf("Invalid object file version\n");
	return (FAILURE);
}

static int	check_file_size(char *file, unsigned long size)
{
	if (file[EI_CLASS] == ELFCLASS32 && size < HEADEROFFSET32)
	{
		ft_printf("Invalid or corrupted file\n");
		return (FAILURE);
	}
	else if (file[EI_CLASS] == ELFCLASS64 && size < HEADEROFFSET64)
	{
		ft_printf("Invalid or corrupted file\n");
		return (FAILURE);
	}
	return (SUCCESS);
}

static int	check_e_type(char *file)
{
	t_elf_half e_type;
	
	e_type = ((Elf32_Ehdr * )file)->e_type;
	if (e_type == ET_NONE || e_type == ET_REL || e_type == ET_EXEC
		|| e_type == ET_DYN || e_type == ET_CORE)
		return (SUCCESS);
	ft_printf("Invalid object file type\n");
	return (FAILURE);
}

static int	check_offsets(char *file, unsigned long size)
{
	Elf32_Off	e_phoff32;
	Elf32_Off	e_shoff32;
	Elf64_Off	e_phoff64;
	Elf64_Off	e_shoff64;

	if (file[EI_CLASS] == ELFCLASS32) goto x32;
	else if (file[EI_CLASS] == ELFCLASS64) goto x64;

x32:
	e_phoff32 = ((Elf32_Ehdr *)file)->e_phoff;
	e_shoff32 = ((Elf32_Ehdr *)file)->e_shoff;
	if (e_phoff32 > size || e_shoff32 > size)
		goto error;
	return (SUCCESS);

x64:
	e_phoff64 = ((Elf64_Ehdr *)file)->e_phoff;
	e_shoff64 = ((Elf64_Ehdr *)file)->e_shoff;
	if (e_phoff64 > size || e_shoff64 > size)
		goto error;
	return (SUCCESS);

error:
	ft_printf("Invalid or corrupted file\n");
	return (FAILURE);
}


int	parse_header(t_elfheader *elf, void *file)
{
	if (check_signature(file) == FAILURE
		|| check_ei_class(file) == FAILURE
		|| check_file_size(file, elf->file_size) == FAILURE
		|| check_ei_data(file) == FAILURE
		|| check_ei_version(file) == FAILURE
		|| check_e_type(file) == FAILURE
		|| check_e_version(file) == FAILURE
		|| check_offsets(file, elf->file_size) == FAILURE)
		return (FAILURE);
	elf->ei_class = ((char *)file)[EI_CLASS];
	elf->ei_data = ((char *)file)[EI_DATA];
	if (elf->ei_class == ELFCLASS32)
	{
		set_header32(elf, file);
		print_elf32(elf); // to remove
	}
	else
	{
		set_header64(elf, file);
		print_elf64(elf); // to remove
	}
	return (SUCCESS);
}
