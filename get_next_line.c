/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:16:18 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/04/03 16:16:20 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void do_smth(t_bufer **list, int fd)
{
    if (!(*list))
    {
        (*list) = (t_bufer *)malloc(sizeof(t_bufer));
        (*list)->fd = fd;
        (*list)->buf = NULL;
        (*list)->next = NULL;
    }
    else
    {
        while ((*list)->next)
        {
            if((*list)->fd == fd)
                return;
            (*list) = ((*list)->next);
        }
        if ((*list)->fd != fd)
        {
            (*list) = (t_bufer *)malloc(sizeof(t_bufer));
            (*list)->fd = fd;
            (*list)->buf = NULL;
            (*list)->next = NULL;
        }
    }
}

int check_smth(t_bufer **list, char **res, char *buf)
{
    char *temp;

    if ((temp = ft_strchr(buf, '\n')) == NULL)
            (*res) = ft_strjoin(*res, buf);
    else
    {
        (*res) = ft_strjoin(*res, ft_strsub(buf, 0, temp - buf));
        (*list)->buf = ft_strsub(buf , temp - buf + 1, BUFF_SIZE - (temp - buf) - 1);
        return 1;
    }
    return 0;
}

int get_next_line(const int fd, char **line)
{
    char buf[BUFF_SIZE + 1];
    char *temp;
    char *res;
    static t_bufer *list;
    int read_bytes;

    //do_smth(&list, fd);
    res = NULL;
    do_smth(&list, fd);
    while((read_bytes = read(fd, buf, BUFF_SIZE)))
    {
       // if (check_smth(&list, &res, buf))
           // break;
        if ((temp = ft_strchr(buf, '\n')) == NULL)
            res = ft_strjoin(res, buf);
        else
        {
            res = ft_strjoin(res, ft_strsub(buf, 0, temp - buf));
            list->buf = ft_strsub(buf , temp - buf + 1, BUFF_SIZE - (temp - buf) - 1);
            return 1;
        }
    }
    if (!read_bytes && !res)
         return 0;
    *line = res;
   // printf("\n----------------------------------\n");
   // (*line) = ft_strdup(res);
    //printf("%s", (*line));
 
    // (*line) = ft_strdup(res);
    // printf("%s\n", (*line));
   
    // res = NULL;
    // if ((temp = ft_strchr(list->buf, '\n')) == NULL)
    //     res = ft_strjoin(res, list->buf);
    // 
    // (*line) = ft_strdup(res);
    // printf("%s\n", (*line));
   
    // res = NULL;
    // if ((temp = ft_strchr(list->buf, '\n')) == NULL)
    //     res = ft_strjoin(res, list->buf);
    // else
    // {
    //    res = ft_strjoin(res, ft_strsub(list->buf, 0, temp - list->buf));
    //    list->buf = ft_strsub(list->buf , temp - list->buf + 1, ft_strlen(list->buf) - (temp - list->buf));
    // }
    // printf("%s", res);
    // printf("\n----------------------------------\n");
    // printf("%s", list->buf);
    // (*line) = ft_strdup(res);
    // printf("%s\n", (*line));
    // char c;
    // read(fd, &c, 1);
    // printf("%c\n", c);
    // read(fd, &c, 1);
    // printf("%c\n", c);
    return (1);
}



