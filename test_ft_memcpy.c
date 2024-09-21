/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofarina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 18:41:19 by ofarina           #+#    #+#             */
/*   Updated: 2024/09/21 19:05:37 by ofarina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>
#include <string.h>
#define MAX_LEN 80

int test_ft_memcpy(void)
{
	char source[MAX_LEN] = "This is the source string";

	char target_libc[MAX_LEN] = "This is the target string";
	char target_ft[MAX_LEN] = "This is the target string";

	memcpy(target_libc, source, sizeof(source));

	ft_memcpy(target_ft, source, sizeof(source));

	if (memcmp(target_libc, target_ft, sizeof(source)) != 0)
	{
		printf("ft_memcpy differs from memcpy.\n");
		printf("\tAfter memcpy: \"%s\"\n", target_libc);
		printf("\tAfter ft_memcpy: \"%s\"\n", target_ft);
		return 1;
	}

	return 0;
}
