/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofarina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:36:02 by ofarina           #+#    #+#             */
/*   Updated: 2024/09/22 15:39:27 by ofarina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>
#include <string.h>
#define MAX_LEN 50

size_t strlcat(char *dst, const char *src, size_t n) {
    char *p = dst;

    while (n != 0 && *p != '\0') {
        p++;
        n--;
    }
    if (n != 0) {
        for (; --n != 0; p++, src++) {
            if ((*p = *src) == '\0')
                return p - dst;
        }
        *p = '\0';
    }
    return (p - dst) + strlen(src);
}

int test_ft_strlcat(void)
{
    char src[MAX_LEN] = " World!";
    char target_libc[MAX_LEN] = "Hello";
    char target_ft[MAX_LEN] = "Hello";

    size_t size = sizeof(target_libc);
    size_t libc_result, ft_result;

    libc_result = strlcat(target_libc, src, size);

    ft_result = ft_strlcat(target_ft, src, size);

    if (libc_result != ft_result
		|| memcmp(target_libc, target_ft, sizeof(target_libc)) != 0)
    {
        printf("ft_strlcat differs from strlcat.\n");
        printf("\tAfter strlcat: \"%s\" (return value: %zu)\n", target_libc, libc_result);
        printf("\tAfter ft_strlcat: \"%s\" (return value: %zu)\n", target_ft, ft_result);
        return (1);
    }
    return (0);
}
