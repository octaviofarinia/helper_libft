/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofarina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 18:41:19 by ofarina           #+#    #+#             */
/*   Updated: 2024/09/24 20:08:33 by ofarina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tests_libft.h"
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

typedef struct s_memcpy_test_case {
    const char *description;
    const char *source;
    size_t n;
    const char *initial_dest;
} t_memcpy_test_case;

int test_ft_memcpy(void);

int test_ft_memcpy(void)
{
    t_memcpy_test_case test_cases[] = {
        {
            "Basic copy",
            "Hello, World!",
            13,
            "Destination"
        },
        {
            "Copy zero bytes",
            "No copy",
            0,
            "Original Destination"
        },
        {
            "Copy entire buffer",
            "Full buffer copy",
            MAX_LEN - 1,
            "Destination Buffer with initial data"
        },
        {
            "Empty source string",
            "",
            10,
            "Non-empty Destination"
        },
        {
            "Source and destination are the same",
            "Same Source and Dest",
            20,
            "Same Source and Dest"
        },
        {
            "Source buffer larger than destination buffer",
            "This source string is longer than the destination buffer size.",
            MAX_LEN - 1,
            "Initial Dest Buffer"
        },
        {
            "Source contains null bytes",
            "Null\0Byte\0Test",
            14,
            "Destination with initial data"
        }
    };
    
    int num_cases = sizeof(test_cases) / sizeof(test_cases[0]);
    int fail = 0;

	int i = 0;
    while(i < num_cases)
    {
        char dest_libc[MAX_LEN];
        char dest_ft[MAX_LEN];

        strncpy(dest_libc, test_cases[i].initial_dest, MAX_LEN - 1);
        dest_libc[MAX_LEN - 1] = '\0';

        strncpy(dest_ft, test_cases[i].initial_dest, MAX_LEN - 1);
        dest_ft[MAX_LEN - 1] = '\0';

        memcpy(dest_libc, test_cases[i].source, test_cases[i].n);

        ft_memcpy(dest_ft, test_cases[i].source, test_cases[i].n);

        if (memcmp(dest_libc, dest_ft, MAX_LEN) != 0)
        {
            printf(COLOR_RED "Test ft_memcpy FAILED: %s\n" COLOR_RESET, test_cases[i].description);
            printf("\tSource: \"%s\"\n", test_cases[i].source);
            printf("\tBytes to copy: %zu\n", test_cases[i].n);
            printf("\tAfter memcpy:   \"%s\"\n", dest_libc);
            printf("\tAfter ft_memcpy:\"%s\"\n", dest_ft);
            printf("\n");
            fail = 1;
        }
        else
        {
            printf(COLOR_GREEN "Test ft_memcpy PASSED: %s\n" COLOR_RESET, test_cases[i].description);
        }
		i++;
    }

    return fail ? 1 : 0;
}
