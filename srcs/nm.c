/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:45:59 by lletourn          #+#    #+#             */
/*   Updated: 2024/05/20 16:46:38 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/nm.h"
#include <sys/stat.h>

static void	*map_file(t_elfheader *elf, int fd)
{
	struct stat	st;
	void		*file;

	if (fstat(fd, &st) < 0)
	{
		perror("");
		exit(1);
	}
	if (st.st_size == 0)
		goto error;
	elf->file_size = st.st_size;
	file = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (file == MAP_FAILED)
	{
		perror("");
		goto error;
	}
	return (file);

	error:
		return (NULL);
}

int	nm(char *file)
{
	t_elfheader	elf;
	void		*mapped_file;
	int			fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("");
		return (1);
	}
	mapped_file = map_file(&elf, fd);
	if (!mapped_file)
		goto error;
	if (parse_header(&elf, mapped_file) == FAILURE)
		goto error;
	if (parse_program_header(&elf, file) == FAILURE)
		goto error;
	close(fd);
	return (0);

error:
	close(fd);
	return (1);
}
