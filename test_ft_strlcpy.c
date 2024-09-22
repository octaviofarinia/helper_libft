/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofarina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:11:34 by ofarina           #+#    #+#             */
/*   Updated: 2024/09/22 15:22:14 by ofarina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>
#include <string.h>
#define MAX_LEN 50

size_t strlcpy(char *dst, const char *src, size_t n) {
    char *p = dst;

    if (n != 0) {
        for (; --n != 0; p++, src++) {
            if ((*p = *src) == '\0')
                return p - dst;
        }
        *p = '\0';
    }
    return (p - dst) + strlen(src);
}

int test_ft_strlcpy(void)
{
	char source1[MAX_LEN] = "This is the source string";
	char target_libc1[MAX_LEN] = "This is the target string";
	char target_ft1[MAX_LEN] = "This is the target string";

	size_t libc_len1 = strlcpy(target_libc1, source1, sizeof(target_libc1));

	size_t ft_len1 = ft_strlcpy(target_ft1, source1, sizeof(target_ft1));

	if (libc_len1 != ft_len1 || memcmp(target_libc1, target_ft1, sizeof(target_libc1)) != 0)
	{
		printf("ft_strlcpy differs from strlcpy (Test Case 1: Normal string copy).\n");
		printf("\tAfter strlcpy: \"%s\" (return value: %zu)\n", target_libc1, libc_len1);
		printf("\tAfter ft_strlcpy: \"%s\" (return value: %zu)\n", target_ft1, ft_len1);
		return (1);
	}
	return (0);
}
