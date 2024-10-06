#include "../include/tests_libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define COLOR_RED "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_RESET "\x1b[0m"

typedef struct s_atoi_test_case {
    const char *description;
    const char *input;
    int expected;
} t_atoi_test_case;

int test_ft_atoi(void);

int test_ft_atoi(void)
{
    t_atoi_test_case test_cases[] = {
        {
            "Empty string",
            "",
            0
        },
        {
            "String with only whitespaces",
            "    ",
            0
        },
        {
            "Positive number",
            "12345",
            12345
        },
        {
            "Negative number",
            "-12345",
            -12345
        },
        {
            "Positive number with plus sign",
            "+12345",
            12345
        },
        {
            "Mixed characters after number",
            "42 is the answer",
            42
        },
        {
            "Leading non-digit characters",
            "abc123",
            0
        },
        {
            "Number at maximum int",
            "2147483647",
            INT_MAX
        },
        {
            "Number at minimum int",
            "-2147483648",
            INT_MIN
        },
        {
            "Multiple signs",
            "--123",
            0
        },
        {
            "Leading zeros",
            "0000123",
            123
        },
        {
            "Only plus sign",
            "+",
            0
        },
        {
            "Only minus sign",
            "-",
            0
        },
        {
            "Whitespace and negative number",
            "   -42",
            -42
        },
        {
            "Null byte within string",
            "123\0abc",
            123
        },
        {
            "Only non-digit characters",
            "abc",
            0
        },
        {
            "Number with letters",
            "007JamesBond",
            7
        },
        {
            "Number with decimal point",
            "123.45",
            123
        },
        {
            "Space between sign and number",
            "- 123",
            0
        },
        {
            "Hexadecimal-like prefix",
            "0x1A",
            0
        },
        {
            "Large number exceeding int",
            "9999999999999999999999999",
            INT_MAX
        },
        {
            "Non-printable characters before number",
            "\n\t123",
            123
        },
        {
            "Multiple leading spaces and signs",
            "   +++--123",
            0
        },
        {
            "Plus and minus combination",
            "+-123",
            0
        },
        {
            "Number with trailing spaces",
            "456   ",
            456
        },
        {
            "Number with internal spaces",
            "78 90",
            78
        },
        {
            "Number with tab character",
            "   \t-56",
            -56
        },
        {
            "Number with newline character",
            "89\n10",
            89
        },
        {
            "Long positive number within int range",
            "2147483646",
            2147483646
        },
        {
            "Long negative number within int range",
            "-2147483647",
            -2147483647
        }
    };

    int num_cases = sizeof(test_cases) / sizeof(test_cases[0]);
    int fail = 0;
    int i = 0;

    while (i < num_cases)
    {
        int libc_result = atoi(test_cases[i].input);
        int ft_result = ft_atoi(test_cases[i].input);

        if (libc_result != ft_result)
        {
            printf(COLOR_RED "Test ft_atoi FAILED: %s\n" COLOR_RESET, test_cases[i].description);
            printf("\tInput: \"%s\"\n", test_cases[i].input);
            printf("\tExpected: %d\n", libc_result);
            printf("\tGot: %d\n\n", ft_result);
            fail = 1;
        }
        else
        {
            printf(COLOR_GREEN "Test ft_atoi PASSED: %s\n" COLOR_RESET, test_cases[i].description);
        }
        i++;
    }

    return (fail ? 1 : 0);
}
