#include "../include/tests_libft.h"
#include <stdio.h>
#include <string.h>

#define COLOR_RED "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_RESET "\x1b[0m"

typedef struct s_memcmp_test_case {
    const char *description;
    const void *s1;
    const void *s2;
    size_t n;
} t_memcmp_test_case;

int test_ft_memcmp(void);

int test_ft_memcmp(void)
{
    t_memcmp_test_case test_cases[] = {
        {
            "Both buffers empty, n = 0",
            "",
            "",
            0
        },
        {
            "Both buffers empty, n = 5",
            "",
            "",
            5
        },
        {
            "First buffer empty, second non-empty, n = 5",
            "",
            "Non-empty",
            5
        },
        {
            "Second buffer empty, first non-empty, n = 5",
            "Non-empty",
            "",
            5
        },
        {
            "Identical buffers, n = 10",
            "HelloWorld",
            "HelloWorld",
            10
        },
        {
            "Identical buffers, n = 5",
            "HelloWorld",
            "HelloWorld",
            5
        },
        {
            "Different buffers, s1 < s2, n = 5",
            "Apple",
            "Banana",
            5
        },
        {
            "Different buffers, s1 > s2, n = 5",
            "Banana",
            "Apple",
            5
        },
        {
            "Different buffers, first difference after n",
            "HelloWorld",
            "HelloThere",
            5
        },
        {
            "Different buffers, first difference before n",
            "HelloWorld",
            "HellpWorld",
            5
        },
        {
            "n = 0, different buffers",
            "Hello",
            "World",
            0
        },
        {
            "n greater than buffer lengths, identical buffers",
            "Short",
            "Short",
            10
        },
        {
            "n greater than buffer lengths, different buffers",
            "Short",
            "Shirt",
            10
        },
        {
            "Buffers with null bytes, n covers null byte",
            "Null\0Byte",
            "Null\0Test",
            6
        },
        {
            "Buffers with null bytes, n does not cover null byte",
            "Null\0Byte",
            "Null\0Test",
            4
        },
        {
            "Buffers with special characters, n = 10",
            "Spécial!@#",
            "Spécial!@#",
            10
        },
        {
            "Buffers with special characters, different at end",
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
        int libc_result = memcmp(test_cases[i].s1, test_cases[i].s2, test_cases[i].n);
        int ft_result = ft_memcmp(test_cases[i].s1, test_cases[i].s2, test_cases[i].n);

        if ((libc_result == 0 && ft_result != 0) ||
            (libc_result < 0 && ft_result >= 0) ||
            (libc_result > 0 && ft_result <= 0))
        {
            printf(COLOR_RED "Test ft_memcmp FAILED: %s\n" COLOR_RESET, test_cases[i].description);
            printf("\tBuffer 1: \"");
            for (size_t j = 0; j < strlen(test_cases[i].s1) + 1; j++) // +1 to include null terminator
            {
                unsigned char byte = ((unsigned char*)test_cases[i].s1)[j];
                if (byte >= 32 && byte <= 126)
                    printf("%c", byte);
                else
                    printf("\\x%02X", byte);
            }
            printf("\"\n");

            printf("\tBuffer 2: \"");
            for (size_t j = 0; j < strlen(test_cases[i].s2) + 1; j++) // +1 to include null terminator
            {
                unsigned char byte = ((unsigned char*)test_cases[i].s2)[j];
                if (byte >= 32 && byte <= 126)
                    printf("%c", byte);
                else
                    printf("\\x%02X", byte);
            }
            printf("\"\n");

            printf("\tBytes compared (n): %zu\n", test_cases[i].n);
            printf("\tExpected result: %d\n", libc_result);
            printf("\tGot result: %d\n\n", ft_result);
            fail = 1;
        }
        else
        {
            printf(COLOR_GREEN "Test ft_memcmp PASSED: %s\n" COLOR_RESET, test_cases[i].description);
        }
        i++;
    }

    return (fail ? 1 : 0);
}
