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

int main(int argc, char **argv)
{
	// int fd;
	// char *str;
	// int check;

	 argc = 0;
	// fd = open(argv[1], O_RDONLY);
	// while((check = get_next_line(fd, &str)))
	// 	printf("%s\n", str);
	char *str;
	char *line;

	str = (char *)malloc(1000 * 1000);
	*str = '\0';
	strcat(str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus");
	strcat(str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus");
	strcat(str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus");
	int fd = open(argv[1], O_RDONLY);
	write(fd, str, strlen(str));
	close(fd);
	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, &line);
	if(ft_strcmp(str, line) == 0)
		ft_putstr("OK");
	else
		ft_putstr("Fail");

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
	close(fd);
	//close(fd1);
	return 0;
}
