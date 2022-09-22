/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hommayunosuke <hommayunosuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:31:29 by hommayunosu       #+#    #+#             */
/*   Updated: 2022/09/22 13:31:30 by hommayunosu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
//do something for each char

/*
#include <stdio.h>
#include <string.h>

void	additional_func(unsigned int i, char *s)
{
	*s += i;
}

int main(void)
{
	char a[] = "0000000000";
	ft_striteri(a, additional_func);

	printf("%d\n", strcmp(a, "0123456789"));
}
 */