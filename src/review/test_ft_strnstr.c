#include "../include/tests_libft.h"
#include <stdio.h>
#include <string.h>

#define COLOR_RED "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_RESET "\x1b[0m"

typedef struct s_strnstr_test_case {
    const char *description;
    const char *haystack;
    const char *needle;
    size_t len;
} t_strnstr_test_case;

int test_ft_strnstr(void);

int test_ft_strnstr(void)
{
    t_strnstr_test_case test_cases[] = {
        {
            "Both haystack and needle empty, len = 0",
            "",
            "",
            0
        },
        {
            "Both haystack and needle empty, len = 5",
            "",
            "",
            5
        },
        {
            "Needle empty, haystack non-empty, len = 10",
            "Hello, World!",
            "",
            10
        },
        {
            "Haystack empty, needle non-empty, len = 5",
            "",
            "Test",
            5
        },
        {
            "Needle longer than haystack, len = 10",
            "Short",
            "LongerNeedle",
            10
        },
        {
            "Needle present at the beginning, len sufficient",
            "Start of the string",
            "Start",
            20
        },
        {
            "Needle present at the beginning, len insufficient",
            "Start of the string",
            "Start",
            3
        },
        {
            "Needle present in the middle, len sufficient",
            "Find the needle in the haystack",
            "needle",
            30
        },
        {
            "Needle present in the middle, len insufficient",
            "Find the needle in the haystack",
            "needle",
            10
        },
        {
            "Needle present at the end, len sufficient",
            "This is the end",
            "end",
            15
        },
        {
            "Needle present at the end, len insufficient",
            "This is the end",
            "end",
            10
        },
        {
            "Needle not present, len = 15",
            "No match here",
            "absent",
            15
        },
        {
            "Multiple occurrences of needle, len covers first",
            "Repeat repeat repeat",
            "peat",
            10
        },
        {
            "Multiple occurrences of needle, len covers second",
            "Repeat repeat repeat",
            "peat",
            20
        },
        {
            "n is zero, needle present",
            "Should not find anything",
            "find",
            0
        },
        {
            "n is zero, needle empty",
            "Should not find anything",
            "",
            0
        },
        {
            "n greater than haystack length, needle present",
            "Exact match at the end",
            "end",
            50
        },
        {
            "n greater than haystack length, needle absent",
            "Just some random text",
            "missing",
            50
        },
        {
            "Needle with special characters, present",
            "Special chars !@# in the string",
            "!@#",
            30
        },
        {
            "Needle with special characters, absent",
            "Special chars !@# in the string",
            "$%^",
            30
        },
        {
            "Unicode needle present",
            "Unicode test: こんにちは世界",
            "こんにちは",
            30
        },
        {
            "Unicode needle absent",
            "Unicode test: こんにちは世界",
            "さようなら",
            30
        },
        {
            "Needle with null byte, present before len",
            "String with\0null byte",
            "with",
            15
        },
        {
            "Needle with null byte, absent due to len",
            "String with\0null byte",
            "null",
            10
        }
    };

    int num_cases = sizeof(test_cases) / sizeof(test_cases[0]);
    int fail = 0;
    int i = 0;

    while (i < num_cases)
    {
        const char *libc_result = strnstr(test_cases[i].haystack, test_cases[i].needle, test_cases[i].len);
        const char *ft_result = ft_strnstr(test_cases[i].haystack, test_cases[i].needle, test_cases[i].len);

        if (libc_result == NULL && ft_result == NULL)
        {
            printf(COLOR_GREEN "Test ft_strnstr PASSED: %s\n" COLOR_RESET, test_cases[i].description);
        }
        else if (libc_result != NULL && ft_result != NULL)
        {
            ptrdiff_t libc_offset = libc_result - test_cases[i].haystack;
            ptrdiff_t ft_offset = ft_result - test_cases[i].haystack;

            if (libc_offset == ft_offset)
            {
                printf(COLOR_GREEN "Test ft_strnstr PASSED: %s\n" COLOR_RESET, test_cases[i].description);
            }
            else
            {
                printf(COLOR_RED "Test ft_strnstr FAILED: %s\n" COLOR_RESET, test_cases[i].description);
                printf("\tHaystack: \"%s\"\n", test_cases[i].haystack);
                printf("\tNeedle: \"%s\"\n", test_cases[i].needle);
                printf("\tLength: %zu\n", test_cases[i].len);
                printf("\tExpected position: %td\n", libc_offset);
                printf("\tGot position: %td\n\n", ft_offset);
                fail = 1;
            }
        }
        else
        {
            printf(COLOR_RED "Test ft_strnstr FAILED: %s\n" COLOR_RESET, test_cases[i].description);
            printf("\tHaystack: \"%s\"\n", test_cases[i].haystack);
            printf("\tNeedle: \"%s\"\n", test_cases[i].needle);
            printf("\tLength: %zu\n", test_cases[i].len);
            if (libc_result == NULL)
                printf("\tExpected: NULL\n");
            else
                printf("\tExpected position: %td\n", libc_result - test_cases[i].haystack);
            if (ft_result == NULL)
                printf("\tGot: NULL\n\n");
            else
                printf("\tGot position: %td\n\n", ft_result - test_cases[i].haystack);
            fail = 1;
        }
        i++;
    }

    return (fail ? 1 : 0);
}
