#include "../include/tests_libft.h"
#include <stdio.h>
#include <string.h>

#define COLOR_RED "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_RESET "\x1b[0m"

typedef struct s_strchr_test_case {
    const char *description;
    const char *input;
    int character;
} t_strchr_test_case;

int test_ft_strchr(void);

int test_ft_strchr(void)
{
    t_strchr_test_case test_cases[] = {
        {
            "Character present once",
            "Hello, World!",
            'W'
        },
        {
            "Character present multiple times",
            "banana",
            'a'
        },
        {
            "Character not present",
            "Test string",
            'z'
        },
        {
            "Search for null byte",
            "Null byte test",
            '\0'
        },
        {
            "Empty string",
            "",
            'a'
        },
        {
            "Single character string - character present",
            "a",
            'a'
        },
        {
            "Single character string - character absent",
            "b",
            'a'
        },
        {
            "Search for first character",
            "start",
            's'
        },
        {
            "Search for last character",
            "end",
            'd'
        },
        {
            "Search for special character",
            "Special!@#",
            '@'
        },
        {
            "Search for non-printable character",
            "Non-printable\x01Test",
            '\x01'
        },
        {
            "Search in string with multiple null bytes",
            "Multi\0Null\0Bytes",
            'N'
        },
        {
            "Search for uppercase character in lowercase string",
            "lowercase",
            'L'
        }
    };

    int num_cases = sizeof(test_cases) / sizeof(test_cases[0]);
    int fail = 0;
    int i = 0;

    while (i < num_cases)
    {
        const char *libc_result = strchr(test_cases[i].input, test_cases[i].character);
        const char *ft_result = ft_strchr(test_cases[i].input, test_cases[i].character);

        if (libc_result == NULL && ft_result == NULL)
        {
            printf(COLOR_GREEN "Test ft_strchr PASSED: %s\n" COLOR_RESET, test_cases[i].description);
        }
        else if (libc_result != NULL && ft_result != NULL)
        {
            // Calculate the offset from the start of the string
            ptrdiff_t libc_offset = libc_result - test_cases[i].input;
            ptrdiff_t ft_offset = ft_result - test_cases[i].input;

            if (libc_offset == ft_offset)
            {
                printf(COLOR_GREEN "Test ft_strchr PASSED: %s\n" COLOR_RESET, test_cases[i].description);
            }
            else
            {
                printf(COLOR_RED "Test ft_strchr FAILED: %s\n" COLOR_RESET, test_cases[i].description);
                printf("\tInput: \"%s\"\n", test_cases[i].input);
                printf("\tCharacter: '%c'\n", test_cases[i].character);
                printf("\tExpected position: %td\n", libc_offset);
                printf("\tGot position: %td\n\n", ft_offset);
                fail = 1;
            }
        }
        else
        {
            printf(COLOR_RED "Test ft_strchr FAILED: %s\n" COLOR_RESET, test_cases[i].description);
            printf("\tInput: \"%s\"\n", test_cases[i].input);
            printf("\tCharacter: '%c'\n", test_cases[i].character);
            if (libc_result == NULL)
                printf("\tExpected: NULL\n");
            else
                printf("\tExpected position: %td\n", libc_result - test_cases[i].input);
            if (ft_result == NULL)
                printf("\tGot: NULL\n\n");
            else
                printf("\tGot position: %td\n\n", ft_result - test_cases[i].input);
            fail = 1;
        }
        i++;
    }

    return (fail ? 1 : 0);
}
