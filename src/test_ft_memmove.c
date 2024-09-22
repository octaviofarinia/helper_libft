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

#include "../include/tests_libft.h"
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

// Structure to define a single test case for memmove
typedef struct s_memmove_test_case {
    const char *description;
    char source[MAX_LEN];
    char expected[MAX_LEN];
    size_t n;
    size_t overlap_offset; // Offset for overlapping scenarios
} t_memmove_test_case;

// Test Function Implementation
int test_ft_memmove(void)
{
    // Define multiple test cases
    t_memmove_test_case test_cases[] = {
        {
            "Non-overlapping regions",
            "1234567890",
            "abcdefghij",
            5,
            0
        },
        {
            "Overlap: dest < src",
            "OverlapTest",
            "OverlapTest",
            6,
            0
        },
        {
            "Overlap: dest > src",
            "OverlapTest",
            "OverlapTest",
            6,
            2
        },
        {
            "Zero bytes to move",
            "NoMove",
            "InitialDest",
            0,
            0
        },
        {
            "Entire buffer move",
            "FullBufferMove",
            "FullBufferMove",
            MAX_LEN,
            0
        }
    };

    int num_cases = sizeof(test_cases) / sizeof(test_cases[0]);
    int fail = 0;

    int i = 0;
    while(i < num_cases)
    {
        char dest_libc[MAX_LEN];
        char dest_ft[MAX_LEN];

        // Initialize destination buffers with 'a's for visibility
        memset(dest_libc, 'a', MAX_LEN - 1);
        dest_libc[MAX_LEN - 1] = '\0';

        memset(dest_ft, 'a', MAX_LEN - 1);
        dest_ft[MAX_LEN - 1] = '\0';

        // Copy expected result into destination buffers
        strncpy(dest_libc, test_cases[i].expected, MAX_LEN - 1);
        strncpy(dest_ft, test_cases[i].expected, MAX_LEN - 1);

        // Calculate actual source and destination pointers for overlapping
        char *src_ptr_libc = dest_libc + test_cases[i].overlap_offset;
        char *src_ptr_ft = dest_ft + test_cases[i].overlap_offset;

        // Perform standard memmove
        memmove(src_ptr_libc, test_cases[i].source, test_cases[i].n);

        // Perform ft_memmove
        ft_memmove(src_ptr_ft, test_cases[i].source, test_cases[i].n);

        // Compare the results
        if (memcmp(dest_libc, dest_ft, MAX_LEN) != 0)
        {
            printf(COLOR_RED "Test ft_memmove FAILED: %s\n" COLOR_RESET, test_cases[i].description);
            printf("\tSource: \"%s\"\n", test_cases[i].source);
            printf("\tBytes to move: %zu\n", test_cases[i].n);
            printf("\tAfter memmove:   \"%s\"\n", dest_libc);
            printf("\tAfter ft_memmove:\"%s\"\n", dest_ft);
            printf("\n");
            fail = 1;
        }
        else
        {
            printf(COLOR_GREEN "Test ft_memmove PASSED: %s\n" COLOR_RESET, test_cases[i].description);
        }
		i++;
    }

    return fail ? 1 : 0;
}

