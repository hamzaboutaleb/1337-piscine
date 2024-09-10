/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:50:04 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/10 14:50:06 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <libgen.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFFER_SIZE 1024 * 30

void	ft_print(char *s, int end);
void	ft_perror(char *program_name, char *filename);
void	ft_print_content(int fp);
void	interactive_mode(void);
void	read_files(char **files, int size);