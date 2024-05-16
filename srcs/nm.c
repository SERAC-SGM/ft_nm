/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:45:59 by lletourn          #+#    #+#             */
/*   Updated: 2024/05/16 17:15:50 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/nm.h"

int	nm(char *files)
{
	struct stat	st;
	void		*file_start;
	t_elfheader	header;
	int			fd;

	fd = open(files, O_RDONLY);
	if (fstat(fd, &st) < 0)
	{
		perror("fstat");
		return (1);
	}
	if (st.st_size == 0)
		exit(1);
	if ((file_start = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0))
		== MAP_FAILED)
	{
		perror("mmap");
		return (1);
	}
	header = parse_header(file_start);
	close(fd);
	return (0);
}
