#include "../include/tests_libft.h"
#include <stdio.h>
#include <string.h>

#define COLOR_RED "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_RESET "\x1b[0m"

typedef struct s_strlen_test_case {
    const char *description;
    const char *input;
    size_t expected;
} t_strlen_test_case;

int test_ft_strlen(void);

int test_ft_strlen(void)
{
    t_strlen_test_case test_cases[] = {
        {
            "Empty string",
            "",
            0
        },
        {
            "Single character",
            "a",
            1
        },
        {
            "Short string",
            "Hello, World!",
            13
        },
        {
            "String with spaces",
            "This is a test string.",
            21
        },
        {
            "String with special characters",
            "Café Münsterländer",
            17
        },
        {
            "Long string",
            "The quick brown fox jumps over the lazy dog",
            43
        },
        {
            "String with null bytes",
            "Null\0Byte\0Test",
            4
        }
    };

    int num_cases = sizeof(test_cases) / sizeof(test_cases[0]);
    int fail = 0;
    int i = 0;

    while (i < num_cases)
    {
        size_t libc_len = strlen(test_cases[i].input);
        size_t ft_len = ft_strlen(test_cases[i].input);

        if (libc_len != ft_len)
        {
            printf(COLOR_RED "Test ft_strlen FAILED: %s\n" COLOR_RESET, test_cases[i].description);
            printf("\tInput: \"%s\"\n", test_cases[i].input);
            printf("\tExpected: %zu, Got: %zu\n\n", libc_len, ft_len);
            fail = 1;
        }
        else
        {
            printf(COLOR_GREEN "Test ft_strlen PASSED: %s\n" COLOR_RESET, test_cases[i].description);
        }
        i++;
    }

    return (fail ? 1 : 0);
}
