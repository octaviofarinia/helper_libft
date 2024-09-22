/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_libft.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofarina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 15:51:44 by ofarina           #+#    #+#             */
/*   Updated: 2024/09/22 15:38:34 by ofarina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_LIBFT_H 
# define TESTS_LIBFT_H
#include <stdio.h>
#include "../libft/libft.h"
#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_RESET   "\x1b[0m"

typedef struct s_test
{
	const char *name;
	int (*test_func)(void);
} t_test;

int test_ft_memcpy(void);
int test_ft_memmove(void);
int test_ft_strlcpy(void);
int test_ft_strlcat(void);

#endif
