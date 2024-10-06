#include "../include/tests_libft.h"
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

typedef struct s_memset_test_case {
    const char *description;
    int value;
    size_t n;
    const char *initial_dest;
} t_memset_test_case;

int test_ft_memset(void);

int test_ft_memset(void)
{
    t_memset_test_case test_cases[] = {
        {
            "Basic set",
            'A',
            5,
            "Initial Data"
        },
        {
            "Set zero bytes",
            'B',
            0,
            "Initial Data"
        },
        {
            "Set entire buffer",
            'C',
            MAX_LEN - 1,
            "Initial Data for entire buffer set"
        },
        {
            "Set with zero value",
            0,
            10,
            "Initial Data"
        },
        {
            "Set with max unsigned char value",
            255,
            10,
            "Initial Data"
        },
        {
            "Set in the middle of buffer",
            'D',
            10,
            "12345InitialData67890"
        },
        {
            "Set with overlapping regions (dest same as source)",
            'E',
            15,
            "Same Source and Dest"
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

        memset(dest_libc, test_cases[i].value, test_cases[i].n);

        ft_memset(dest_ft, test_cases[i].value, test_cases[i].n);

        if (memcmp(dest_libc, dest_ft, MAX_LEN) != 0)
        {
            printf(COLOR_RED "Test ft_memset FAILED: %s\n" COLOR_RESET, test_cases[i].description);
            printf("\tValue: %d\n", test_cases[i].value);
            printf("\tBytes to set: %zu\n", test_cases[i].n);
            printf("\tAfter memset:   \"%s\"\n", dest_libc);
            printf("\tAfter ft_memset:\"%s\"\n", dest_ft);
            printf("\n");
            fail = 1;
        }
        else
        {
            printf(COLOR_GREEN "Test ft_memset PASSED: %s\n" COLOR_RESET, test_cases[i].description);
        }
        i++;
    }

    return fail ? 1 : 0;
}
