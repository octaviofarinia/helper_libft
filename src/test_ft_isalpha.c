/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofarina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 20:14:46 by ofarina           #+#    #+#             */
/*   Updated: 2024/09/24 20:38:28 by ofarina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/tests_libft.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

typedef struct s_isalpha_test_case {
    const char	*description;
    char		input;
} t_isalpha_test_case;

int test_ft_isalpha(void)
{
    t_isalpha_test_case test_cases[] = {
        {
            "Basic - A",
            'A'
        },
        {
            "Basic - Z",
            'Z'
        },
		{
            "Basic - a",
            'a'
        },
        {
            "Basic - z",
            'z'
        },
		{
            "Non Alpha - 8",
            '8'
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
		int res_libc = isalpha(test_cases[i].input);
		int res_ft = ft_isalpha(test_cases[i].input);

        if ((res_libc == 0 && res_ft != 0) || (res_libc != 0 && res_ft == 0))
        {
            printf(COLOR_RED "Test ft_isalpha FAILED: %s\n" COLOR_RESET, test_cases[i].description);
            printf("\tInput: \"%c\"\n", test_cases[i].input);
            printf("\tResult libc: \"%i\"\n", res_libc);
            printf("\tResult ft: \"%i\"\n", res_ft);
            printf("\n");
            fail = 1;
        }
        else
        {
            printf(COLOR_GREEN "Test ft_isalpha PASSED: %s\n" COLOR_RESET, test_cases[i].description);
        }
		i++;
    }

    return fail ? 1 : 0;
}
