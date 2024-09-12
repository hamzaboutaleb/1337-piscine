/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:50:04 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/11 10:47:25 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <libgen.h>
#include <unistd.h>
#define BUFFER_SIZE 30720

void	ft_print(char *s, int end);
void	ft_perror(char *program_name, char *filename);
void	ft_print_content(int fp);
void	interactive_mode(void);
void	read_files(char **files, int size);