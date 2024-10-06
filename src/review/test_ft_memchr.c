#include "../include/tests_libft.h"
#include <stdio.h>
#include <string.h>

#define COLOR_RED "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_RESET "\x1b[0m"

#define MAX_LEN 100

typedef struct s_memchr_test_case {
    const char *description;
    const char *input;
    int byte;
    size_t n;
} t_memchr_test_case;

int test_ft_memchr(void);

int test_ft_memchr(void)
{
    t_memchr_test_case test_cases[] = {
        {
            "Search for byte present once",
            "Hello, World!",
            'W',
            13
        },
        {
            "Search for byte present multiple times",
            "banana",
            'a',
            6
        },
        {
            "Search for byte not present",
            "Test string",
            'z',
            11
        },
        {
            "Search for null byte in string",
            "Null byte\0Test",
            '\0',
            11
        },
        {
            "Search in empty buffer",
            "",
            'a',
            0
        },
        {
            "Search for first byte",
            "Start",
            'S',
            5
        },
        {
            "Search for last byte",
            "End",
            'd',
            3
        },
        {
            "Search for special character",
            "Special!@#",
            '@',
            9
        },
        {
            "Search for non-printable byte",
            "Non-printable\x01Test",
            '\x01',
            16
        },
        {
            "Search in buffer with multiple null bytes",
            "Multi\0Null\0Bytes",
            'N',
            14
        },
        {
            "Search for byte beyond buffer size",
            "Short",
            'S',
            10
        },
        {
            "Search for byte in buffer with all bytes same",
            "AAAAAA",
            'A',
            6
        },
        {
            "Search for byte not in uniform buffer",
            "AAAAAA",
            'B',
            6
        },
        {
            "Search for byte in buffer with binary data",
            "\x00\x01\x02\x03\x04\x05",
            '\x03',
            6
        },
        {
            "Search for first byte in binary buffer",
            "\xFF\xFE\xFD\xFC",
            '\xFF',
            4
        },
        {
            "Search for last byte in binary buffer",
            "\x10\x20\x30\x40",
            '\x40',
            4
        },
        {
            "Search for byte with n = 0",
            "No search",
            'N',
            0
        },
        {
            "Search for byte in full buffer",
            "CompleteBuffer",
            'B',
            14
        },
        {
            "Search for byte multiple times with early match",
            "aabacadae",
            'a',
            9
        },
        {
            "Search for byte multiple times with late match",
            "abcdefgaa",
            'a',
            9
        },
        {
            "Search for byte in buffer without null terminator",
            "NonNullTerm",
            'T',
            11
        }
    };

    int num_cases = sizeof(test_cases) / sizeof(test_cases[0]);
    int fail = 0;
    int i = 0;

    while (i < num_cases)
    {
        const void *libc_result = memchr(test_cases[i].input, test_cases[i].byte, test_cases[i].n);
        const void *ft_result = ft_memchr(test_cases[i].input, test_cases[i].byte, test_cases[i].n);

        if (libc_result == NULL && ft_result == NULL)
        {
            printf(COLOR_GREEN "Test ft_memchr PASSED: %s\n" COLOR_RESET, test_cases[i].description);
        }
        else if (libc_result != NULL && ft_result != NULL)
        {
            ptrdiff_t libc_offset = (const char*)libc_result - test_cases[i].input;
            ptrdiff_t ft_offset = (const char*)ft_result - test_cases[i].input;

            if (libc_offset == ft_offset)
            {
                printf(COLOR_GREEN "Test ft_memchr PASSED: %s\n" COLOR_RESET, test_cases[i].description);
            }
            else
            {
                printf(COLOR_RED "Test ft_memchr FAILED: %s\n" COLOR_RESET, test_cases[i].description);
                printf("\tInput: \"");
                for (size_t j = 0; j < strlen(test_cases[i].input); j++)
                {
                    if (test_cases[i].input[j] >= 32 && test_cases[i].input[j] <= 126)
                        printf("%c", test_cases[i].input[j]);
                    else
                        printf("\\x%02X", (unsigned char)test_cases[i].input[j]);
                }
                printf("\"\n");
                printf("\tByte to search: 0x%02X ('%c')\n", (unsigned char)test_cases[i].byte, test_cases[i].byte);
                printf("\tBytes to search (n): %zu\n", test_cases[i].n);
                printf("\tExpected offset: %td\n", libc_offset);
                printf("\tGot offset: %td\n\n", ft_offset);
                fail = 1;
            }
        }
        else
        {
            printf(COLOR_RED "Test ft_memchr FAILED: %s\n" COLOR_RESET, test_cases[i].description);
            printf("\tInput: \"");
            for (size_t j = 0; j < strlen(test_cases[i].input); j++)
            {
                if (test_cases[i].input[j] >= 32 && test_cases[i].input[j] <= 126)
                    printf("%c", test_cases[i].input[j]);
                else
                    printf("\\x%02X", (unsigned char)test_cases[i].input[j]);
            }
            printf("\"\n");
            printf("\tByte to search: 0x%02X ('%c')\n", (unsigned char)test_cases[i].byte, test_cases[i].byte);
            printf("\tBytes to search (n): %zu\n", test_cases[i].n);
            if (libc_result == NULL)
                printf("\tExpected: NULL\n");
            else
                printf("\tExpected offset: %td\n", (const char*)libc_result - test_cases[i].input);
            if (ft_result == NULL)
                printf("\tGot: NULL\n\n");
            else
                printf("\tGot offset: %td\n\n", (const char*)ft_result - test_cases[i].input);
            fail = 1;
        }
        i++;
    }

    return (fail ? 1 : 0);
}
