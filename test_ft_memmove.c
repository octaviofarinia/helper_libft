/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memmove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofarina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:19:35 by ofarina           #+#    #+#             */
/*   Updated: 2024/09/22 14:20:37 by ofarina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>
#include <string.h>
#define MAX_LEN 80

int test_ft_memmove(void)
{
	char source[MAX_LEN] = "This is the source string";

	char target_libc[MAX_LEN] = "This is the target string";
	char target_ft[MAX_LEN] = "This is the target string";

	memmove(target_libc, source, sizeof(source));

	ft_memmove(target_ft, source, sizeof(source));

	if (memcmp(target_libc, target_ft, sizeof(source)) != 0)
	{
		printf("ft_memmove differs from memmove.\n");
		printf("\tAfter memmove: \"%s\"\n", target_libc);
		printf("\tAfter ft_memmove: \"%s\"\n", target_ft);
		return 1;
	}

	return 0;
}
