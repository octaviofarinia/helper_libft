#include "../include/tests_libft.h"
#include <stdio.h>
#include <string.h>

#define COLOR_RED "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_RESET "\x1b[0m"

typedef struct s_strrchr_test_case {
    const char *description;
    const char *input;
    int character;
} t_strrchr_test_case;

int test_ft_strrchr(void);

int test_ft_strrchr(void)
{
    t_strrchr_test_case test_cases[] = {
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
        },
        {
            "Search for last occurrence of character",
            "abcabcabc",
            'a'
        },
        {
            "Search for last occurrence of space",
            "Find the last space here ",
            ' '
        },
        {
            "Search for character at the end",
            "Ends with X",
            'X'
        },
        {
            "Search for character at the beginning",
            "Starts with Y",
            'S'
        },
        {
            "Search for multiple special characters",
            "!@#$%^&*()_+",
            '%'
        },
        {
            "Search for digit character",
            "Number12345",
            '3'
        },
        {
            "Search for space in spaces only",
            "     ",
            ' '
        }
    };

    int num_cases = sizeof(test_cases) / sizeof(test_cases[0]);
    int fail = 0;
    int i = 0;

    while (i < num_cases)
    {
        const char *libc_result = strrchr(test_cases[i].input, test_cases[i].character);
        const char *ft_result = ft_strrchr(test_cases[i].input, test_cases[i].character);

        if (libc_result == NULL && ft_result == NULL)
        {
            printf(COLOR_GREEN "Test ft_strrchr PASSED: %s\n" COLOR_RESET, test_cases[i].description);
        }
        else if (libc_result != NULL && ft_result != NULL)
        {
            // Calculate the offset from the start of the string
            ptrdiff_t libc_offset = libc_result - test_cases[i].input;
            ptrdiff_t ft_offset = ft_result - test_cases[i].input;

            if (libc_offset == ft_offset)
            {
                printf(COLOR_GREEN "Test ft_strrchr PASSED: %s\n" COLOR_RESET, test_cases[i].description);
            }
            else
            {
                printf(COLOR_RED "Test ft_strrchr FAILED: %s\n" COLOR_RESET, test_cases[i].description);
                printf("\tInput: \"%s\"\n", test_cases[i].input);
                printf("\tCharacter: '%c'\n", test_cases[i].character);
                printf("\tExpected position: %td\n", libc_offset);
                printf("\tGot position: %td\n\n", ft_offset);
                fail = 1;
            }
        }
        else
        {
            printf(COLOR_RED "Test ft_strrchr FAILED: %s\n" COLOR_RESET, test_cases[i].description);
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
