/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_tolower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofarina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 21:01:30 by ofarina           #+#    #+#             */
/*   Updated: 2024/09/24 21:02:07 by ofarina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tests_libft.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

typedef struct s_tolower_test_case {
    const char	*description;
    int			input;
} t_tolower_test_case;

int test_ft_tolower(void)
{
    t_tolower_test_case test_cases[] = {
        {
            "Basic - A",
            'A'
        },
        {
            "Basic - \\n",
            '\n'
        },
		{
            "Basic - 354",
            354
        },
        {
            "Basic - z",
            'z'
        },
		{
            "Non Alpha - Y",
            'Y'
        },
        {
            "Non Alpha - #",
            '#'
        },
		{
			"Null char",
			'\0'
		}
	};
    
    int num_cases = sizeof(test_cases) / sizeof(test_cases[0]);
    int fail = 0;

	int i = 0;
    while(i < num_cases)
    {
		int res_libc = tolower(test_cases[i].input);
		int res_ft = ft_tolower(test_cases[i].input);

        if ((res_libc == 0 && res_ft != 0) || (res_libc != 0 && res_ft == 0))
        {
            printf(COLOR_RED "Test ft_tolower FAILED: %s\n" COLOR_RESET, test_cases[i].description);
            printf("\tInput: \"%c\"\n", test_cases[i].input);
            printf("\tResult libc: \"%i\"\n", res_libc);
            printf("\tResult ft: \"%i\"\n", res_ft);
            printf("\n");
            fail = 1;
        }
        else
        {
            printf(COLOR_GREEN "Test ft_tolower PASSED: %s\n" COLOR_RESET, test_cases[i].description);
        }
		i++;
    }

    return fail ? 1 : 0;
}
