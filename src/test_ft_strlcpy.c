/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofarina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:11:34 by ofarina           #+#    #+#             */
/*   Updated: 2024/09/24 20:09:53 by ofarina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tests_libft.h"
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

typedef struct s_strlcpy_test_case {
    const char *description;
    const char *source;
    char dest_libc[MAX_LEN];
    char dest_ft[MAX_LEN];
    size_t size;
    size_t expected_length;
} t_strlcpy_test_case;

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
    t_strlcpy_test_case test_cases[] = {
        {
            "Normal copy with sufficient size",
            "Hello, World!",
            "",
            "",
            20,
            13
        },
        {
            "Copy with exact size",
            "ExactSize",
            "",
            "",
            10,
            9
        },
        {
            "Copy with size zero",
            "NoCopy",
            "InitialDest",
            "InitialDest",
            0,
            6
        },
        {
            "Copy with size one",
            "A",
            "",
            "",
            1,
            1
        },
        {
            "Empty source string",
            "",
            "NonEmptyDest",
            "NonEmptyDest",
            10,
            0
        },
        {
            "Copy longer string with small buffer",
            "This is a very long source string.",
            "",
            "",
            10,
            31
        }
    };

    int num_cases = sizeof(test_cases) / sizeof(test_cases[0]);
    int fail = 0;

    int i = 0;
    while(i < num_cases)
    {
        memset(test_cases[i].dest_libc, 'X', MAX_LEN - 1);
        test_cases[i].dest_libc[MAX_LEN - 1] = '\0';

        memset(test_cases[i].dest_ft, 'X', MAX_LEN - 1);
        test_cases[i].dest_ft[MAX_LEN - 1] = '\0';

        size_t ret_libc = strlcpy(test_cases[i].dest_libc, test_cases[i].source, test_cases[i].size);

        size_t ret_ft = ft_strlcpy(test_cases[i].dest_ft, test_cases[i].source, test_cases[i].size);

        if (ret_libc != ret_ft || strcmp(test_cases[i].dest_libc, test_cases[i].dest_ft) != 0)
        {
            printf(COLOR_RED "Test ft_strlcpy FAILED: %s\n" COLOR_RESET, test_cases[i].description);
            printf("\tSource: \"%s\"\n", test_cases[i].source);
            printf("\tSize: %zu\n", test_cases[i].size);
            printf("\tReturn value (strlcpy): %zu\n", ret_libc);
            printf("\tReturn value (ft_strlcpy): %zu\n", ret_ft);
            printf("\tDestination (strlcpy): \"%s\"\n", test_cases[i].dest_libc);
            printf("\tDestination (ft_strlcpy): \"%s\"\n", test_cases[i].dest_ft);
            printf("\n");
            fail = 1;
        }
        else
        {
            printf(COLOR_GREEN "Test ft_strlcpy PASSED: %s\n" COLOR_RESET, test_cases[i].description);
        }
		i++;
    }

    return fail ? 1 : 0;
}

