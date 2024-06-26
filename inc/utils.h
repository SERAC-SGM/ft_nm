/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:33:18 by lletourn          #+#    #+#             */
/*   Updated: 2024/05/17 14:59:28 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "struct.h"

void	print_elf32(t_elfheader *elf);
void	print_elf64(t_elfheader *elf);
void	init_memory(t_elfheader *elf, char elfclass);
void	allocate_memory(t_elfheader *elf, char param);
void	ft_exit(char num, t_elfheader *elf);

#endif
