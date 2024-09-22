/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofarina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 18:41:19 by ofarina           #+#    #+#             */
/*   Updated: 2024/09/22 14:18:55 by ofarina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tests_libft.h"
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

// Structure to define a single test case for memcpy
typedef struct s_memcpy_test_case {
    const char *description;    // Description of the test case
    const char *source;         // Source string
    size_t n;                   // Number of bytes to copy
    const char *initial_dest;   // Initial content of destination
} t_memcpy_test_case;

// Function Prototype
int test_ft_memcpy(void);

// Test Function Implementation
int test_ft_memcpy(void)
{
    // Define multiple test cases
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
            MAX_LEN - 1,  // Copy up to the buffer size minus null terminator
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
            14,  // Including the null bytes
            "Destination with initial data"
        }
    };
    
    int num_cases = sizeof(test_cases) / sizeof(test_cases[0]);
    int fail = 0; // Flag to indicate if any test case fails

	int i = 0;
    while(i < num_cases)
    {
        // Allocate and initialize destination buffers
        char dest_libc[MAX_LEN];
        char dest_ft[MAX_LEN];

        // Initialize destinations with the initial_dest string
        strncpy(dest_libc, test_cases[i].initial_dest, MAX_LEN - 1);
        dest_libc[MAX_LEN - 1] = '\0'; // Ensure null-termination

        strncpy(dest_ft, test_cases[i].initial_dest, MAX_LEN - 1);
        dest_ft[MAX_LEN - 1] = '\0'; // Ensure null-termination

        // Perform standard memcpy
        memcpy(dest_libc, test_cases[i].source, test_cases[i].n);

        // Perform ft_memcpy
        ft_memcpy(dest_ft, test_cases[i].source, test_cases[i].n);

        // Compare the results
        if (memcmp(dest_libc, dest_ft, MAX_LEN) != 0)
        {
            printf(COLOR_RED "Test ft_memcpy FAILED: %s\n" COLOR_RESET, test_cases[i].description);
            printf("\tSource: \"%s\"\n", test_cases[i].source);
            printf("\tBytes to copy: %zu\n", test_cases[i].n);
            printf("\tAfter memcpy:   \"%s\"\n", dest_libc);
            printf("\tAfter ft_memcpy:\"%s\"\n", dest_ft);
            printf("\n");
            fail = 1; // Mark as failed
        }
        else
        {
            printf(COLOR_GREEN "Test ft_memcpy PASSED: %s\n" COLOR_RESET, test_cases[i].description);
        }
		i++;
    }

    // Return 1 if any test case failed, else 0
    return fail ? 1 : 0;
}
