#include "../include/tests_libft.h"
#include <stdio.h>
#include <string.h>

#define COLOR_RED "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_RESET "\x1b[0m"

typedef struct s_strncmp_test_case {
    const char *description;
    const char *s1;
    const char *s2;
    size_t n;
} t_strncmp_test_case;

int test_ft_strncmp(void);

int test_ft_strncmp(void)
{
    t_strncmp_test_case test_cases[] = {
        {
            "Both strings empty, n = 0",
            "",
            "",
            0
        },
        {
            "Both strings empty, n = 5",
            "",
            "",
            5
        },
        {
            "First string empty, second non-empty, n = 5",
            "",
            "Non-empty",
            5
        },
        {
            "Second string empty, first non-empty, n = 5",
            "Non-empty",
            "",
            5
        },
        {
            "Identical strings, n = 10",
            "HelloWorld",
            "HelloWorld",
            10
        },
        {
            "Identical strings, n = 5",
            "HelloWorld",
            "HelloWorld",
            5
        },
        {
            "Different strings, s1 < s2, n = 5",
            "Apple",
            "Banana",
            5
        },
        {
            "Different strings, s1 > s2, n = 5",
            "Banana",
            "Apple",
            5
        },
        {
            "Different strings, first difference after n",
            "HelloWorld",
            "HelloThere",
            5
        },
        {
            "Different strings, first difference before n",
            "HelloWorld",
            "HellpWorld",
            5
        },
        {
            "n = 0, different strings",
            "Hello",
            "World",
            0
        },
        {
            "n greater than string lengths, identical strings",
            "Short",
            "Short",
            10
        },
        {
            "n greater than string lengths, different strings",
            "Short",
            "Shirt",
            10
        },
        {
            "Strings with null bytes, n covers null byte",
            "Null\0Byte",
            "Null\0Test",
            6
        },
        {
            "Strings with null bytes, n does not cover null byte",
            "Null\0Byte",
            "Null\0Test",
            4
        },
        {
            "Strings with special characters, n = 10",
            "Spécial!@#",
            "Spécial!@#",
            10
        },
        {
            "Strings with special characters, different at end",
            "Spécial!@#A",
            "Spécial!@#B",
            10
        },
        {
            "Unicode strings, identical",
            "こんにちは",
            "こんにちは",
            15
        },
        {
            "Unicode strings, different",
            "こんにちは",
            "こんばんは",
            15
        },
        {
            "Numeric strings, s1 < s2",
            "12345",
            "12346",
            5
        },
        {
            "Numeric strings, s1 > s2",
            "12346",
            "12345",
            5
        }
    };

    int num_cases = sizeof(test_cases) / sizeof(test_cases[0]);
    int fail = 0;
    int i = 0;

    while (i < num_cases)
    {
        int libc_result = strncmp(test_cases[i].s1, test_cases[i].s2, test_cases[i].n);
        int ft_result = ft_strncmp(test_cases[i].s1, test_cases[i].s2, test_cases[i].n);

        if ((libc_result == 0 && ft_result != 0) ||
            (libc_result < 0 && ft_result >= 0) ||
            (libc_result > 0 && ft_result <= 0))
        {
            printf(COLOR_RED "Test ft_strncmp FAILED: %s\n" COLOR_RESET, test_cases[i].description);
            printf("\tString 1: \"%s\"\n", test_cases[i].s1);
            printf("\tString 2: \"%s\"\n", test_cases[i].s2);
            printf("\tBytes compared: %zu\n", test_cases[i].n);
            printf("\tExpected result: %d\n", libc_result);
            printf("\tGot result: %d\n\n", ft_result);
            fail = 1;
        }
        else
        {
            printf(COLOR_GREEN "Test ft_strncmp PASSED: %s\n" COLOR_RESET, test_cases[i].description);
        }
        i++;
    }

    return (fail ? 1 : 0);
}
