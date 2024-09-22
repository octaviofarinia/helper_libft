/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofarina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 18:57:25 by ofarina           #+#    #+#             */
/*   Updated: 2024/09/22 15:40:52 by ofarina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_libft.h"
#define MAX_TESTS 42

int main(void)
{
	int num_tests;
	int fail_count;
	int pass_count;
	int i;

	t_test tests[MAX_TESTS] = {
		{"ft_memcpy", test_ft_memcpy},
		{"ft_memmove", test_ft_memmove},
		{"ft_strlcpy", test_ft_strlcpy},
		{"ft_strlcat", test_ft_strlcat},
		{NULL, NULL}
	};

	fail_count = 0;
	pass_count = 0;

	i = 0;
	while (tests[i].test_func != NULL)
	{
		if (tests[i].test_func())
		{
			printf("\nTest %s failed.\n", tests[i].name);
			fail_count++;
		}
		else
		{
			printf("Test %s passed.\n", tests[i].name);
			pass_count++;
		}
		i++;
		printf("--------------------------------------\n");
	}
	num_tests = i;

	printf("\nTest Summary:\n");
	printf("\tTotal Tests: %d\n", num_tests);
	printf("\tPassed: %d\n", pass_count);
	printf("\tFailed: %d\n", fail_count);
	if (fail_count == 0)
		printf("All tests passed successfully.\n");
	else
		printf("Some tests failed. Please review the failed test cases.\n");

	return (fail_count == 0) ? 0 : 1;
}
