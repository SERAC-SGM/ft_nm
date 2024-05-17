/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:45:59 by lletourn          #+#    #+#             */
/*   Updated: 2024/05/17 11:16:19 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/nm.h"
#include <sys/stat.h>

void	*map_file(int fd)
{
	struct stat	st;
	void		*file;

	if (fstat(fd, &st) < 0)
	{
		perror("fstat");
		exit(1);
	}
	if (st.st_size == 0)
		exit(1);
	file = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (file == MAP_FAILED)
	{
		perror("mmap");
		exit(1);
	}
	return (file);
}

int	nm(char *file)
{
	t_elfheader	elf;
	void		*mapped_file;
	int			fd;

	fd = open(file, O_RDONLY);
	mapped_file = map_file(fd);
	parse_header(&elf, mapped_file);
	// parse_program_header();
	// parse_section_header();
	close(fd);
	return (0);
}
