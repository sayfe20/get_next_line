/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:36:29 by sahamzao          #+#    #+#             */
/*   Updated: 2024/01/21 23:15:07 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GETNEXTLINE_H
#define GETNEXTLINE_H
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

char	*get_next_line(int fd);
char *here(char *string);
int ft_newline_check(char *string);
int ft_strlen(char *string);
char *allocation_manager(int fd);
char    *ft_strcat(char *string1, char *string2);
#endif
