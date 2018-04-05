/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 18:32:35 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/04/03 18:32:50 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd;
	char *str;
	int check;

	fd = open("file", O_RDONLY);
	while ((check = get_next_line(fd, &str)))
	{
		printf("%d\n", check);
		printf("%s\n", str);
		str = NULL;
	}
	// get_next_line(fd, &str);
	// printf("fd: %s\n", str);
	// int fd1 = open("file1", O_RDONLY);
	// str = NULL;
	// get_next_line(fd, &str);
	// printf("fd: %s\n", str);
	// str = NULL;
	// get_next_line(fd1, &str);
	// printf("fd1: %s\n", str);
	// str = NULL;
	// get_next_line(fd1, &str);
	// printf("fd1: %s\n", str);
	printf("%d\n", check);
	close(fd);
	//close(fd1);
	return 0;
}
