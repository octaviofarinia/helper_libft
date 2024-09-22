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

#include "../include/tests_libft.h"
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

// Structure to define a single test case for strlcat
typedef struct s_strlcat_test_case {
    const char *description;
    char dest_libc[MAX_LEN];
    const char *src;
    size_t size;
    size_t expected_length; // Expected return value
} t_strlcat_test_case;

// Test Function Implementation
int test_ft_strlcat(void)
{
    // Define multiple test cases
    t_strlcat_test_case test_cases[] = {
        {
            "Normal concatenation with sufficient size",
            "Hello, ",
            "World!",
            20,
            13
        },
        {
            "Concatenation with exact buffer size",
            "Exact",
            "Size",
            10,
            9
        },
        {
            "Concatenation with size zero",
            "NoChange",
            "ShouldNotAppend",
            0,
            15
        },
        {
            "Concatenation where buffer size less than dest length",
            "LongDestination",
            "Append",
            10,
            15
        },
        {
            "Empty source string",
            "InitialDest",
            "",
            15,
            11
        },
        {
            "Empty destination string",
            "",
            "Source",
            10,
            6
        }
    };

    int num_cases = sizeof(test_cases) / sizeof(test_cases[0]);
    int fail = 0;

    int i = 0;
    while(i < num_cases)
    {
        // Initialize destination buffers
        memset(test_cases[i].dest_libc, 'X', MAX_LEN - 1);
        test_cases[i].dest_libc[MAX_LEN - 1] = '\0';

        strncpy(test_cases[i].dest_libc, test_cases[i].dest_libc, MAX_LEN - 1); // Already set to 'X's

        // Make a copy for ft_strlcat
        char dest_ft[MAX_LEN];
        strncpy(dest_ft, test_cases[i].dest_libc, MAX_LEN - 1);
        dest_ft[MAX_LEN - 1] = '\0';

        // Perform standard strlcat
        size_t ret_libc = strlcat(test_cases[i].dest_libc, test_cases[i].src, test_cases[i].size);

        // Perform ft_strlcat
        size_t ret_ft = ft_strlcat(dest_ft, test_cases[i].src, test_cases[i].size);

        // Compare return values and destination buffers
        if (ret_libc != ret_ft || strcmp(test_cases[i].dest_libc, dest_ft) != 0)
        {
            printf(COLOR_RED "Test ft_strlcat FAILED: %s\n" COLOR_RESET, test_cases[i].description);
            printf("\tDestination: \"%s\"\n", test_cases[i].dest_libc);
            printf("\tSource: \"%s\"\n", test_cases[i].src);
            printf("\tSize: %zu\n", test_cases[i].size);
            printf("\tReturn value (strlcat): %zu\n", ret_libc);
            printf("\tReturn value (ft_strlcat): %zu\n", ret_ft);
            printf("\tDestination after strlcat: \"%s\"\n", test_cases[i].dest_libc);
            printf("\tDestination after ft_strlcat:\"%s\"\n", dest_ft);
            printf("\n");
            fail = 1;
        }
        else
        {
            printf(COLOR_GREEN "Test ft_strlcat PASSED: %s\n" COLOR_RESET, test_cases[i].description);
        }
		i++;
    }

    return fail ? 1 : 0;
}
