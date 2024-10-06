#include "../include/tests_libft.h"
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

#define COLOR_RED "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_RESET "\x1b[0m"

typedef struct s_bzero_test_case {
    const char *description;
    size_t n;
    const char *initial_dest;
} t_bzero_test_case;

int test_ft_bzero(void);

int test_ft_bzero(void)
{
    t_bzero_test_case test_cases[] = {
        {
            "Basic zeroing of 5 bytes",
            5,
            "InitialDataHere"
        },
        {
            "Zero zero bytes",
            0,
            "No Change Expected"
        },
        {
            "Zero entire buffer",
            MAX_LEN - 1,
            "Buffer will be entirely zeroed out."
        },
        {
            "Zero with n larger than buffer size",
            MAX_LEN + 10,
            "Partial Zeroing"
        },
        {
            "Zero in the middle of buffer",
            10,
            "12345InitialData67890"
        },
        {
            "Zero on buffer already containing zeros",
            10,
            "\0\0\0\0\0AlreadyZeroed"
        },
        {
            "Zero empty string",
            5,
            ""
        }
    };

    int num_cases = sizeof(test_cases) / sizeof(test_cases[0]);
    int fail = 0;
    int i = 0;

    while (i < num_cases)
    {
        char dest_libc[MAX_LEN];
        char dest_ft[MAX_LEN];

        strncpy(dest_libc, test_cases[i].initial_dest, MAX_LEN - 1);
        dest_libc[MAX_LEN - 1] = '\0';

        strncpy(dest_ft, test_cases[i].initial_dest, MAX_LEN - 1);
        dest_ft[MAX_LEN - 1] = '\0';

        bzero(dest_libc, test_cases[i].n);

        ft_bzero(dest_ft, test_cases[i].n);

        if (memcmp(dest_libc, dest_ft, MAX_LEN) != 0)
        {
            printf(COLOR_RED "Test ft_bzero FAILED: %s\n" COLOR_RESET, test_cases[i].description);
            printf("\tBytes to zero: %zu\n", test_cases[i].n);
            printf("\tAfter bzero:   \"");
            for (size_t j = 0; j < MAX_LEN; j++)
            {
                if (dest_libc[j] == '\0')
                    printf("\\0");
                else
                    printf("%c", dest_libc[j]);
            }
            printf("\"\n");
            printf("\tAfter ft_bzero:\"");
            for (size_t j = 0; j < MAX_LEN; j++)
            {
                if (dest_ft[j] == '\0')
                    printf("\\0");
                else
                    printf("%c", dest_ft[j]);
            }
            printf("\"\n\n");
            fail = 1;
        }
        else
        {
            printf(COLOR_GREEN "Test ft_bzero PASSED: %s\n" COLOR_RESET, test_cases[i].description);
        }
        i++;
    }

    return (fail ? 1 : 0);
}
