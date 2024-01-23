/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:36:02 by sahamzao          #+#    #+#             */
/*   Updated: 2024/01/22 23:54:08 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

char *here(char *string)
{
	char *ptr;
	int i;
	int j = 0;

	i = 0;
	while(string[i] && string[i] != '\n')
		i++;
	if(string[i] == '\n')
		i++;
	ptr = malloc(i + 1);
	if(!ptr)
		return NULL;
	while(j < i)
	{
		ptr[j] = string[j];
		j++;
	}
	ptr[j] = '\0';
	return ptr;
}
char *new(char *string)
{
	int i;
	int j;
	char *ptr;
	int size;

	i = 0;
	while(*(string + i) && *(string + i) != '\n')
		i++;
	if (*(string + i) == '\n')
		i++;
	size = ft_strlen(string);
	ptr = malloc(size - i + 1);
	if(!ptr)
	{
		free(string);
		string = NULL;
		return NULL;
	}
		j = 0;
	while(i < size)
	{
		ptr[j] = string[i];
		i++;
		j++;
	}
	ptr[j] = '\0';
	free(string);
	return (ptr);
}
char	*get_next_line(int fd)
{
	static char *string;
	char *line;

	if(fd < 0 ||  BUFFER_SIZE < 0 )
		return NULL;
	allocation_manager(fd, &string);
	if(!string )
	{
		free(string);
		string = NULL;
		return(NULL);
	}
	if(string[0] == '\0')
	{
		free(string);
		string = NULL;
		return NULL;
	}
	line = here(string);
	string = new(string);
	return (line);
}
