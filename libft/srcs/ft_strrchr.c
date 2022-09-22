/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hommayunosuke <hommayunosuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:31:50 by hommayunosu       #+#    #+#             */
/*   Updated: 2022/09/22 13:31:51 by hommayunosu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len_s;
	char	*new_s;

	new_s = (char *) s;
	len_s = ft_strlen(s);
	if (c == 0)
		return (new_s + len_s);
	while (len_s--)
	{
		if (new_s[len_s] == (char) c)
			return (new_s + len_s);
	}
	return (NULL);
}

//L19 -1 -> address back due to while(len_s--)

/*#include <stdio.h>
#include <string.h>

int main(void)
{
	char *a = NULL;
	int b = 'a';

	printf("%s\n", ft_strrchr(a, b));

	char *c = NULL;
	int d = 'a';

	printf("%s\n", strrchr(c, d));
}*/
//if s == NULL SIGSEGV (same as the original)