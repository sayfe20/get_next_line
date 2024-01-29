/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:36:02 by sahamzao          #+#    #+#             */
/*   Updated: 2024/01/23 02:43:11 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	allocation_manager(int fd, char **save)
{
	int		rd;
	char	*buffer;

	rd = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return ;
	while (rd != 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buffer);
			buffer = NULL;
			free(*save);
			*save = NULL;
			return ;
		}
		buffer[rd] = '\0';
		*save = ft_strcat(*save, buffer);
		if (!ft_newline_check(buffer))
			break ;
	}
	free(buffer);
}

int	ft_newline_check(char *string)
{
	int	i;

	i = 0;
	if (!string)
		return (0);
	while (string[i])
	{
		if (string[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

void	*ft_cpy(char *string, char *string1, int n)
{
	int	i;

	i = 0;
	if (!string || !string1)
		return (NULL);
	while (string1[i] && i < n)
	{
		string[i] = string1[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

char	*ft_strcat(char *string1, char *string2)
{
	char	*ptr;

	if (!string1)
	{
		string1 = malloc(1);
		string1[0] = '\0';
	}
	if (!string2 || !string1)
	{
		free(string1);
		string1 = NULL;
		return (NULL);
	}
	ptr = malloc(ft_strlen(string1) + ft_strlen(string2) + 1);
	if (!ptr)
	{
		free(string1);
		string1 = NULL;
		return (NULL);
	}
	ft_cpy(ptr, string1, ft_strlen(string1));
	ft_cpy(ptr + ft_strlen(string1), string2, ft_strlen(string2));
	free(string1);
	string1 = NULL;
	return (ptr);
}

int	ft_strlen(char *string)
{
	int	i;

	i = 0;
	if (!string)
		return (0);
	while (string[i])
		i++;
	return (i);
}
