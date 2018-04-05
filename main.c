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

	fd = open("file", O_RDONLY);
	get_next_line(fd, &str);
	//printf("%s", str);
	//printf("%c\n", '/');
	close(fd);
	return 0;
}
