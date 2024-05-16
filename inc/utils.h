/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lletourn <lletourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:33:18 by lletourn          #+#    #+#             */
/*   Updated: 2024/05/15 17:52:03 by lletourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "struct.h"

void	print_elf32(t_elfheader *elf);
void	print_elf64(t_elfheader *elf);
void	ft_exit(char num, t_elfheader *elf);

#endif
