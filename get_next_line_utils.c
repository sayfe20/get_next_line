/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:36:02 by sahamzao          #+#    #+#             */
/*   Updated: 2024/01/22 00:03:49 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *allocation_manager(int fd)
{
	static char *save;
	int rd;
	char *buffer;
	
	rd = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	while(rd != 0)
	{
		rd = read(fd,buffer,BUFFER_SIZE);
		if(rd == 0 || rd == -1)
		{
			free(buffer);
			buffer = NULL;
			return save;
		}
		buffer[rd] = '\0';
		save = ft_strcat(save,buffer);
		if(!ft_newline_check(buffer))
			break;

	}
	free(buffer);
	return save;
}
int ft_newline_check(char *string)
{
	int i = 0 ;
	while(string[i])
	{
		if(string[i] == '\n')
			return 0;
		i++;
	}
	return 1;
}

char    *ft_strcat(char *string1, char *string2)
{
	int s1;
	int s2;
	char *ptr;
	int i = 0;
	int j = 0;
	if(!string1)
	{
		string1 = malloc(1);
		string1[0] = '\0';
	}
	if(!string1 || !string2)
		return NULL;
	s1 = ft_strlen(string1);
	s2 = ft_strlen(string2);
	ptr = malloc(s1  + s2 + 1);
	if(!ptr)
		return NULL;
	while(string1[i])
	{
		ptr[i] = string1[i];
		i++;
	}
	while(string2[j])
	{
		ptr[i + j] = string2[j];
		j++;
	}
	ptr[i+j] = '\0';
	free(string1);
	return ptr;
}


int  ft_strlen(char *string)
{
    int i;
    i = 0;
    while (string[i])
		i++;
    return (i);
}
