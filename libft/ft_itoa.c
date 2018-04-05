/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 18:43:04 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/03/21 22:32:39 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*res;
	int		size;
	int		i;

	size = 1;
	i = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	while ((i = i / 10))
		size++;
	if (n < 0)
		size += 1;
	if ((res = (char *)malloc(sizeof(*res) * size + 1)) == NULL)
		return (NULL);
	if (n < 0)
	{
		res[0] = '-';
		n *= -1;
	}
	res[size--] = '\0';
	res[size--] = n % 10 + 48;
	while ((n = n / 10))
		res[size--] = n % 10 + 48;
	return (res);
}
